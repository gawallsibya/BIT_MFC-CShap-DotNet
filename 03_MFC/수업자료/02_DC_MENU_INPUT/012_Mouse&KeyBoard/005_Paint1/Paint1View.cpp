// Paint1View.cpp : implementation of the CPaint1View class
//

#include "stdafx.h"
#include "Paint1.h"

#include "Paint1Doc.h"
#include "Paint1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaint1View

IMPLEMENT_DYNCREATE(CPaint1View, CView)

BEGIN_MESSAGE_MAP(CPaint1View, CView)
	//{{AFX_MSG_MAP(CPaint1View)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_PAINT_DRAW, ID_PAINT_RECTANGLE, OnShape)
	ON_UPDATE_COMMAND_UI_RANGE(ID_PAINT_DRAW, ID_PAINT_RECTANGLE, OnUpdateShape)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaint1View construction/destruction

CPaint1View::CPaint1View()
{
	m_SelectTool = ID_PAINT_DRAW;
}

CPaint1View::~CPaint1View()
{
}

BOOL CPaint1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPaint1View drawing

void CPaint1View::OnDraw(CDC* pDC)
{
	CPaint1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPaint1View printing

BOOL CPaint1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPaint1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPaint1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPaint1View diagnostics

#ifdef _DEBUG
void CPaint1View::AssertValid() const
{
	CView::AssertValid();
}

void CPaint1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaint1Doc* CPaint1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaint1Doc)));
	return (CPaint1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaint1View message handlers

void CPaint1View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	SetCapture();
	m_nowPoint = point;
	m_OldPoint = point;
	CView::OnLButtonDown(nFlags, point);
}

void CPaint1View::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC	dc(this);
	CBrush	*OldBrush;
	OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);
	if(GetCapture() == this)
	{
		if(nFlags & MK_LBUTTON)
		{
			switch(m_SelectTool)
			{
			case ID_PAINT_DRAW:
				dc.MoveTo(m_nowPoint);
				dc.LineTo(point);
				m_nowPoint = point;
				break;
			case ID_PAINT_LINE:
				dc.SetROP2(R2_NOT);
				dc.MoveTo(m_nowPoint);		dc.LineTo(m_OldPoint);
				dc.MoveTo(m_nowPoint);		dc.LineTo(point);
				m_OldPoint = point;
				break;
			case ID_PAINT_ELLIPSE:
				dc.SetROP2(R2_NOT);
				dc.Ellipse(m_nowPoint.x, m_nowPoint.y, m_OldPoint.x, m_OldPoint.y);
				dc.Ellipse(m_nowPoint.x, m_nowPoint.y, point.x, point.y);
				m_OldPoint = point;
				break;
			case ID_PAINT_RECTANGLE:
				dc.SetROP2(R2_NOT);
				dc.Rectangle(m_nowPoint.x, m_nowPoint.y, m_OldPoint.x, m_OldPoint.y);
				dc.Rectangle(m_nowPoint.x, m_nowPoint.y, point.x, point.y);
				m_OldPoint = point;
				break;
			}
			dc.SelectObject(OldBrush);
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CPaint1View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(GetCapture()== this)
		ReleaseCapture();

	CBrush *OldBrush;
	CClientDC dc(this);
	OldBrush = (CBrush*)dc.SelectStockObject(NULL_BRUSH);
	switch(m_SelectTool)
	{
	case ID_PAINT_DRAW:
		dc.MoveTo(m_nowPoint);
		dc.LineTo(point);
		break;
	case ID_PAINT_ELLIPSE:
		dc.Ellipse(m_nowPoint.x, m_nowPoint.y, point.x, point.y);
		break;
	case ID_PAINT_RECTANGLE:
		dc.Rectangle(m_nowPoint.x, m_nowPoint.y, point.x, point.y);
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}

void CPaint1View::OnShape(UINT nID)
{
	m_SelectTool = nID;
}

void CPaint1View::OnUpdateShape(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_SelectTool == (int)pCmdUI->m_nID);
}
