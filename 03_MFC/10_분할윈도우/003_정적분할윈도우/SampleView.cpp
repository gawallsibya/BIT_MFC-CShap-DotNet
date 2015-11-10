// SampleView.cpp : implementation of the CSampleView class
//

#include "stdafx.h"
#include "Sample.h"

#include "SampleDoc.h"
#include "SampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSampleView

IMPLEMENT_DYNCREATE(CSampleView, CView)

BEGIN_MESSAGE_MAP(CSampleView, CView)
	//{{AFX_MSG_MAP(CSampleView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()


CSampleView::CSampleView()
{
}

CSampleView::~CSampleView()
{
}
BOOL CSampleView::PreCreateWindow(CREATESTRUCT& cs)
{

	return CView::PreCreateWindow(cs);
}
void CSampleView::OnDraw(CDC* pDC)
{
	CSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CPen pen(PS_SOLID, 5, RGB(0,0,255));
	CPen* old = pDC->SelectObject(&pen);

	POSITION pos = pDoc->m_list.GetHeadPosition();
	
	while ( pos )
	{
		Line* p = pDoc->m_list.GetNext( pos );
		
		pDC->MoveTo( p->ptFrom);
		pDC->LineTo( p->ptTo);
	}
	pDC->SelectObject( old );
}
/////////////////////////////////////////////////////////////////////////////
// CSampleView printing

BOOL CSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSampleView diagnostics

#ifdef _DEBUG
void CSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleDoc* CSampleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleDoc)));
	return (CSampleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSampleView message handlers

void CSampleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	m_ptFrom = m_ptOld = point;
	SetCapture();
}
void CSampleView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if ( GetCapture() == this )
	{
		ReleaseCapture();

		CClientDC dc(this);
		CPen pen( PS_SOLID, 5, RGB(0,0,255));
		CPen* old = dc.SelectObject(&pen);

		dc.MoveTo(m_ptFrom);
		dc.LineTo(point);

		dc.SelectObject(old);

		// Document에 저장한다.
		CSampleDoc* pDoc = GetDocument();
		pDoc->m_list.AddTail( new Line(m_ptFrom, point) );

		// 모든 View를 다시 그리게 한다.
		pDoc->UpdateAllViews(this);
	}
}

void CSampleView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if ( GetCapture() == this )
	{
		CClientDC dc(this);
		CPen pen( PS_SOLID, 5, RGB(0,0,255));
		CPen* old = dc.SelectObject(&pen);

		dc.SetROP2( R2_NOTXORPEN );
		dc.MoveTo(m_ptFrom);
		dc.LineTo(m_ptOld);

		dc.MoveTo(m_ptFrom);
		dc.LineTo(point);

		m_ptOld = point;

		dc.SelectObject(old);
	}
}

