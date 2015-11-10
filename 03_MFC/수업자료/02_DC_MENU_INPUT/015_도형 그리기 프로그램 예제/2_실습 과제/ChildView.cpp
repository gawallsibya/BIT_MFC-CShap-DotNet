// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "MFC Shape.h"
#include "ChildView.h"
#include "Rectangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_ACTIVATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// list�� ��� ��Ҹ� �ٽ� �׸���.
	POSITION pos = wList.GetHeadPosition();

	while( pos )
	{
		CWidget* p = wList.GetNext( pos );

		p->Draw( &dc );
	}
	
	// Do not call CWnd::OnPaint() for painting messages
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint pt) 
{
	CRectangle* p = new CRectangle( pt.x, pt.y, pt.x+50, pt.y+50 );

	// list�� ����
	wList.AddTail( p );

	// �ڽ��� �׸��� �Ѵ�.
	CClientDC dc(this);
	p->Draw( &dc );	
}

void CChildView::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CWnd ::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}

void CChildView::OnDestroy() 
{
	CWnd ::OnDestroy();

	// list�� �ִ� ��� ��ü�� �ı��Ѵ�.
	POSITION pos = wList.GetHeadPosition();

	while( pos )
	{
		CWidget* p = wList.GetNext( pos );

		delete p;
	}
}
