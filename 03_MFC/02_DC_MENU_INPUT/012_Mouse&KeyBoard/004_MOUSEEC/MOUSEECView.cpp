// MOUSEECView.cpp : implementation of the CMOUSEECView class
//

#include "stdafx.h"
#include "MOUSEEC.h"

#include "MOUSEECDoc.h"
#include "MOUSEECView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECView

IMPLEMENT_DYNCREATE(CMOUSEECView, CView)

BEGIN_MESSAGE_MAP(CMOUSEECView, CView)
	//{{AFX_MSG_MAP(CMOUSEECView)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
	ON_MESSAGE (WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECView construction/destruction

CMOUSEECView::CMOUSEECView()
{
	// TODO: add construction code here
	m_bMouseOver	= FALSE;
}

CMOUSEECView::~CMOUSEECView()
{
}

BOOL CMOUSEECView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECView drawing

void CMOUSEECView::OnDraw(CDC* pDC)
{
	CMOUSEECDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECView diagnostics

#ifdef _DEBUG
void CMOUSEECView::AssertValid() const
{
	CView::AssertValid();
}

void CMOUSEECView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMOUSEECDoc* CMOUSEECView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMOUSEECDoc)));
	return (CMOUSEECDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMOUSEECView message handlers
//	#define _WIN32_WINNT 0x0400  : AfxWin.h
void CMOUSEECView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if( !m_bMouseOver)	{
		TRACE(_T("Mouse enter\n"));
	}
	m_bMouseOver	= TRUE;

	TRACKMOUSEEVENT tme;
	 tme.cbSize 	= sizeof(tme);
	 tme.dwFlags	= TME_HOVER | TME_LEAVE;
	 tme.hwndTrack = m_hWnd;
	 tme.dwHoverTime = HOVER_DEFAULT;
	 ::TrackMouseEvent(&tme);
	
	CView::OnMouseMove(nFlags, point);
}

LRESULT CMOUSEECView::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	TRACE(_T("Mouse leave\n"));

	AfxGetMainWnd()->SetWindowText("Mouse leave");
	m_bMouseOver = FALSE;
	return 0;
}
	char temp[50];

LRESULT CMOUSEECView::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	TRACE(_T("Mouse hover( x= %d, y = %d)\n"),

		LOWORD(lParam), HIWORD(lParam));

	wsprintf(temp, "Mouse hover( x= %d, y = %d)",
			LOWORD(lParam), HIWORD(lParam));

	AfxGetMainWnd()->SetWindowText(temp);

	return 0;
}

BOOL CMOUSEECView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	BOOL	bUp = TRUE;
	int nDelta	= zDelta;

	if( zDelta < 0 ) {
		bUp	= FALSE;
		nDelta	= -nDelta;
	}

	UINT nWheelScrollLines;
	::SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &nWheelScrollLines, 0);
	if(nWheelScrollLines == WHEEL_PAGESCROLL)
	{
		SendMessage(WM_VSCROLL, MAKEWPARAM(bUp ? SB_PAGEUP : SB_PAGEDOWN, 0), 0);
	}
	else
	{
		int nLines = (nDelta * nWheelScrollLines) / WHEEL_DELTA;
		while( nLines--)
		{
			SendMessage(WM_VSCROLL, MAKEWPARAM(bUp ? SB_LINEUP : SB_PAGEDOWN, 0), 0);
		}
	}
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
