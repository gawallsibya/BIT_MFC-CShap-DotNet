// App.cpp
#include "App.h"
#include "resource.h"
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


	pFrame->Create( 0, "MENU");
	CMenu menu;
	menu.LoadMenu( IDR_MENU1 );
	pFrame->SetMenu( &menu ); // 메뉴 부착..
//	menu.Detach(); // 메뉴의 핸들을 보호하기 위해..

	// 3. CFrameWnd::LoadFrame으로 윈도우를 만들면 4가지 resource가
	// 자동으로 붙는다
	/*
	pFrame->LoadFrame( IDR_MENU1 ); // 동일 ID의 메뉴, Icon, 
							// accelerator, string TABLE이 자동적재.
	*/
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow();
	
	m_pMainWnd = pFrame;

	return TRUE;
}


	/*
	// 메뉴 부착 방법 2.
	pFrame->Create( 0, "MENU");
	CMenu menu;
	menu.LoadMenu( IDR_MENU1 );
	pFrame->SetMenu( &menu ); // 메뉴 부착..
	menu.Detach(); // 메뉴의 핸들을 보호하기 위해..
	*/

	/*
	// 메뉴 부착 방법 1.
	pFrame->Create( 0, "MFC",
					WS_OVERLAPPEDWINDOW,
					pFrame->rectDefault, // 크기( default 값사용)
					0, // 부모
					MAKEINTRESOURCE(IDR_MENU1) // Menu ID
								// 정수 ID -> 문자열 ID : 100->"100"
					);
	// 메뉴 자동 Disable 기능 제거
//	pFrame->m_bAutoMenuEnable = FALSE;
	*/
int CMyApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
/*
// Detach()의 개념.
class CMenu
{
public:
	HMENU m_hMenu;
	void LoadMenu(UINT id)
	{
		m_hMenu = ::LoadMenu(id); // API를 사용해서 메뉴 Load
	}
	~CMenu() { ::DestroyMenu(m_hMenu); }

	void Detach() { m_hMenu = 0;}
};
*/



