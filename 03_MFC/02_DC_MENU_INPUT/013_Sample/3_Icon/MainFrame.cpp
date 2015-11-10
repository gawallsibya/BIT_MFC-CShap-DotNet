// MainFrame.cpp
#include "MainFrame.h"
#include "resource.h" // 리소스에서 만든 ID 를 사용하기 위해 필요

BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )

ON_WM_CREATE()
ON_WM_SETFOCUS()

ON_WM_SETCURSOR() // 마우스를 움직일때
					// 커서를 변경하기 위해 나온다.

END_MESSAGE_MAP()

/////////////////////////////////////////////
CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}
///////////////////////////////////////////////
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if ( ! CFrameWnd::PreCreateWindow( cs ) )
		return FALSE;

	// icon 을 변경하기위해. 새로운 class 를 만들어 사용한다.
	cs.lpszClass = AfxRegisterWndClass( 0, // class style
					0, // cursor -> View에서 지정.
			(HBRUSH)(COLOR_WINDOW+1), // 배경색 -> View에서 지정
					AfxGetApp()->LoadIcon( IDI_MYICON ));

	return TRUE;
}
//////////////////////////////////////
int CMainFrame::OnCreate( LPCREATESTRUCT lpc)
{
	if ( CFrameWnd::OnCreate(lpc ) == -1 ) 
		return -1;

	// View 만들기.
	m_wndView.CreateEx( 0, 0, 0, AFX_WS_DEFAULT_VIEW, 
		CRect(0,0,0,0), this, AFX_IDW_PANE_FIRST);

	return 0;
}
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// Frame 이 Focus를 가질때 View에게 전달한다.
	m_wndView.SetFocus();
}

// 커서를 변경하기 위해 나오는 메세지.
BOOL CMainFrame::OnSetCursor(CWnd *pWnd, // 커서 아래 있는 윈도우
							 UINT nHit, // hit Test code
							 UINT msg)
{
	if ( nHit == HTCAPTION ) // hit test code -> 현재 커서의 위치
	{
		//SetCursor( AfxGetApp()->LoadCursor(IDC_CURSOR1) );

		// Animation Cursor 사용하기. API 함수.
		HCURSOR h = LoadCursorFromFile("C:\\winnt\\cursors\\banana.ani");
		SetCursor( h );
		return TRUE; // 커서를 바꾼경우.
	}
	// 커서를 바꾸지 않은 경우는 반드시 부모에게 보낸다.
	// 그러면 부모가 default 값으로 바꾸어 준다.
	return CFrameWnd::OnSetCursor(pWnd, nHit, msg );
}










