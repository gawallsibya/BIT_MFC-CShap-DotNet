// Single.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"						
/*
(1) Ư���� h���Ϸ� �ݵ�� �ٸ� ���Ϻ��� ���� #include �Ǿ�� ��
    �� ������ �̸� �����ϵ� ����� ���Ǳ� ������


	- Project-Setting(Alt+F7)  ? C/C++ ? Category(procomplied headers) 
    
    - �̸� �����ϵ� ��� 
      ���������� ����� �������� ���� ���� �ð��� ��� �κ� 
	  : ������ �ð���

      �̿� ���� ��ó�� �ð��̳� ��ũ �ð��� ��������� ���� �ð��� �ʿ�� ��
      ������ h������ �������� ��ó�� �ð��� ������ �� ���� �Ǿ���.
      ���� ����� �̸� �������Ͽ� ��ũ�ϴ� ����� �ʿ�� �ϰ� ��

      ������) �̸� �����ϵ� ���(PCH)�� ����� ���� 
	          #include ������ ���� �����ϴ� �ڵ尡 �޶�����.

        #include "a.h"
        #include "b.h"
              ��
        #include "b.h"
        #include "a.h" 
              �� �ٸ���.

       ��Ģ) PCH�� ����ϴ� ����� �ٸ� ��� ���Ϻ��� ���� ���� �ξ�� �Ѵ�.
       ������ ���) #include "stdafx.h" ��ġ�� �Ʒ��� �����ϸ� ??
       ���� ����ڰ� ��� ������ �߰��Ҷ��� stdafx���� ������ ����ؾ� ��

*/


#include "Single.h"

#include "MainFrm.h"
#include "SingleDoc.h"
#include "SingleView.h"

#ifdef _DEBUG							// (2)
#define new DEBUG_NEW					// (3)

/*
(2),(3) ���� Ÿ��(build target) Win32 Debug�� �����Ǿ��� �� ����� ��ũ�� ����
���α׷� ���߽� ����� ������� �ʿ��ϴٸ� ����븸�� ���� ������ �Լ��� �ʿ��� 
 ex) �޸� �˻縦 ������ �ϴ� �޸� �Ҵ� �Լ�, �ʿ��� �޽����� ����ϴ� �����Լ���

�����ô� ����ȭ�� �ٶ��� 
���� ���� Ÿ���� ���� ���� �����Ѵ�.(Project-Setting)���� Ȯ��
		
#define new DEBUG_NEW		: �޸� �˻縦 ������ �ϴ� ����� ������ new
static char THIS_FILE[] = __FILE__;	: ������ �̸��� �����ϱ� ���� ��ũ�� 
Release�� ��쿡�� ���õ�

�޸� �˻�
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
  (4),(5) �޽��� �� ���� ��	:	[  F12  ]
*/

/////////////////////////////////////////////////////////////////////////////
// CSingleApp construction

CSingleApp::CSingleApp()
{
	// TODO: add construction code here,	// (6)
	// Place all significant initialization in InitInstance
}

/*
(6) ����ڰ� �߰��� �ڵ��� ��ġ�� �˷��� 
*/

/////////////////////////////////////////////////////////////////////////////
// The one and only CSingleApp object

CSingleApp theApp;							// (7)
/*
(7) App Ŭ������ ���� ��ü
*/


/////////////////////////////////////////////////////////////////////////////
// CSingleApp initialization

/*
(8) InitInstance() : ������ Ŭ���� ���, ����, ȣ��(ShowWindow(), UpdateWindow() )
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
	(9) ������Ʈ���� ������ ��� : 
		Unicode (HKEY_CURRENT_USER => sofrwareŰ �ؿ� Ȯ��)
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
	(10) ��ť��Ʈ ���ø� ����
	     ( ��ť��Ʈ, ���� ������, �� ��ü�� ���� �����ϴ� �κ�)
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

