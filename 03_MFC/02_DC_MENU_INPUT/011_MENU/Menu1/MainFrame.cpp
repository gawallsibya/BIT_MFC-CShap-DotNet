// MainFrame.cpp
#include "MainFrame.h"
#include "resource.h"

BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )

ON_WM_CREATE()
ON_WM_SETFOCUS()

// 메뉴 메세지를 처리 하기위한 Macro
ON_COMMAND( IDM_FILE_EXIT, OnExit)

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

void CMainFrame::OnExit()
{
	// 자신에게 WM_CLOSE 메세지를 보낸다.
	SendMessage(WM_CLOSE);

}
BOOL CMainFrame::OnCmdMsg( UINT nID, int nCode, 
						   void* pExtra, 
						   AFX_CMDHANDLERINFO* pHandlerInfo )
{
	// 결국 메뉴 메세지는 이 함수를 지난다.
	// 여기서 View의 OnCmdMsg()를 호출해 주면 View가 먼저 처리할
	// 기회를 얻게 된다ㅣ.
	if ( m_wndView.OnCmdMsg( nID, nCode, pExtra, pHandlerInfo ) )
		return TRUE ; // 처리한 경우.

	// view가 처리하지 않은 경우는 원래 대로 하기 위해 부모에게 전달
	return CFrameWnd::OnCmdMsg( nID, nCode, pExtra, pHandlerInfo);

	// 부모는 자신이 처리하고 처리 못한 경우 APP로 전달하다.
}










