// MainFrame.cpp
#include "MainFrame.h"

BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )

ON_WM_CREATE()
ON_WM_SETFOCUS()

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

	// View �����.
	m_wndView.CreateEx( 0, 0, 0, AFX_WS_DEFAULT_VIEW, 
		CRect(0,0,0,0), this, AFX_IDW_PANE_FIRST);

	return 0;
}
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// Frame �� Focus�� ������ View���� �����Ѵ�.
	m_wndView.SetFocus();
}

