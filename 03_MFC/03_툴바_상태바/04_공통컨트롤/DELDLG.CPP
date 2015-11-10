// DelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComDlg.h"
#include "DelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteDialog dialog


CDeleteDialog::CDeleteDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt,
							 LPCTSTR lpszFileName, DWORD dwFlags,
							 LPCTSTR lpszFilter, CWnd* pParent /*=NULL*/)
	: CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags,
				  lpszFilter, pParent)
{
	//{{AFX_DATA_INIT(CDeleteDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_ofn.Flags |= OFN_ENABLETEMPLATE;
	m_ofn.lpTemplateName = MAKEINTRESOURCE(CDeleteDialog::IDD);
	m_ofn.lpstrTitle = "삭제";
	m_bDeleteAll = FALSE;
}


void CDeleteDialog::DoDataExchange(CDataExchange* pDX)
{
	CFileDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleteDialog, CFileDialog)
	//{{AFX_MSG_MAP(CDeleteDialog)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteDialog message handlers

BOOL CDeleteDialog::OnInitDialog() 
{
	BOOL bRet = CFileDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(bRet == TRUE)
		GetParent()->GetDlgItem(IDOK)->SetWindowText("삭제");

	return bRet;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDeleteDialog::OnDelete() 
{
	// TODO: Add your control notification handler code here
	m_bDeleteAll = TRUE;
	GetParent()->SendMessage(WM_COMMAND, IDCANCEL);
}
