// Single.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"						
/*
(1) 특별한 h파일로 반드시 다른 파일보다 먼저 #include 되어야 함
    이 파일이 미리 컴파일된 헤더로 사용되기 때문임


	- Project-Setting(Alt+F7)  ? C/C++ ? Category(procomplied headers) 
    
    - 미리 컴파일된 헤더 
      실행파일을 만드는 과정에서 가장 많이 시간이 드는 부분 
	  : 컴파일 시간임

      이에 비해 전처리 시간이나 링크 시간은 상대적으로 적은 시간을 필요로 함
      하지만 h파일이 많아지면 전처리 시간도 무시할 수 없게 되었다.
      따라서 헤더를 미리 컴파일하여 링크하는 기술이 필요로 하게 됨

      유의점) 미리 컴파일된 헤더(PCH)를 사용할 때는 
	          #include 순서에 따라 생성하는 코드가 달라진다.

        #include "a.h"
        #include "b.h"
              와
        #include "b.h"
        #include "a.h" 
              는 다르다.

       규칙) PCH를 사용하는 헤더를 다른 헤더 파일보다 제일 먼저 두어야 한다.
       무시할 경우) #include "stdafx.h" 위치를 아래로 변경하면 ??
       따라서 사용자가 헤더 파일을 추가할때는 stdafx보다 다음에 명시해야 함

*/


#include "Single.h"

#include "MainFrm.h"
#include "SingleDoc.h"
#include "SingleView.h"

#ifdef _DEBUG							// (2)
#define new DEBUG_NEW					// (3)

/*
(2),(3) 빌드 타겟(build target) Win32 Debug로 설정되었을 때 사용할 매크로 설정
프로그램 개발시 빈번한 디버깅이 필요하다면 디버깅만을 위한 여분의 함수가 필요함 
 ex) 메모리 검사를 엄격히 하는 메모리 할당 함수, 필요한 메시지를 출력하는 진단함수…

배포시는 최적화가 바람직 
따라서 빌드 타겟을 여러 개를 지원한다.(Project-Setting)에서 확인
		
#define new DEBUG_NEW		: 메모리 검사를 엄격히 하는 디버깅 버전의 new
static char THIS_FILE[] = __FILE__;	: 파일의 이름을 추적하기 위한 메크로 
Release일 경우에는 무시됨

메모리 검사
*/


#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleApp

BEGIN_MESSAGE_MAP(CSingleApp, CWinApp)	// (4)
	//{{AFX_MSG_MAP(CSingleApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()						// (5)

/*
  (4),(5) 메시지 맵 구현 부	:	[  F12  ]
*/

/////////////////////////////////////////////////////////////////////////////
// CSingleApp construction

CSingleApp::CSingleApp()
{
	// TODO: add construction code here,	// (6)
	// Place all significant initialization in InitInstance
}

/*
(6) 사용자가 추가할 코드의 위치를 알려줌 
*/

/////////////////////////////////////////////////////////////////////////////
// The one and only CSingleApp object

CSingleApp theApp;							// (7)
/*
(7) App 클래스의 전역 객체
*/


/////////////////////////////////////////////////////////////////////////////
// CSingleApp initialization

/*
(8) InitInstance() : 윈도우 클래스 등록, 생성, 호출(ShowWindow(), UpdateWindow() )
*/

BOOL CSingleApp::InitInstance()				// (8)
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));	// (9)
	/*
	(9) 레지스트리에 정보를 기록 : 
		Unicode (HKEY_CURRENT_USER => sofrware키 밑에 확인)
	*/

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;					// (10)
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSingleDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CSingleView));
	AddDocTemplate(pDocTemplate);			
	/*
	(10) 다큐먼트 탬플릿 구성
	     ( 다큐먼트, 메인 프레임, 뷰 객체를 동적 생성하는 부분)
	*/

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);					
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CSingleApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CSingleApp message handlers

