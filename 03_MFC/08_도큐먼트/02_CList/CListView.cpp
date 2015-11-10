// CListView.cpp : implementation of the CCListView class
//

#include "stdafx.h"
#include "CList.h"

#include "CListDoc.h"
#include "CListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCListView

IMPLEMENT_DYNCREATE(CCListView, CView)

BEGIN_MESSAGE_MAP(CCListView, CView)
	//{{AFX_MSG_MAP(CCListView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCListView construction/destruction

CCListView::CCListView()
{
	// TODO: add construction code here

}

CCListView::~CCListView()
{
}

BOOL CCListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCListView drawing

void CCListView::OnDraw(CDC* pDC)
{
	CCListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	POSITION pos;
	CRect rect;

	pos = pDoc->list.GetHeadPosition();

	while(pos)
	{
		rect.left = pDoc->list.GetAt(pos).x;
		rect.top = pDoc->list.GetAt(pos).y;
		rect.right = pDoc->list.GetAt(pos).x + 30;
		rect.bottom = pDoc->list.GetAt(pos).y + 30;

		pDC->Rectangle(rect);
		pDoc->list.GetNext(pos);
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CCListView printing

BOOL CCListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCListView diagnostics

#ifdef _DEBUG
void CCListView::AssertValid() const
{
	CView::AssertValid();
}

void CCListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCListDoc* CCListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCListDoc)));
	return (CCListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCListView message handlers

void CCListView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CCListDoc *pDoc = GetDocument();
	
	CRect rect(point.x, point.y, point.x + 30, point.y + 30);

	pDoc->list.AddTail(point);
	InvalidateRect(&rect);

	CView::OnLButtonDown(nFlags, point);
}
