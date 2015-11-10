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

	// Document�� �ִ� data�� �׸���.
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

		// Document�� �����Ѵ�
		CSampleDoc* pDoc = GetDocument();
		
		Line* pLine = new Line(m_ptFrom, point);

		pDoc->m_list.AddTail( pLine  );

		// Document�� ����� ��� View�� �ٽ� �׷����� �Ѵ�.
		pDoc->UpdateAllViews( this , // �ڽ��� ���� �϶�� �ǹ�
								1,   // hint( ��ӵ� ����)
						(CObject*)pLine);

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


void CSampleView::OnUpdate(CView* pSender,
						   LPARAM lHint, 
						   CObject* pHint) 
{
	if ( lHint == 1) // ���� 1���� �߰��� ����̴�. ��ü�� ��ȿȭ
	{				// �� �ʿ�� ����.
		Line* pLine = (Line*)pHint;
		
		// ȭ���� ��ȿȭ �ϴ� ��� 1������ ���⼭ �׷�����..
		CClientDC dc(this);
		CPen pen( PS_SOLID, 5, RGB(0,0,255));
		CPen* old = dc.SelectObject(&pen);

		dc.MoveTo( pLine->ptFrom);		
		dc.LineTo( pLine->ptTo);		

		dc.SelectObject( old);
		return;
	}
	// �׿ܿ��� ȭ�� ��ü ��ȿȭ
	InvalidateRect(0);
}


