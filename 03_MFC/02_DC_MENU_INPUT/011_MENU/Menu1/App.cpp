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
	pFrame->SetMenu( &menu ); // �޴� ����..
//	menu.Detach(); // �޴��� �ڵ��� ��ȣ�ϱ� ����..

	// 3. CFrameWnd::LoadFrame���� �����츦 ����� 4���� resource��
	// �ڵ����� �ٴ´�
	/*
	pFrame->LoadFrame( IDR_MENU1 ); // ���� ID�� �޴�, Icon, 
							// accelerator, string TABLE�� �ڵ�����.
	*/
	pFrame->ShowWindow( SW_SHOW );
	pFrame->UpdateWindow();
	
	m_pMainWnd = pFrame;

	return TRUE;
}


	/*
	// �޴� ���� ��� 2.
	pFrame->Create( 0, "MENU");
	CMenu menu;
	menu.LoadMenu( IDR_MENU1 );
	pFrame->SetMenu( &menu ); // �޴� ����..
	menu.Detach(); // �޴��� �ڵ��� ��ȣ�ϱ� ����..
	*/

	/*
	// �޴� ���� ��� 1.
	pFrame->Create( 0, "MFC",
					WS_OVERLAPPEDWINDOW,
					pFrame->rectDefault, // ũ��( default �����)
					0, // �θ�
					MAKEINTRESOURCE(IDR_MENU1) // Menu ID
								// ���� ID -> ���ڿ� ID : 100->"100"
					);
	// �޴� �ڵ� Disable ��� ����
//	pFrame->m_bAutoMenuEnable = FALSE;
	*/
int CMyApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
/*
// Detach()�� ����.
class CMenu
{
public:
	HMENU m_hMenu;
	void LoadMenu(UINT id)
	{
		m_hMenu = ::LoadMenu(id); // API�� ����ؼ� �޴� Load
	}
	~CMenu() { ::DestroyMenu(m_hMenu); }

	void Detach() { m_hMenu = 0;}
};
*/



