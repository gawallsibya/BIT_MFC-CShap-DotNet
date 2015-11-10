#if !defined(AFX_SETUPDLG_H__297EC82B_6AE6_468E_8411_7EEC1C0EAADD__INCLUDED_)
#define AFX_SETUPDLG_H__297EC82B_6AE6_468E_8411_7EEC1C0EAADD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetupDlg dialog

class CSetupDlg : public CDialog
{
// Construction
public:
	CSetupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetupDlg)
	enum { IDD = IDD_SETUP };
	CAnimateCtrl	m_Avi;
	CString	m_Mail;
	CString	m_Path;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetupDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETUPDLG_H__297EC82B_6AE6_468E_8411_7EEC1C0EAADD__INCLUDED_)
