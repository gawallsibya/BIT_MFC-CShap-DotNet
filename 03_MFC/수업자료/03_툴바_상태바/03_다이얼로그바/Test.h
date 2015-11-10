#if !defined(AFX_TEST_H__03FBF263_BDD1_47E3_9F09_E49603F1DEE8__INCLUDED_)
#define AFX_TEST_H__03FBF263_BDD1_47E3_9F09_E49603F1DEE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Test.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Test dialog

class Test : public CDialog
{
// Construction
public:
	Test(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Test)
	enum { IDD = CG_IDD_MYDIALOGBAR };
	CComboBox	m_test;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Test)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Test)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_H__03FBF263_BDD1_47E3_9F09_E49603F1DEE8__INCLUDED_)
