// TapeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VideoShop2.h"
#include "TapeDlg.h"
#include "InsTapeDlg.h"
#include "MainFrm.h"
#include "VideoShop2Doc.h"
#include "VideoShop2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTapeDlg dialog


CTapeDlg::CTapeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTapeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTapeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTapeDlg)
	DDX_Control(pDX, IDC_TAPE_LIST, m_listTape);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTapeDlg, CDialog)
	//{{AFX_MSG_MAP(CTapeDlg)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_TAPE_LIST, OnItemchangedTapeList)
	ON_BN_CLICKED(ID_TAPE_DELETE, OnTapeDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTapeDlg message handlers

BOOL CTapeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CVideoShop2View* pView = (CVideoShop2View*)pFrame->GetActiveView();

	// 뷰에서 생성시킨 Tape관련DB 객체의 포인터를 가져옴 
	m_tSet = pView->m_tSet;

	m_listTape.InsertColumn(0, "영화제목", LVCFMT_LEFT, 150, -1);
	m_listTape.InsertColumn(1, "번호", LVCFMT_LEFT, 50, -1);
	m_listTape.InsertColumn(2, "입수일자", LVCFMT_LEFT, 100, -1);
	m_listTape.InsertColumn(3, "감독", LVCFMT_LEFT, 100, -1);
	m_listTape.InsertColumn(4, "주연", LVCFMT_LEFT, 100, -1);
	m_listTape.InsertColumn(5, "대여금액", LVCFMT_RIGHT, 80, -1);

	ViewList();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTapeDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString tmpstr;
	int year, month, day;
	CInsTapeDlg tDlg;
	if(tDlg.DoModal() != IDOK)
		return;
	m_lTapeCD = tDlg.m_lTapeCD;
	m_strTitle = tDlg.m_strTitle;
	
	tmpstr = tDlg.m_tInday.Left(4);
	year = atoi(tmpstr);
	tmpstr = tDlg.m_tInday.Mid(4,2);
	month = atoi(tmpstr);
	tmpstr = tDlg.m_tInday.Right(2);
	day = atoi(tmpstr);
	CTime t(year, month, day, 0, 0, 0);
	m_tInday = t;
	
	m_strDirector = tDlg.m_strDirector;
	m_strActor = tDlg.m_strActor;
	m_lMoney = tDlg.m_lMoney;

	//레코드셋을 연다.
	if(!m_tSet->IsOpen())
		m_tSet->Open();
	//마지막으로 이동한다.
	m_tSet->MoveLast();
	
	//빈레코드를 하나 추가한다.
	m_tSet->AddNew();
	//해당 컬럼에 값을 입력한 후
	ResourceToDB();
	//데이터베이스에 저장한다.
	m_tSet->Update();

	//레코드셋을 닫는다.
	m_tSet->Close();
	//리스트뷰를 다시 작성한다.
	ViewList();
	
	//CDialog::OnOK();
}

void CTapeDlg::ResourceToDB()
{
	UpdateData(TRUE);

	m_tSet->m_TAPE_CD = m_lTapeCD;
	m_tSet->m_TITLE = m_strTitle;
	m_tSet->m_INDAY = m_tInday;
	m_tSet->m_DIRECTOR = m_strDirector;
	m_tSet->m_ACTOR = m_strActor;
	m_tSet->m_MONEY = m_lMoney;
}

void CTapeDlg::DBToResource()
{
	m_lTapeCD = m_tSet->m_TAPE_CD;
	m_strTitle = m_tSet->m_TITLE;
	m_tInday = m_tSet->m_INDAY;
	m_strDirector = m_tSet->m_DIRECTOR;
	m_strActor = m_tSet->m_ACTOR;
	m_lMoney = m_tSet->m_MONEY;
}

void CTapeDlg::ViewList()
{
	LV_ITEM lvitem;
	CString tmpstr;
	int actual;;
	//LV_ITEM 구조체를 채워준다.
	lvitem.mask = LVIF_TEXT;
	lvitem.state = lvitem.stateMask = 0;
	//소트를 하려면 여기에다 포인터값을 넣어주어야 한다.
	lvitem.lParam = 0;

	m_listTape.DeleteAllItems();

	m_tSet->m_strFilter="";

	m_tSet->Open();
	m_tSet->MoveFirst();
	while(!m_tSet->IsEOF())
	{
		DBToResource();
		tmpstr = m_strTitle;
		lvitem.iItem = m_listTape.GetItemCount() + 1;
		lvitem.iSubItem = 0;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		actual = m_listTape.InsertItem(&lvitem);

		tmpstr.Format("%ld", m_lTapeCD);
		lvitem.iItem = actual;
		lvitem.iSubItem = 1;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);

		tmpstr.Format("%d년 %d월 %d일", m_tInday.GetYear(), m_tInday.GetMonth(), m_tInday.GetDay());
		lvitem.iItem = actual;
		lvitem.iSubItem = 2;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);

		tmpstr = m_strDirector;
		lvitem.iItem = actual;
		lvitem.iSubItem = 3;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);

		tmpstr = m_strActor;
		lvitem.iItem = actual;
		lvitem.iSubItem = 4;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);

		tmpstr.Format("%ld", m_lMoney);
		lvitem.iItem = actual;
		lvitem.iSubItem = 5;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);

		m_tSet->MoveNext();
	}
	m_tSet->Close();
}

void CTapeDlg::OnItemchangedTapeList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_nlistIndex = pNMListView->iItem;
	*pResult = 0;
}

void CTapeDlg::OnTapeDelete() 
{
	// TODO: Add your control notification handler code here
	LV_ITEM item;
	int count;

	//현재 선택된 리스트가 없으면 리턴한다.
	if(m_listTape.GetSelectedCount() == 0)
		return;

	//삭제할 것인지 박스를 띄운다.
	if(MessageBox("정말로 지우실 것입니까?",NULL,MB_ICONQUESTION|MB_OKCANCEL) != IDOK)
		return;

	//LV_ITEM 구조체를 세팅한다.
	memset(&item, 0, sizeof(item));
	item.mask = LVIF_STATE;
	item.stateMask = LVIS_SELECTED;

	//루프를 돌면서 선택된 자료를 레코드와 항목에서 지운다.
	for(count= m_listTape.GetItemCount()-1; count >= 0; count--)
	{
		item.iItem = count;
		m_listTape.GetItem(&item);
		if(item.state == LVIS_SELECTED)
		{
			//레코드 지우는 함수 호출
			RecordDelete(m_listTape.GetItemText(m_nlistIndex, 1));
			//현재 item의 항목을 리스트 콘트롤에서 지움.
			m_listTape.DeleteItem(count);
		}
	}
}

void CTapeDlg::RecordDelete(CString delstr)
{
	//레코드셋을 Close한다.
	if(m_tSet->IsOpen())
		m_tSet->Close();

	//1. 지울 레코드를 고르기 위해 SQL 조건문 작성
	m_tSet->m_strFilter = "TAPE_CD = ";
	m_tSet->m_strFilter += delstr;

	//2. 해당 레코드를 Open한다.
	if(!m_tSet->IsOpen())
		m_tSet->Open();

	//3. 레코드를 지운다.
	m_tSet->Delete();
	//다음으로 이동한다.
	m_tSet->MoveNext();

	if(m_tSet->IsEOF())
		m_tSet->MoveLast();
	if(m_tSet->IsBOF())
		m_tSet->SetFieldNull(NULL);

	DBToResource();

	//4. 레코드를 닫는다. 
	m_tSet->Close();

	// 리스트 컨트롤을 갱싱 
	ViewList();
}
