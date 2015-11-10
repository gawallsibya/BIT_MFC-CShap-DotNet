// DialogDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DialogDemo.h"
#include "DialogDemoDlg.h"

#include "TestDlg.h"

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
// CDialogDemoDlg dialog

CDialogDemoDlg::CDialogDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogDemoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// 2. �ʱ�ȭ(��޸���) 
	m_pMDlg = NULL;

}

void CDialogDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogDemoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CDialogDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Button_Modaless, OnButtonModaless)
	ON_BN_CLICKED(IDC_Button_Modal, OnButtonModal)
	ON_BN_CLICKED(IDC_Button_NModaless, OnButtonNModaless)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogDemoDlg message handlers

BOOL CDialogDemoDlg::OnInitDialog()
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


// sysCommand �ý��� Ŀ��� �޴� 
// �ݱ⸦ ���� ��� ó�� 
// Alt + F4����  ���� 
void CDialogDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		if(nID == SC_CLOSE)
		{	
			ShowWindow(SW_MINIMIZE);	
			return;	
		}

		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogDemoDlg::OnPaint() 
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
HCURSOR CDialogDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDialogDemoDlg::OnButtonModal() 
{
	// TODO: Add your control notification handler code here
	CTestDlg Dlg;
	Dlg.SetMessage("�̰��� ��� ��ȭ���� �Դϴ�.");

	if(Dlg.DoModal() == IDOK)	
	{
		CString temp = _T("");	
		temp.Format("�Է��� �̸��� %s�Դϴ�.", Dlg.m_csName);
		AfxMessageBox(temp);
	}
	else		
		AfxMessageBox("��� �Ǿ���");


}

void CDialogDemoDlg::OnButtonModaless() 
{
	// TODO: Add your control notification handler code here
	CTestDlg* pDlg = new CTestDlg;
	ASSERT(pDlg);

	pDlg->SetMessage("�̰��� ��޸��� ��ȭ���� �Դϴ�.");
	pDlg->Create(IDD_Dialog_Test);
	pDlg->ShowWindow(SW_SHOW);


	// ��޸����� ������ �����Ǿ����� �������� ���� ó�� ��� 
	// ��ü�� �ڽ��� delete �ϰ� �� 
	pDlg->m_bSelfDelete = TRUE;

}


void CDialogDemoDlg::OnButtonNModaless() 
{
	if(m_pMDlg == NULL)	
	{
		// ��ȭ���ڸ� �������� �ʾ����Ƿ� �޸� �Ҵ��ϰ� ��޸��� ����
		m_pMDlg = new CTestDlg;
		m_pMDlg->Create(IDD_Dialog_Test);
		// �����찡 ����� �����Ǿ��ٸ� ȭ�鿡 ���δ�.
		if(m_pMDlg->GetSafeHwnd())	
			m_pMDlg->ShowWindow(SW_SHOW);
	}
	else	
	{
		// ��ȭ���ڰ� �̹� �����Ǿ��ٸ� ȭ�鿡 �����ְ� focus�̵��Ѵ�.
		m_pMDlg->ShowWindow(SW_SHOW);	
		m_pMDlg->SetFocus();
	}
	// ��޸����� ���� 
	// WM_DESTROY --> OnDestroy --> PostNCDestroy()

}

void CDialogDemoDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
}





