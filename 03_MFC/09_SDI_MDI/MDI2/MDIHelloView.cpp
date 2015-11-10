// MDIHelloView.cpp : implementation of the CMDIHelloView class
//

#include "stdafx.h"
#include "MDIHello.h"

#include "MDIHelloDoc.h"
#include "MDIHelloView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloView

IMPLEMENT_DYNCREATE(CMDIHelloView, CView)

BEGIN_MESSAGE_MAP(CMDIHelloView, CView)
	//{{AFX_MSG_MAP(CMDIHelloView)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloView construction/destruction

CMDIHelloView::CMDIHelloView()
{
	// TODO: add construction code here

}

CMDIHelloView::~CMDIHelloView()
{
}

BOOL CMDIHelloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloView drawing

void CMDIHelloView::OnDraw(CDC* pDC)
{
	CMDIHelloDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPoint pt = pDoc->GetLocation();
	COLORREF color = pDoc->GetColor();
	CString strText = pDoc->GetText();

	pDC->SetTextColor(color);
	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOut(pt.x, pt.y, strText);
}

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloView printing

BOOL CMDIHelloView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDIHelloView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDIHelloView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloView diagnostics

#ifdef _DEBUG
void CMDIHelloView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIHelloView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIHelloDoc* CMDIHelloView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIHelloDoc)));
	return (CMDIHelloDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDIHelloView message handlers

void CMDIHelloView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CMDIHelloDoc* pDoc = GetDocument();
	pDoc->SetMax(CPoint(cx, cy));
	pDoc->SetLocation(CPoint(cx/2, cy/2));
}

void CMDIHelloView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	GetDocument()->SetLocation(point);

	CView::OnLButtonDown(nFlags, point);
}
