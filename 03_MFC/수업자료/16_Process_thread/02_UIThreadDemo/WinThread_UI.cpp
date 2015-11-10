// WinThread_UI.cpp : implementation file
//

#include "stdafx.h"
#include "UIThreadDemo.h"
#include "WinThread_UI.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWinThread_UI

IMPLEMENT_DYNCREATE(CWinThread_UI, CWinThread)

CWinThread_UI::CWinThread_UI()
{
}

CWinThread_UI::~CWinThread_UI()
{
}

BOOL CWinThread_UI::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	CMainFrame* pFrame = new CMainFrame;
	m_pMainWnd = pFrame;

	// create and load the frame with its resources

	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);

	//인터페이스 쓰레드 윈도우로 설정함
	pFrame->SetMainWnd(FALSE);

	// The one and only window has been initialized, so show and update it.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();

	return TRUE;
}

int CWinThread_UI::ExitInstance()
{
	//사용자 인터페이스 쓰레드가 종료되었으므로,
	//전역변수를 초기화한다.
	g_pUIThread = NULL;
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CWinThread_UI, CWinThread)
	//{{AFX_MSG_MAP(CWinThread_UI)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinThread_UI message handlers
