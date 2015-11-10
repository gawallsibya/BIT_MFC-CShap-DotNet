// UseView.cpp : implementation of the CUseView class
//

#include "stdafx.h"
#include "Use.h"

#include "UseDoc.h"
#include "UseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUseView

IMPLEMENT_DYNCREATE(CUseView, CView)

BEGIN_MESSAGE_MAP(CUseView, CView)
	//{{AFX_MSG_MAP(CUseView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUseView construction/destruction

CUseView::CUseView()
{
	// TODO: add construction code here

}

CUseView::~CUseView()
{
}

BOOL CUseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUseView drawing

void CUseView::OnDraw(CDC* pDC)
{
	CUseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CUseView printing

BOOL CUseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CUseView diagnostics

#ifdef _DEBUG
void CUseView::AssertValid() const
{
	CView::AssertValid();
}

void CUseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUseDoc* CUseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseDoc)));
	return (CUseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUseView message handlers

int CUseView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_edit.Create( AFX_WS_DEFAULT_VIEW, CRect(10,10,100,100),
					this, 1);

	return 0;
}
// DLL만들때 생긴, NumEdit.h,  MFCEX.lib, MFCEX.dll을(debug아래) 
// 현재 Directory에 복사해 오세요.