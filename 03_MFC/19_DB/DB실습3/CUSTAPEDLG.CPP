// CusTapeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VideoShop2.h"
#include "CusTapeDlg.h"
#include "MainFrm.h"
#include "VideoShop2Doc.h"
#include "VideoShop2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCusTapeDlg dialog


CCusTapeDlg::CCusTapeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCusTapeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCusTapeDlg)
	m_strName = _T("");
	m_strRecDay = _T("");
	m_strRentDay = _T("");
	m_nTapeCD = 0;
	m_strTitle = _T("");
	m_nCustomCD = 0;
	//}}AFX_DATA_INIT
	m_flagMode = 0;
}


void CCusTapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCusTapeDlg)
	DDX_Control(pDX, IDC_TITLE_LIST, m_listTitle);
	DDX_Text(pDX, IDC_CUSNAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_RECDAY_EDIT, m_strRecDay);
	DDX_Text(pDX, IDC_RENTDAY_EDIT, m_strRentDay);
	DDX_Text(pDX, IDC_TAPECODE_EDIT, m_nTapeCD);
	DDX_Text(pDX, IDC_TAPETTLE_EDIT, m_strTitle);
	DDX_Text(pDX, IDC_CUSCODE_EDIT, m_nCustomCD);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCusTapeDlg, CDialog)
	//{{AFX_MSG_MAP(CCusTapeDlg)
	ON_BN_CLICKED(ID_CUSTAPE_ADD, OnCustapeAdd)
	ON_BN_CLICKED(ID_CUSTAPE_COMPLETE, OnCustapeComplete)
	ON_BN_CLICKED(ID_CUSTAPE_DELETE, OnCustapeDelete)
	ON_BN_CLICKED(ID_CUSTAPE_UPDATE, OnCustapeUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCusTapeDlg message handlers

BOOL CCusTapeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CVideoShop2View* pView = (CVideoShop2View*)pFrame->GetActiveView();

	m_listTitle.InsertColumn(0, "영화제목", LVCFMT_LEFT, 280, -1);
	m_listTitle.InsertColumn(1, "번호", LVCFMT_LEFT, 50, -1);

	m_ctSet = pView->m_ctSet;
	m_tSet = pView->m_tSet;

	m_strName = pView->m_strName;
	m_nCustomCD = pView->m_lCode;

	UpdateData(FALSE);
	TapeList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//검색버튼을 눌렀을 경우
void CCusTapeDlg::OnOK() 
{
	// TODO: Add extra validation here
	//현재 모드가 추가버튼을 누르고 있는 지 검사한다.
	if(m_flagMode == 2)
	{
		MessageBox("현재 추가 모드입니다. 완료를 누르고 실행하십시오.");
		return;
	}
	//리소스의 내용을 멤버변수로 옮긴다.
	UpdateData(TRUE);
	//검색을 위한 SQL 질의문 편집
	m_ctSet->m_strFilter.Format("CUSTOM_CD = %ld AND ISREC = FALSE", m_nCustomCD);
	m_ctSet->Open();
	//검색된 레코드가 없을 경우 처리
	if(m_ctSet->GetRecordCount() == 0)
	{
		MessageBox("대여중인 테잎이 없습니다.");
		m_ctSet->Close();
		m_flagMode = 0;
		return;
	}

	//Resource를 다시 편집
	DBToResource();

	m_ctSet->Close();
	//해당하는 tape의 제목을 구한다.
	m_tSet->m_strFilter.Format("TAPE_CD = %ld", m_nTapeCD);
	m_tSet->Open();
	m_strTitle = m_tSet->m_TITLE;
	m_tSet->Close();
	UpdateData(FALSE);
	m_flagMode = 0;
	//CDialog::OnOK();
}

//추가버튼을 눌렀을 경우
void CCusTapeDlg::OnCustapeAdd() 
{
	// TODO: Add your control notification handler code here
	m_flagMode = 2;
	//리소스의 데이터를 모두 Clear 시킨다.
	m_strRentDay = "";
	m_strRecDay = "";
	m_nTapeCD = 0;
	m_strTitle = "";
	UpdateData(FALSE);
}

//삭제버튼을 눌렀을 경우
void CCusTapeDlg::OnCustapeDelete() 
{
	// TODO: Add your control notification handler code here
	if(m_flagMode == 2)
	{
		MessageBox("현재 추가 모드입니다. 완료를 누르고 실행하십시오.");
		return;
	}
	//현재 설정된 고객-테이프 관련 테이프에서 현재 레코드 삭제
	UpdateData(TRUE);
	m_ctSet->m_strFilter.Format("CUSTOM_CD = %ld AND TAPE_CD = %ld AND ISREC = TRUE",m_nCustomCD, m_nTapeCD);
	m_ctSet->Open();
	if(m_ctSet->GetRecordCount() == 0)
	{
		MessageBox("삭제할 레코드가 없습니다.");
		m_ctSet->Close();
		m_flagMode = 0;
		return;
	}
	m_ctSet->Delete();
	m_ctSet->MoveNext();
	if(m_ctSet->IsEOF())
		m_ctSet->MoveLast();
	if(m_ctSet->IsBOF())
		m_ctSet->SetFieldNull(NULL);
	m_ctSet->Close();
	//리소스를 Clear
	m_strRentDay = "";
	m_strRecDay = "";
	m_nTapeCD = 0;
	m_strTitle = "";
	UpdateData(FALSE);
	m_flagMode = 0;
}

//수정버튼을 눌렀을 경우
void CCusTapeDlg::OnCustapeUpdate() 
{
	// TODO: Add your control notification handler code here
	//현재 추가모드인지를 검색한다.
	if(m_flagMode == 2)
	{
		MessageBox("현재 추가 모드입니다. 완료를 누르고 실행하십시오.");
		return;
	}
	//리소스의 데이터를 멤버변수에 옮긴다.
	UpdateData(TRUE);
	//수정한 데이터가 반납 대기중인지 검색한다.
	m_ctSet->m_strFilter.Format("CUSTOM_CD = %ld AND TAPE_CD = %ld AND ISREC = FALSE", m_nCustomCD, m_nTapeCD);
	//DB을 Open 한다.
	m_ctSet->Open();
	//반납 대기중인 자료가 이니면 다음 루틴을 수행한다.
	if(m_ctSet->GetRecordCount() == 0)
	{
		MessageBox("해당하는 영화는 대여중인 테잎이 아닙니다.");
		m_ctSet->Close();
		m_flagMode = 0;
		return;
	}
	//반납대기중이었으면 레코드를 수정한다.
	m_ctSet->Edit();
	ResourceToDB();
	m_ctSet->Update();

	//DB의 자료를 리소스로 옮긴다.
	DBToResource();
	//DB를 닫는다.
	m_ctSet->Close();
	
	m_flagMode = 0;
}

//완료버튼을 눌렀을 경우
void CCusTapeDlg::OnCustapeComplete() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	switch (m_flagMode)
	{
	//추가
	case 2:
		if(m_strRentDay == "" || m_nTapeCD == 0)
		{
			MessageBox("항목에 입력을 하셔야 합니다.");
			return;
		}
		if(m_ctSet->IsOpen())
			m_ctSet->Close();
		//전체 레코드를 얻기위해 SQL을 Null로 질의한다.
		m_ctSet->m_strFilter = "";
		m_ctSet->Open();
		//레코드를 끝으로 이동시킨다.
		m_ctSet->MoveLast();
		//추가한다.
		m_ctSet->AddNew();
		ResourceToDB();
		m_ctSet->Update();
		m_ctSet->Close();
		m_flagMode = 0;
		break;
	default:
		MessageBox("추가 버튼을 누르고 실행하세요.");
		break;
	}
}

