#if !defined(AFX_MYDIALOG_H__5B6E9A43_D961_4AFD_B0EE_AAB88CE57C46__INCLUDED_)
#define AFX_MYDIALOG_H__5B6E9A43_D961_4AFD_B0EE_AAB88CE57C46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyDialog dialog

class CMyDialog : public CDialog
{
// Construction
public:
	
	CString text; // IDC_EDIT1 와 연결할 변수.



	CMyDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDialog)
	enum { IDD = IDD_MYDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyDialog)
	afx_msg void OnButton1();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDIALOG_H__5B6E9A43_D961_4AFD_B0EE_AAB88CE57C46__INCLUDED_)
