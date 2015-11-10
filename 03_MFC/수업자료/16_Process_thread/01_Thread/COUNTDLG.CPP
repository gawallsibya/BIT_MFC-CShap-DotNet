// CountDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Count.h"
#include "CountDlg.h"
#include "MyThread.h"

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
// CCountDlg dialog

CCountDlg::CCountDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCountDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCountDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pMyThread = NULL;
}

void CCountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCountDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCountDlg, CDialog)
	//{{AFX_MSG_MAP(CCountDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_COUNT, OnStartCount)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_START_PROGRESS, OnStartProgress)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCountDlg message handlers

BOOL CCountDlg::OnInitDialog()
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

void CCountDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCountDlg::OnPaint() 
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
HCURSOR CCountDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CCountDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(	nCtlColor == CTLCOLOR_STATIC)
		pDC->SetTextColor(RGB(0, 0, 255));

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

// 작업 스레드 함수 정의 
UINT CCountDlg::MySumProc(void * lParam)
{
	int nResult = 0;
	CCountDlg* pDlg = (CCountDlg*)lParam;

	for(int i = 1; i <= 10000; i++)
	{
		nResult += i;
		pDlg->SetDlgItemInt(IDC_RESULT, nResult);
	}
	pDlg->GetDlgItem(IDC_START_COUNT)->EnableWindow(TRUE);
	return 0;
}


void CCountDlg::OnStartCount() 
{
	/*
	int nResult = 0;
	for(int i = 1; i <= 10000; i++)
	{
		nResult += i;
		SetDlgItemInt(IDC_RESULT, nResult);
	}
	*/
	AfxBeginThread(MySumProc, this);
	GetDlgItem(IDC_START_COUNT)->EnableWindow(FALSE);		
}


// 사용자 인터페이스 스레드 생성
void CCountDlg::OnStartProgress() 
{
	m_pMyThread =   // 스레드 생성과 함께 스레드를 중단
		(CMyThread*)AfxBeginThread(RUNTIME_CLASS(CMyThread), THREAD_PRIORITY_LOWEST,
		                                 0, CREATE_SUSPENDED);
	m_pMyThread->SetOwner(this); // 메인 스레드와 UI 스레드간 통신을 위해
	m_pMyThread->ResumeThread(); // 스레드를 재개한다.
	GetDlgItem(IDC_START_PROGRESS)->EnableWindow(FALSE); 	
}

void CCountDlg::OnCheck1() 
{
	CButton* pCheck = (CButton*)GetDlgItem(IDC_CHECK1);
	BOOL bSuspend = pCheck->GetCheck();
	if(bSuspend) 
	{
		m_pMyThread->SuspendThread(); // 스레드 중단
	}
	else
	{
		m_pMyThread->ResumeThread(); // 스레드 계속 진행
	}
		
}
