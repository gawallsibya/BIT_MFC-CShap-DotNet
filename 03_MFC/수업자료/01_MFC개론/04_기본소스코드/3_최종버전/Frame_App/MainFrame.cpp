// MainFrame.cpp
#include "MainFrame.h"

BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )

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

