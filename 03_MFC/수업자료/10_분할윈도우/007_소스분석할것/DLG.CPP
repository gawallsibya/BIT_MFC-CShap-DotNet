// Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Enroll.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog


CCourseDlg::CCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCourseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCourseDlg)
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCourseDlg)
	DDX_Text(pDX, IDC_NAME, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCourseDlg, CDialog)
	//{{AFX_MSG_MAP(CCourseDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog


CStudentDlg::CStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentDlg)
	m_Name = _T("");
	m_Telno = _T("");
	m_Birth = _T("");
	m_Sex = -1;
	//}}AFX_DATA_INIT
}


void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentDlg)
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_TELNO, m_Telno);
	DDX_Text(pDX, IDC_BIRTH, m_Birth);
	DDX_Radio(pDX, IDC_SEX, m_Sex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg message handlers
