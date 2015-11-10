// ChildView.cpp

#include "ChildView.h"

BEGIN_MESSAGE_MAP(CChildView, CWnd)

ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()

END_MESSAGE_MAP()

//////////////////////////////////////////////////
CChildView::CChildView()
{
}
CChildView::~CChildView()
{
}
/////////////////////////////////////////////////
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if ( ! CWnd::PreCreateWindow( cs ) )
		return FALSE;

	return TRUE;
}
//////////////////////////////////////////////////
// Message Handler
void CChildView::OnLButtonDown( UINT nFlags, CPoint point)
{
	MessageBox("LButton");
}
void CChildView::OnRButtonDown( UINT nFlags, CPoint point)
{
	MessageBox("RButton");
}


