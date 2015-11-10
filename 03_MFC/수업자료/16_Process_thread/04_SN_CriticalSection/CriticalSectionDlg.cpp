// CriticalSectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CriticalSection.h"
#include "CriticalSectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


int g_nData[10];
CCriticalSection g_cs;


/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionDlg dialog

CCriticalSectionDlg::CCriticalSectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCriticalSectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCriticalSectionDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCriticalSectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCriticalSectionDlg)
	DDX_Control(pDX, IDC_RADIO2, m_ctrlDraw);
	DDX_Control(pDX, IDC_RADIO1, m_ctrlReceive);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress[0]);
	DDX_Control(pDX, IDC_PROGRESS2, m_ctrlProgress[1]);
	DDX_Control(pDX, IDC_PROGRESS3, m_ctrlProgress[2]);
	DDX_Control(pDX, IDC_PROGRESS4, m_ctrlProgress[3]);
	DDX_Control(pDX, IDC_PROGRESS5, m_ctrlProgress[4]);
	DDX_Control(pDX, IDC_PROGRESS6, m_ctrlProgress[5]);
	DDX_Control(pDX, IDC_PROGRESS7, m_ctrlProgress[6]);
	DDX_Control(pDX, IDC_PROGRESS8, m_ctrlProgress[7]);
	DDX_Control(pDX, IDC_PROGRESS9, m_ctrlProgress[8]);
	DDX_Control(pDX, IDC_PROGRESS10, m_ctrlProgress[9]);
}

BEGIN_MESSAGE_MAP(CCriticalSectionDlg, CDialog)
	//{{AFX_MSG_MAP(CCriticalSectionDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionDlg message handlers

BOOL CCriticalSectionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	AfxBeginThread(Thread_for_DataReceive, this);
	AfxBeginThread(Thread_for_DataDraw, this);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCriticalSectionDlg::OnPaint() 
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
HCURSOR CCriticalSectionDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


UINT Thread_for_DataReceive(LPVOID pParam)
{
	CCriticalSectionDlg *pWnd = (CCriticalSectionDlg *)pParam;

	while(1)
	{
		Sleep(rand()%1000);

		g_cs.Lock();
		for(int i=0 ; i<10 ; i++)
			g_nData[i] = rand()%100;

		pWnd->m_ctrlReceive.SetCheck(1);
		pWnd->m_ctrlDraw.SetCheck(0);
		
		g_cs.Unlock();
	}
	return 0;
}


UINT Thread_for_DataDraw(LPVOID pParam)
{
	CCriticalSectionDlg *pWnd = (CCriticalSectionDlg *)pParam;

	while(1)
	{
		Sleep(rand()%1000);

		g_cs.Lock();
		for(int i=0 ; i<10 ; i++)
			pWnd->m_ctrlProgress[i].SetPos(g_nData[i]);

		pWnd->m_ctrlReceive.SetCheck(0);
		pWnd->m_ctrlDraw.SetCheck(1);

		g_cs.Unlock();
	}
	return 0;
}
