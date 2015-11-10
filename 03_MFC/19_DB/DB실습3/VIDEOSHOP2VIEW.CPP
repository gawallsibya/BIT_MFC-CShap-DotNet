// VideoShop2View.cpp : implementation of the CVideoShop2View class
//

#include "stdafx.h"
#include "VideoShop2.h"

#include "TapeSet.h"
#include "CusTapeSet.h"
#include "VideoShop2Set.h"
#include "VideoShop2Doc.h"
#include "VideoShop2View.h"
#include "CusTapeDlg.h"
#include "TapeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2View

IMPLEMENT_DYNCREATE(CVideoShop2View, CRecordView)

BEGIN_MESSAGE_MAP(CVideoShop2View, CRecordView)
	//{{AFX_MSG_MAP(CVideoShop2View)
	ON_WM_DESTROY()
	ON_COMMAND(ID_RECORD_CUSTOM, OnRecordCustom)
	ON_COMMAND(ID_RECORD_TAPE, OnRecordTape)
	ON_COMMAND(ID_CUSTAPE_ADD, OnCustapeAdd)
	ON_BN_CLICKED(IDC_ADD_BTN, OnAddBtn)
	ON_UPDATE_COMMAND_UI(ID_CUSTAPE_ADD, OnUpdateCustapeAdd)
	ON_BN_CLICKED(IDC_ADDCANCEL_BTN, OnAddcancelBtn)
	ON_COMMAND(ID_RECORD_FIRST, OnRecordFirst)
	ON_UPDATE_COMMAND_UI(ID_RECORD_FIRST, OnUpdateRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, OnRecordLast)
	ON_UPDATE_COMMAND_UI(ID_RECORD_LAST, OnUpdateRecordLast)
	ON_COMMAND(ID_RECORD_NEXT, OnRecordNext)
	ON_UPDATE_COMMAND_UI(ID_RECORD_NEXT, OnUpdateRecordNext)
	ON_COMMAND(ID_RECORD_PREV, OnRecordPrev)
	ON_UPDATE_COMMAND_UI(ID_RECORD_PREV, OnUpdateRecordPrev)
	ON_BN_CLICKED(IDC_DELETE_BTN, OnDeleteBtn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2View construction/destruction

CVideoShop2View::CVideoShop2View()
	: CRecordView(CVideoShop2View::IDD)
{
	//{{AFX_DATA_INIT(CVideoShop2View)
	m_pSet = NULL;
	m_strAddress = _T("");
	m_strName = _T("");
	m_strTel = _T("");
	m_lCode = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_flagAdd = FALSE;
	m_flagFirst = TRUE;
	m_flagLast = FALSE;
}

CVideoShop2View::~CVideoShop2View()
{
}

void CVideoShop2View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideoShop2View)
	DDX_Control(pDX, IDC_TAPE_LIST, m_listTape);
	DDX_Text(pDX, IDC_ADDRESS_EDIT, m_strAddress);
	DDX_Text(pDX, IDC_NAME_EDIT, m_strName);
	DDX_Text(pDX, IDC_TEL_EDIT, m_strTel);
	DDX_Text(pDX, IDC_CODE_EDIT, m_lCode);
	//}}AFX_DATA_MAP
}

BOOL CVideoShop2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CVideoShop2View::OnInitialUpdate()
{
	 
	m_pSet = GetDocument()->m_videoShop2Set;

	// 추가한 두 개의 레코드 셋에 대해 동적으로 메모리 할당 
	m_ctSet = new CCusTapeSet(&GetDocument()->m_DB);
	m_tSet = new CTapeSet(&GetDocument()->m_DB);

	CRecordView::OnInitialUpdate();
	
	// DB의 데이터를 리소스(컨트롤)에 출력 
	DBToResource();
	
	// 리스트 컨트롤에 컬럼 추가 
	m_listTape.InsertColumn(0, "영화제목", LVCFMT_LEFT, 250, -1);
	m_listTape.InsertColumn(1, "빌린날짜", LVCFMT_LEFT, 150, -1);
	m_listTape.InsertColumn(2, "회수날짜", LVCFMT_LEFT, 150, -1);
	m_listTape.InsertColumn(3, "구분", LVCFMT_LEFT, 100, -1);

	UpdateList();
}

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2View printing

BOOL CVideoShop2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVideoShop2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVideoShop2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2View diagnostics

