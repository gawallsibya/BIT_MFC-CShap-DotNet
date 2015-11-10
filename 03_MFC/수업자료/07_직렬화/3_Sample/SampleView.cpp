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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSampleView construction/destruction

CSampleView::CSampleView()
{
	// TODO: add construction code here

}

CSampleView::~CSampleView()
{
}

BOOL CSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSampleView drawing

void CSampleView::OnDraw(CDC* pDC)
{
	CSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Document�� buf�� ������ �׸���.
	for ( int i = 0 ; i < pDoc->buf.GetSize(); i++)
		pDC->Rectangle( pDoc->buf[i] );

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
	CClientDC dc(this);
	CRect r( point.x, point.y, point.x+50, point.y+50);
	dc.Rectangle(r);

	// Document�� buf�� �����Ѵ�.
	CSampleDoc* pDoc  = GetDocument();
	pDoc->buf.Add(r); 

	// Document class �� ������� ���� data�� ������ MFC�� �˸���.
	pDoc->SetModifiedFlag( TRUE ); // �ݵ�� �ܿ켼��...

	// View�� ������ �������� �ٸ� View�� Update �Ǿ� �� �Ѵ�.
	pDoc->UpdateAllViews( this );
}











