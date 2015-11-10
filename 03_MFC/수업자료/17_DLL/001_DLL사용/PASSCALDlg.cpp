// PASSCALDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PASSCAL.h"
#include "PASSCALDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CPASSCALDlg dialog

CPASSCALDlg::CPASSCALDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPASSCALDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPASSCALDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hInstDll	= NULL;
}

void CPASSCALDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPASSCALDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPASSCALDlg, CDialog)
	//{{AFX_MSG_MAP(CPASSCALDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RUNTIME_LINK, OnRuntimeLink)
	ON_BN_CLICKED(IDC_IMPORT_LIB, OnImportLib)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPASSCALDlg message handlers

BOOL CPASSCALDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPASSCALDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPASSCALDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPASSCALDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// importLib를 이용한 연결 방법
/*
1. 클라이언트 프로그램을 포함하는 디렉토리
2. 현재 작업 디렉토리
3. 윈도우 시스템 디렉토리
4. 윈도우 디렉토리
5. Path환경변수에 설정된 디렉토리 
*/

#ifdef __cplusplus
	extern "C" {
#endif 
		
	__declspec(dllimport) BOOL ShowSetupDialog(char* szMail, char* szPath);

#ifdef __cplusplus
	}
#endif 

// Pass.lib
void CPASSCALDlg::OnImportLib() 
{
	char szMail[40];
	char szPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szPath);

	if(ShowSetupDialog(szMail, szPath))
	{
		CString strInfo;
		strInfo.Format("E-mail : %s\n설치 경로 : %s",
			szMail, szPath);
		AfxMessageBox(strInfo);
	}	
}


// 프로그램 실행시 연결 방법
/*
1. LoadLibrary 함수에 설정된 디렉토리 
2. 현재 작업 디렉토리
3. 윈도우 시스템 디렉토리
4. 윈도우 디렉토리
5. Path환경변수에 설정된 디렉토리 
*/

typedef BOOL (*pFunc)(char*, char*);
void CPASSCALDlg::OnRuntimeLink() 
{
	if(m_hInstDll == NULL) // DLL이 로드된 상태인지 판단
	{
		m_hInstDll = LoadLibrary("Pass.dll");
		if(m_hInstDll == NULL)
		{
			AfxMessageBox("Help.dll 로드 실패");
			return;
		}
	}
	pFunc	pF; // 함수 포인터 선언
	pF = (pFunc)GetProcAddress(m_hInstDll, "ShowSetupDialog");
	if(pF == NULL)
	{
		AfxMessageBox("ShowHelp() 함수 실패");
		return;
	}

	char szMail[40];
	char szPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szPath);

	if(pF(szMail, szPath))
	{
		CString strInfo;
		strInfo.Format("E-mail : %s\n설치 경로 : %s",
			szMail, szPath);
		AfxMessageBox(strInfo);
	}	


	if(!FreeLibrary(m_hInstDll))
			AfxMessageBox("Help.dll 해제 실패");
}

