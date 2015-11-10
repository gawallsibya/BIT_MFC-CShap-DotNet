#if !defined(AFX_CUSTAPEDLG_H__83BD48D1_399B_11D2_941F_006097DCA739__INCLUDED_)
#define AFX_CUSTAPEDLG_H__83BD48D1_399B_11D2_941F_006097DCA739__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CusTapeDlg.h : header file
//

#include "CusTapeSet.h"
#include "TapeSet.h"

/////////////////////////////////////////////////////////////////////////////
// CCusTapeDlg dialog

class CCusTapeDlg : public CDialog
{
// Construction
public:
	BOOL m_bReceive;
	void DBToResource();
	void ResourceToDB();
	void TapeList();
	CTapeSet* m_tSet;
	CCusTapeSet* m_ctSet;
	int m_flagMode;
	CCusTapeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCusTapeDlg)
	enum { IDD = IDD_CUSTAPE_DLG };
	CListCtrl	m_listTitle;
	CString	m_strName;
	CString	m_strRecDay;
	CString	m_strRentDay;
	long	m_nTapeCD;
	CString	m_strTitle;
	long	m_nCustomCD;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCusTapeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCusTapeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCustapeAdd();
	afx_msg void OnCustapeComplete();
	afx_msg void OnCustapeDelete();
	afx_msg void OnCustapeUpdate();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTAPEDLG_H__83BD48D1_399B_11D2_941F_006097DCA739__INCLUDED_)
