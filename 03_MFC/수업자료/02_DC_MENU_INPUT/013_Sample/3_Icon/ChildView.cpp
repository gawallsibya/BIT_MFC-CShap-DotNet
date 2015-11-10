// ChildView.cpp

#include "ChildView.h"
#include "resource.h"

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

	// 커서 변경하기.
	cs.lpszClass = AfxRegisterWndClass( 
		CS_HREDRAW | CS_VREDRAW, // size 조절시 화면 전체를 무효화 하느
								// class style.
		AfxGetApp()->LoadCursor( IDC_CURSOR1 ), // 커서.

		(HBRUSH)(COLOR_WINDOW+1), //  흰색 붓의 핸들
		
		0); // icon -> Frame에서 변경.

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


