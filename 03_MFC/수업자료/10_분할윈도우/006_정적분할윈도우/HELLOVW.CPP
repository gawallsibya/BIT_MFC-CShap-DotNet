// HelloVw.cpp : implementation of the CHelloView class
//

#include "stdafx.h"
#include "SplitWnd.h"

#include "HelloDoc.h"
#include "HelloVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelloView

IMPLEMENT_DYNCREATE(CHelloView, CView)

BEGIN_MESSAGE_MAP(CHelloView, CView)
	//{{AFX_MSG_MAP(CHelloView)
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelloView construction/destruction

CHelloView::CHelloView()
{
	// TODO: add construction code here

}

CHelloView::~CHelloView()
{
}

BOOL CHelloView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHelloView drawing

void CHelloView::OnDraw(CDC* pDC)
{
	CHelloDoc* pDoc = GetDocument();
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
// CHelloView printing

BOOL CHelloView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHelloView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHelloView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHelloView diagnostics

#ifdef _DEBUG
void CHelloView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloDoc* CHelloView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloDoc)));
	return (CHelloDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHelloView message handlers

void CHelloView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CHelloDoc* pDoc = GetDocument();
	pDoc->SetMax(CPoint(cx, cy));
	pDoc->SetLocation(CPoint(cx/2, cy/2));
	
}

void CHelloView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	GetDocument()->SetLocation(point);
	
	CView::OnLButtonDown(nFlags, point);
}
