// App.cpp
#include "App.h"
#include "MainFrame.h"

BEGIN_MESSAGE_MAP( CMyApp, CWinApp )

END_MESSAGE_MAP()

///////////////////////////////////////////////
CMyApp::CMyApp()
{

}
CMyApp::~CMyApp()
{

}
////////////////////////////////////////
CMyApp theApp;

/////////////////////////////////////////
BOOL CMyApp::InitInstance()
{
	CMainFrame* pFrame = new CMainFrame;
	pFrame->Create(0, "MFC");
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow();

	m_pMainWnd = pFrame;

	return TRUE;
}

int CMyApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
