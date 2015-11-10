#if !defined(AFX_TESTDLG_H__09A535DC_1D04_4F05_B89C_50A0E5436F9B__INCLUDED_)
#define AFX_TESTDLG_H__09A535DC_1D04_4F05_B89C_50A0E5436F9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

class CTestDlg : public CDialog
{
// Construction
public:
	void SetMessage(char *pszMessage);
	CTestDlg(CWnd* pParent = NULL);   // standard constructor

	// 모달리스 관련 변수 
	BOOL m_bSelfDelete;
	//--------------------------------

// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_Dialog_Test };
	CString	m_csMessage;
	CString	m_csName;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__09A535DC_1D04_4F05_B89C_50A0E5436F9B__INCLUDED_)