#ifdef _DEBUG
void CVideoShop2View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CVideoShop2View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CVideoShop2Doc* CVideoShop2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVideoShop2Doc)));
	return (CVideoShop2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVideoShop2View database support
CRecordset* CVideoShop2View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CVideoShop2View message handlers

void CVideoShop2View::OnDestroy() 
{
	CRecordView::OnDestroy();
	
	// TODO: Add your message handler code here
	if(m_pSet->IsOpen())
		m_pSet->Close();
}


void CVideoShop2View::OnAddBtn() 
{
	// TODO: Add your control notification handler code here
	if(!m_flagAdd)
		return;

	// 컨트롤에 입력된 정보를 맴버 변수로 전달 
	UpdateData(TRUE);

	// 마지막 레코드로 이동
	m_pSet->MoveLast();

	// 레코드를 추가한다.
	m_pSet->AddNew();

	// 레코드에 리소스 변수(컨트롤에 입력된 값)을 설정 
	ResourceToDB();

	// 추가된 레코드를 데이터베이스에 저장 
	m_pSet->Update();

	// 리스트 컨트롤 갱신 
	UpdateList();
	m_flagAdd = FALSE;
	m_flagFirst = FALSE;
	m_flagLast = TRUE;

}

//리소스에서 DB변수로 이동시키는 함수
void CVideoShop2View::ResourceToDB()
{
	//리소스를 초기호 시킨다.
	UpdateData(TRUE);

	//데이터베이스 컬럼변수에 넣는다.
	m_pSet->m_CUSTOM_CD		= m_lCode;
	m_pSet->m_NAME			= m_strName;
	m_pSet->m_ADDRESS		= m_strAddress;
	m_pSet->m_TEL			= m_strTel;
}

//DB에서 리소스로 이동시키는 함수
void CVideoShop2View::DBToResource()
{
	//데이터베이스 컬럼변수의 값을 리소스 변수에 넣는다.
	m_lCode = m_pSet->m_CUSTOM_CD;
	m_strName = m_pSet->m_NAME;
	m_strAddress = m_pSet->m_ADDRESS;
	m_strTel = m_pSet->m_TEL;
	//화면을 다시 갱신한다.
	UpdateData(FALSE);
}

void CVideoShop2View::OnRecordCustom() 
{
	// TODO: Add your command handler code here
	CCusTapeDlg tDlg;
	tDlg.DoModal();
	UpdateList();
}

void CVideoShop2View::OnRecordTape() 
{
	// TODO: Add your command handler code here
	CTapeDlg tDlg;
	tDlg.DoModal();
//	if( tDlg.DoModal() == IDOK )
//		UpdateList();
}

//리스트 컨트롤을 갱신
void CVideoShop2View::UpdateList()
{
	LV_ITEM lvitem;
	int actual;
	CString tmpstr;
	//CUSTOM 테이블에서 CUSTOM_TAPE 테이블의 데이터를 구하기 위한 SQL 조건문
	m_ctSet->m_strFilter.Format("CUSTOM_CD = %ld", m_pSet->m_CUSTOM_CD);

	//LV_ITEM 구조체를 채워준다.
	lvitem.mask = LVIF_TEXT;
	lvitem.state = lvitem.stateMask = 0;
	//소트를 하려면 여기에다 포인터값을 넣어주어야 한다.
	lvitem.lParam = 0;

	//리스트 컨트롤의 데이터를 모두 지운다.
	m_listTape.DeleteAllItems();

	//조건에 따라 CUSTOM_TAPE 테이블을 오픈한다.
	m_ctSet->Open();
	while(!m_ctSet->IsEOF())
	{
		//영하제목을 구하기 위해 다시 Tape 테이블에 SQL 조건 지정
		m_tSet->m_strFilter.Format("TAPE_CD = %ld", m_ctSet->m_TAPE_CD);
		m_tSet->Open();
		tmpstr = m_tSet->m_TITLE;
		lvitem.iItem = m_listTape.GetItemCount() + 1;
		lvitem.iSubItem = 0;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		actual = m_listTape.InsertItem(&lvitem);


		tmpstr.Format("%d년 %d월 %d일",m_ctSet->m_RENT_DAY.GetYear(),m_ctSet->m_RENT_DAY.GetMonth(), m_ctSet->m_RENT_DAY.GetDay());
		lvitem.iItem = actual;
		lvitem.iSubItem = 1;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);


		if(!m_ctSet->m_ISREC)
			tmpstr = "";
		else
			tmpstr.Format("%d년 %d월 %d일",m_ctSet->m_REC_DAY.GetYear(),m_ctSet->m_REC_DAY.GetMonth(), m_ctSet->m_REC_DAY.GetDay());
		lvitem.iItem = actual;
		lvitem.iSubItem = 2;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);

		//m_ISREC이 FALSE일 경우 대여중
		if(m_ctSet->m_ISREC)
			tmpstr = "회수";
		else
			tmpstr = "대여중";
		lvitem.iItem = actual;
		lvitem.iSubItem = 3;
		lvitem.pszText = tmpstr.GetBuffer(tmpstr.GetLength());
		lvitem.cchTextMax = tmpstr.GetLength() + 1;
		m_listTape.SetItem(&lvitem);

		//Tape 테이블을 닫는다.
		m_tSet->Close();
		//CUSTOM_TAPE 테이블에서 다음 레코드로 이동
		m_ctSet->MoveNext();
	}

	//CUSTOM_TAPE 테이블을 닫는다.
	m_ctSet->Close();
}

