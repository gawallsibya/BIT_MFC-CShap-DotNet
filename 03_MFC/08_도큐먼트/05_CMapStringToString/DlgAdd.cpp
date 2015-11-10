// DlgAdd.cpp : implementation file
//

#include "stdafx.h"
#include "Bam.h"
#include "DlgAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgAdd dialog


DlgAdd::DlgAdd(CWnd* pParent /*=NULL*/)
	: CDialog(DlgAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgAdd)
	m_key = _T("");
	m_val = _T("");
	//}}AFX_DATA_INIT
}


void DlgAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgAdd)
	DDX_Text(pDX, IDC_EDIT1, m_key);
	DDX_Text(pDX, IDC_EDIT2, m_val);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgAdd, CDialog)
	//{{AFX_MSG_MAP(DlgAdd)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgAdd message handlers
