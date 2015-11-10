// MyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "DlgSample.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDialog dialog


CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	// IDC_EDIT1 과 멤버 변수 text를 연결한다.
	DDX_Text( pDX, IDC_EDIT1, text);


	//{{AFX_DATA_MAP(CMyDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	//{{AFX_MSG_MAP(CMyDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CMyDialog message handlers

void CMyDialog::OnButton1() 
{
	AfxMessageBox("Test");	
	CDialog::OnCancel(); // dialog 종료
}

void CMyDialog::OnOK() 
{
	// control->멤버 변수
//	UpdateData(TRUE);
	CDialog::OnOK(); // 내부적으로 UpdateData(TRUE);

	/*
	char buf[256];
	
	// ID에서 MFC Control 을 얻기.
//	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1); // !!!!!
//	pEdit->GetWindowText( buf, 256);

	// ID에서 바로 값을 얻기.
	GetDlgItemText( IDC_EDIT1, buf, 256);
	MessageBox( buf );
	*/
	// 부모의 OnOK()는 내부적으로 EndDialog()를 호출 Dialog를 
	// 닫는다.
	//CDialog::OnOK();
}

void CMyDialog::OnCancel() 
{
	
	CDialog::OnCancel();
}

BOOL CMyDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// 멤버 변수->Control로 옮긴다
//	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
