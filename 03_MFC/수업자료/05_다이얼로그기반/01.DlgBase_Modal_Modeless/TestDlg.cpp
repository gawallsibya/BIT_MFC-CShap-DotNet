// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DialogDemo.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog


CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
	m_csMessage = _T("");
	m_csName = _T("");
	//}}AFX_DATA_INIT
	m_bSelfDelete		= FALSE;
}


void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Text(pDX, IDC_Static_Message, m_csMessage);
	DDX_Text(pDX, IDC_Edit_Name, m_csName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTestDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CTestDlg::SetMessage(char *pszMessage)
{
	m_csMessage.Format("%s", pszMessage);
}




void CTestDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}




void CTestDlg::OnOK() 
{
	UpdateData(TRUE);
	if(m_csName.GetLength() == 0)	
	{
		CEdit *pEdit = (CEdit*)GetDlgItem(IDC_Edit_Name);
		AfxMessageBox("�̸��� �Է��ϼ���");	
		pEdit->SetFocus();	
		return;	
	}
	CDialog::OnOK();
}


// WM_DESTROY --> OnDestroy --> PostNCDestroy()
// Non-Client ���� �ı� : delet this ���(�ٸ� ���� �ڱ��ڽ� �ı��� �ȵȴ�.)
// ���ϵǸ鼭 Ŭ���̾�Ʈ �䰡 ������ �ı��ȴ�.

void CTestDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_bSelfDelete)	
	{  
		AfxMessageBox("test");		
		delete this;	
	}
	else	
	{
		CDialog::PostNcDestroy();	
	}
	
	CDialog::PostNcDestroy();
}

// CDialogDemoDlg::OnSysCommand  Ȯ���� �� 