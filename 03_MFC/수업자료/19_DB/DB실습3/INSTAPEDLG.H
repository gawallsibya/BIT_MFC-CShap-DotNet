#if !defined(AFX_INSTAPEDLG_H__83BD48D3_399B_11D2_941F_006097DCA739__INCLUDED_)
#define AFX_INSTAPEDLG_H__83BD48D3_399B_11D2_941F_006097DCA739__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// InsTapeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInsTapeDlg dialog

class CInsTapeDlg : public CDialog
{
// Construction
public:
	CInsTapeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInsTapeDlg)
	enum { IDD = IDD_INSTAPE_DLG };
	CString	m_strActor;
	long	m_lTapeCD;
	CString	m_strDirector;
	CString	m_tInday;
	long	m_lMoney;
	CString	m_strTitle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsTapeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInsTapeDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTAPEDLG_H__83BD48D3_399B_11D2_941F_006097DCA739__INCLUDED_)