//종료 버튼을 눌렀을 경우
void CCusTapeDlg::OnCancel() 
{
	// TODO: Add extra cleanup here

	CDialog::OnCancel();
}

void CCusTapeDlg::TapeList()
{
	LV_ITEM lvitem;
	int actual;
	CString tmpstr;
	m_tSet->m_strFilter = "";

	//LV_ITEM 구조체를 채워준다.
	lvitem.mask = LVIF_TEXT;
	lvitem.state = lvitem.stateMask = 0;
	//소트를 하려면 여기에다 포인터값을 넣어주어야 한다.
	lvitem.lParam = 0;

	m_listTitle.DeleteAllItems();

	m_tSet->m_strFilter = "";

	m_tSet->Open();
	while(!m_tSet->IsEOF())
	{
		tmpstr = m_tSet->m_TITLE;
		lvitem.iItem = m_listTitle.GetItemCount() + 1;
		lvitem.iSubItem = 0;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		actual = m_listTitle.InsertItem(&lvitem);

		tmpstr.Format("%ld", m_tSet->m_TAPE_CD);
		lvitem.iItem = actual;
		lvitem.iSubItem = 1;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTitle.SetItem(&lvitem);

		m_tSet->MoveNext();
	}

	m_tSet->Close();
}

void CCusTapeDlg::ResourceToDB()
{
	UpdateData(TRUE);
	int year, month, day;
	m_ctSet->m_TAPE_CD = m_nTapeCD;
	m_ctSet->m_CUSTOM_CD = m_nCustomCD;

	year = atoi(m_strRentDay.Left(4));
	month = atoi(m_strRentDay.Mid(4,2));
	day = atoi(m_strRentDay.Right(2));
	CTime t(year, month, day, 0, 0, 0);
	m_ctSet->m_RENT_DAY = t;

	if(m_strRecDay == "")
	{
		m_ctSet->m_REC_DAY = 0;
		m_ctSet->m_ISREC = FALSE;
	}
	else
	{
		year = atoi(m_strRecDay.Left(4));
		month = atoi(m_strRecDay.Mid(4,2));
		day = atoi(m_strRecDay.Right(2));
		CTime s(year, month, day, 0, 0, 0);
		m_ctSet->m_REC_DAY = s;
		m_ctSet->m_ISREC = TRUE;
	}
}

void CCusTapeDlg::DBToResource()
{
	m_nTapeCD = m_ctSet->m_TAPE_CD;
	m_nCustomCD = m_ctSet->m_CUSTOM_CD;
	CTime t;
	t = m_ctSet->m_RENT_DAY;
	m_strRentDay.Format("%d년 %d월 %d일",t.GetYear(),t.GetMonth(),t.GetDay());

	CTime s;
	s = m_ctSet->m_REC_DAY;

	if(s.GetYear() == 1970 && s.GetMonth() == 1 && s.GetDay() == 1)
		m_strRecDay = "대여중";
	else
		m_strRecDay.Format("%d년 %d월 %d일",s.GetYear(),s.GetMonth(),s.GetDay());
	m_bReceive = m_ctSet->m_ISREC;

	UpdateData(FALSE);
}
