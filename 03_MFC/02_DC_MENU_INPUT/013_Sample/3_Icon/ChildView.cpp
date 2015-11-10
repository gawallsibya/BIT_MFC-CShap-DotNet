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

	// Ŀ�� �����ϱ�.
	cs.lpszClass = AfxRegisterWndClass( 
		CS_HREDRAW | CS_VREDRAW, // size ������ ȭ�� ��ü�� ��ȿȭ �ϴ�
								// class style.
		AfxGetApp()->LoadCursor( IDC_CURSOR1 ), // Ŀ��.

		(HBRUSH)(COLOR_WINDOW+1), //  ��� ���� �ڵ�
		
		0); // icon -> Frame���� ����.

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


