// MultiLookView.cpp : implementation of the CMultiLookView class
//

#include "stdafx.h"
#include "MultiLook.h"

#include "MultiLookDoc.h"
#include "MultiLookView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiLookView

IMPLEMENT_DYNCREATE(CMultiLookView, CFormView)

BEGIN_MESSAGE_MAP(CMultiLookView, CFormView)
	//{{AFX_MSG_MAP(CMultiLookView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiLookView construction/destruction

CMultiLookView::CMultiLookView()
	: CFormView(CMultiLookView::IDD)
{
	//{{AFX_DATA_INIT(CMultiLookView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMultiLookView::~CMultiLookView()
{
}

void CMultiLookView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiLookView)
	//}}AFX_DATA_MAP
}

BOOL CMultiLookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMultiLookView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	// 탭 컨트롤에서 사용할 이미지 설정
	CTabCtrl* pTab = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	CImageList imgList;
	imgList.Create(IDB_TAB, 32, 0, (COLORREF)-1);
	pTab->SetImageList(&imgList);
	imgList.Detach();
	// 탭에 타이틀과 이미지 추가
	pTab->InsertItem(0, "편지", 0);
	pTab->InsertItem(1, "날짜", 1);
	pTab->InsertItem(2, "전화", 2);
	pTab->InsertItem(3, "계획서", 3);	
	pTab->InsertItem(4, "일기장", 4);	
	pTab->InsertItem(5, "메모", 5);	
	// 리치 에디트 컨트롤의 내용 초기화
	InitRichEdit();
}

/////////////////////////////////////////////////////////////////////////////
// CMultiLookView diagnostics

#ifdef _DEBUG
void CMultiLookView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMultiLookView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMultiLookDoc* CMultiLookView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiLookDoc)));
	return (CMultiLookDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiLookView message handlers

void CMultiLookView::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CTabCtrl* pTab = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	CRichEditCtrl* pRich = (CRichEditCtrl*)GetDlgItem(IDC_RICHEDIT1);
	int count = pTab->GetCurSel();  // 선택된 탭의 인덱스
	switch(count)
	{
	case 0:			
		pRich->ShowWindow(SW_SHOW);
		break;
	default:					
		pRich->ShowWindow(SW_HIDE);
		break;
	}
	*pResult = 0;
}

void CMultiLookView::SetHeadFormat(CHARFORMAT& cf)
{
	// 문자 형식 설정
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_COLOR|CFM_FACE|CFM_SIZE|CFM_BOLD|CFM_ITALIC;
	cf.dwEffects = CFE_BOLD|CFM_ITALIC;
	cf.yHeight = 400;
	cf.crTextColor = RGB(255,0,0);
	cf.bCharSet = ANSI_CHARSET;
	cf.bPitchAndFamily = FF_SWISS;
	lstrcpy(cf.szFaceName, "Arial");
}

void CMultiLookView::SetTailFormat(CHARFORMAT& cf, PARAFORMAT& pf)
{
	// 문자 형식 설정
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_COLOR|CFM_FACE|CFM_SIZE|CFM_BOLD|CFM_UNDERLINE;
	cf.dwEffects = CFE_BOLD|CFE_UNDERLINE;
	cf.yHeight = 300;
	cf.crTextColor = RGB(0,0,255);
	cf.bCharSet = ANSI_CHARSET;
	cf.bPitchAndFamily = FF_ROMAN;
	lstrcpy(cf.szFaceName, "Times New Roman");

	// 문단 형식 설정
	pf.cbSize = sizeof(PARAFORMAT);
	pf.dwMask = PFM_ALIGNMENT;
	pf.wAlignment = PFA_RIGHT;
}

void CMultiLookView::InitRichEdit()
{
	// 리치 에디트 컨트롤의 내용 초기화
	CRichEditCtrl* pRich = (CRichEditCtrl*)GetDlgItem(IDC_RICHEDIT1);
	CTime time = CTime::GetCurrentTime();
	CString strDate = time.Format("%Y년 %m월 %d일");
	CString strTime = time.Format("%A %p:%I시%M분%S초");
	CString strText; 
	strText = strDate + "\r\n" + strTime + "\r\n\r\n";
	pRich->SetWindowText(strText);

	CHARFORMAT cf; // 문자 형식 구조체
	PARAFORMAT pf; // 문단 형식 구조체

	SetHeadFormat(cf);
	int nStart = 0;
	int nEnd = strDate.GetLength()+2;
	pRich->SetSel(nStart, nEnd); // 셀 범위 설정
	pRich->SetSelectionCharFormat(cf); // 선택된 셀의 글자 형식 설정

	SetTailFormat(cf, pf);
	nStart = nEnd;
	nEnd += strTime.GetLength()+2;
	pRich->SetSel(nStart, nEnd); // 셀 범위 설정
	pRich->SetSelectionCharFormat(cf); // 선택된 셀의 글자 형식 설정
	pRich->SetParaFormat(pf); // 선택된 셀의 문단 형식 설정
}

