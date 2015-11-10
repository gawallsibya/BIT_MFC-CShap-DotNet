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

	// 2. 초기화(모달리스) 
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


// sysCommand 시스템 커멘드 메뉴 
// 닫기를 했을 경우 처리 
// Alt + F4에도  동작 
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
	Dlg.SetMessage("이것은 모달 대화상자 입니다.");

	if(Dlg.DoModal() == IDOK)	
	{
		CString temp = _T("");	
		temp.Format("입력한 이름은 %s입니다.", Dlg.m_csName);
		AfxMessageBox(temp);
	}
	else		
		AfxMessageBox("취소 되었음");


}

void CDialogDemoDlg::OnButtonModaless() 
{
	// TODO: Add your control notification handler code here
	CTestDlg* pDlg = new CTestDlg;
	ASSERT(pDlg);

	pDlg->SetMessage("이것은 모달리스 대화상자 입니다.");
	pDlg->Create(IDD_Dialog_Test);
	pDlg->ShowWindow(SW_SHOW);


	// 모달리스가 여러개 생성되었을때 안정적인 종료 처리 방법 
	// 객체가 자신을 delete 하게 됨 
	pDlg->m_bSelfDelete = TRUE;

}


void CDialogDemoDlg::OnButtonNModaless() 
{
	if(m_pMDlg == NULL)	
	{
		// 대화상자를 생성하지 않았으므로 메모리 할당하고 모달리스 생성
		m_pMDlg = new CTestDlg;
		m_pMDlg->Create(IDD_Dialog_Test);
		// 윈도우가 제대로 생성되었다면 화면에 보인다.
		if(m_pMDlg->GetSafeHwnd())	
			m_pMDlg->ShowWindow(SW_SHOW);
	}
	else	
	{
		// 대화상자가 이미 생성되었다면 화면에 보여주고 focus이동한다.
		m_pMDlg->ShowWindow(SW_SHOW);	
		m_pMDlg->SetFocus();
	}
	// 모달리스의 종료 
	// WM_DESTROY --> OnDestroy --> PostNCDestroy()

}

void CDialogDemoDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
}





