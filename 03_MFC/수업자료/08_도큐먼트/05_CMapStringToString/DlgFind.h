#if !defined(AFX_DLGFIND_H__E592C748_EF30_4C92_A33C_944E0CA7D0DF__INCLUDED_)
#define AFX_DLGFIND_H__E592C748_EF30_4C92_A33C_944E0CA7D0DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFind.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFind dialog

class CDlgFind : public CDialog
{
// Construction
public:
	CDlgFind(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgFind)
	enum { IDD = IDD_DIALOG1 };
	CString	m_Key;
	CString	m_val;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFind)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgFind)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFIND_H__E592C748_EF30_4C92_A33C_944E0CA7D0DF__INCLUDED_)