void CVideoShop2View::OnCustapeAdd() 
{
	// 마지막 레코드로 이동
	m_pSet->MoveLast();

	// DB의 자료를 리소스(컨트롤)에 출력
	DBToResource();

	// m_lCode를 설정하고 나머지 변수를 널값으로 채운다.
	m_lCode = m_lCode + 1;
	m_strAddress = "";
	m_strName = "";
	m_strTel = "";

	// 리스트 컨트롤의 모든 데이터를 지운다.
	m_listTape.DeleteAllItems();

	UpdateData(FALSE);
	m_flagAdd = TRUE;
}

void CVideoShop2View::OnUpdateCustapeAdd(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_flagAdd);
}




void CVideoShop2View::OnAddcancelBtn() 
{
	// TODO: Add your control notification handler code here
	if(!m_flagAdd)
		return;
	m_pSet->MoveLast();
	DBToResource();
	UpdateList();
	m_flagAdd = FALSE;
	m_flagFirst = FALSE;
	m_flagLast = TRUE;
}

//레코드 이동에 관련한 사용자 정의 함수
BOOL CVideoShop2View::OnMove(UINT nIDMove) 
{
	// TODO: Add your specialized code here and/or call the base class
	switch (nIDMove)
	{
	case ID_RECORD_PREV:
		if(m_pSet->IsBOF())
			break;
		m_pSet->MovePrev();
		break;
	case ID_RECORD_FIRST:
		m_pSet->MoveFirst();
		break;
	case ID_RECORD_NEXT:
		if(m_pSet->IsEOF())
			break;
		m_pSet->MoveNext();
		break;
	case ID_RECORD_LAST:
		m_pSet->MoveLast();
		break;
	default:
		//에러 ID가 들어왔을 경우 처리하는 로직
		ASSERT(FALSE);
		break;
	}
	UpdateList();
	DBToResource();
	return TRUE;
}

void CVideoShop2View::OnRecordFirst() 
{
	// TODO: Add your command handler code here
	if(m_pSet->IsBOF())
	{
		m_flagFirst = TRUE;
		return;
	}
	OnMove(ID_RECORD_FIRST);
	m_flagLast = FALSE;
}

void CVideoShop2View::OnUpdateRecordFirst(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_flagFirst && !m_flagAdd);
}

void CVideoShop2View::OnRecordLast() 
{
	// TODO: Add your command handler code here
	if(m_pSet->IsEOF())
	{
		//레코드의 처음이면 처음으로 이동시키는 버튼을 비활성화
		m_flagLast = TRUE;
		return;
	}
	//OnMove함수 호출
	OnMove(ID_RECORD_LAST);
	//레코드 처음으로 이동했기 때문에 마지막이동버튼을 활성화
	m_flagFirst = FALSE;
}

void CVideoShop2View::OnUpdateRecordLast(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_flagLast && !m_flagAdd);
}

void CVideoShop2View::OnRecordNext() 
{
	// TODO: Add your command handler code here
	if(m_pSet->IsEOF())
	{
		m_flagLast = TRUE;
		return;
	}
	OnMove(ID_RECORD_NEXT);
	m_flagFirst = FALSE;
}

void CVideoShop2View::OnUpdateRecordNext(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_flagLast && !m_flagAdd);
}

void CVideoShop2View::OnRecordPrev() 
{
	// TODO: Add your command handler code here
	if(m_pSet->IsBOF())
	{
		m_flagFirst = TRUE;
		return;
	}
	OnMove(ID_RECORD_PREV);
	m_flagLast = FALSE;
}

void CVideoShop2View::OnUpdateRecordPrev(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!m_flagFirst && !m_flagAdd);
}

void CVideoShop2View::OnDeleteBtn() 
{
	// TODO: Add your control notification handler code here
	//현재 추가모드인지 검색하여 해당사항이 없는지 확인한다.
	if(m_flagAdd)
		return;
	//현재 레코드를 삭제한다.
	m_pSet->Delete();
	//다음레코드로 이동한다.
	m_pSet->MoveNext();
	//레코드가 마지막이면
	if(m_pSet->IsEOF())
		m_pSet->MoveLast(); //마지막으로 이동시킨다.
	//레코드가 처음이면
	if(m_pSet->IsBOF())
		m_pSet->SetFieldNull(NULL); //널로 채운다.
	//현재 커서의 DB자료를 리소스로 옮긴다.
	DBToResource();
	//리스트 컨트롤을 초기화시킨다.
	UpdateList();
}
