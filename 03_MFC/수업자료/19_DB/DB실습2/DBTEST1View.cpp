// DBTEST1View.cpp : implementation of the CDBTEST1View class
//

#include "stdafx.h"
#include "DBTEST1.h"

#include "DBTEST1Set.h"
#include "DBTEST1Doc.h"
#include "DBTEST1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1View

IMPLEMENT_DYNCREATE(CDBTEST1View, CRecordView)

BEGIN_MESSAGE_MAP(CDBTEST1View, CRecordView)
	//{{AFX_MSG_MAP(CDBTEST1View)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, OnBtnDel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1View construction/destruction

CDBTEST1View::CDBTEST1View()
	: CRecordView(CDBTEST1View::IDD)
{
	//{{AFX_DATA_INIT(CDBTEST1View)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CDBTEST1View::~CDBTEST1View()
{
}

void CDBTEST1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDBTEST1View)
	DDX_FieldText(pDX, IDC_EDIT_ADDRESS, m_pSet->m_CUSTOM_CD, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_NAME, m_pSet->m_NAME, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT_PHONE, m_pSet->m_TEL, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CDBTEST1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CDBTEST1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_dBTEST1Set;
	if(m_pSet->IsOpen())
		m_pSet->Close();

	m_pSet->Open();

	CRecordView::OnInitialUpdate();


}

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1View printing

BOOL CDBTEST1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDBTEST1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDBTEST1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1View diagnostics

#ifdef _DEBUG
void CDBTEST1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDBTEST1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDBTEST1Doc* CDBTEST1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBTEST1Doc)));
	return (CDBTEST1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBTEST1View database support
CRecordset* CDBTEST1View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CDBTEST1View message handlers

BOOL CDBTEST1View::OnMove(UINT nIDMoveCommand)
{
	switch (nIDMoveCommand)
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
		ASSERT(FALSE);
		break;
	}
	UpdateData(FALSE);

	return TRUE;
}

void CDBTEST1View::OnDestroy() 
{
	CRecordView::OnDestroy();
	
	if(m_pSet->IsOpen())
		m_pSet->Close();	
}

void CDBTEST1View::OnBtnAdd() 
{
	// 마지막 레코드로 이동
	m_pSet->MoveLast();

	// 레코드를 추가한다.
	m_pSet->AddNew();

	// 레코드에 리소스 변수(컨트롤에 입력된 값)을 설정 
	m_pSet->m_CUSTOM_CD		= m_pSet->m_CUSTOM_CD + 1;
	m_pSet->m_NAME			= "이름 추가";
	m_pSet->m_ADDRESS		= "주소 추가";
	m_pSet->m_TEL			= "전번 추가";

	// 추가된 레코드를 데이터베이스에 저장 
	m_pSet->Update();
}

void CDBTEST1View::OnBtnDel() 
{
	//현재 레코드를 삭제한다.
	m_pSet->Delete();

	//다음레코드로 이동한다.
	m_pSet->MoveNext();
	//레코드가 마지막이면

	if(m_pSet->IsEOF())
		m_pSet->MoveLast(); //마지막으로 이동시킨다.
	//레코드가 처음이면
	if(m_pSet->IsBOF())
		m_pSet->SetFieldNull(NULL); //널로 채운다
	
	//현재 커서의 DB자료를 리소스로 옮긴다.
	//화면을 다시 갱신한다.
	UpdateData(FALSE);
}
