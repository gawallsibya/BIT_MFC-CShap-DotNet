#if !defined(AFX_DLGADD_H__B46DE6EB_05BD_4999_958A_75C47D5B9F4A__INCLUDED_)
#define AFX_DLGADD_H__B46DE6EB_05BD_4999_958A_75C47D5B9F4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAdd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgAdd dialog

class DlgAdd : public CDialog
{
// Construction
public:
	DlgAdd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgAdd)
	enum { IDD = IDD_DIALOG2 };
	CString	m_key;
	CString	m_val;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgAdd)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADD_H__B46DE6EB_05BD_4999_958A_75C47D5B9F4A__INCLUDED_)
