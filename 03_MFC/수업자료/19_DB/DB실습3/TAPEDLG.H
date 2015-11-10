#if !defined(AFX_TAPEDLG_H__83BD48D2_399B_11D2_941F_006097DCA739__INCLUDED_)
#define AFX_TAPEDLG_H__83BD48D2_399B_11D2_941F_006097DCA739__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TapeDlg.h : header file
//

#include "TapeSet.h"

/////////////////////////////////////////////////////////////////////////////
// CTapeDlg dialog

class CTapeDlg : public CDialog
{
// Construction
public:
	void RecordDelete(CString);
	int m_nlistIndex;
	void ViewList();
	void DBToResource();
	void ResourceToDB();
	long m_lMoney;
	CString m_strActor;
	CString m_strDirector;
	CTime m_tInday;
	CString m_strTitle;
	long m_lTapeCD;
	CTapeSet* m_tSet;
	CTapeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTapeDlg)
	enum { IDD = IDD_TAPE_DLG };
	CListCtrl	m_listTape;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTapeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTapeDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnItemchangedTapeList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTapeDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAPEDLG_H__83BD48D2_399B_11D2_941F_006097DCA739__INCLUDED_)
