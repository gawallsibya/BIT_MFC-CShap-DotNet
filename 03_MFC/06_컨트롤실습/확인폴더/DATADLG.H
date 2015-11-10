#if !defined(AFX_DATADLG_H__E4F05BB5_0857_11D2_B6E8_B785B166E236__INCLUDED_)
#define AFX_DATADLG_H__E4F05BB5_0857_11D2_B6E8_B785B166E236__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog

class CDataDlg : public CDialog
{
// Construction
public:
	CDataDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDataDlg)
	enum { IDD = IDD_MODAL };
	CStatic	m_ImageCtrl;
	CComboBox	m_Combo;
	CStatic	m_ctlStatic2;
	CEdit	m_ctlEdit2;
	CString	m_strEdit3;
	CString	m_strStatic3;
	CString	m_strCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBitmap m_imgBatgirl;
	CBitmap m_imgBatman;

	// Generated message map functions
	//{{AFX_MSG(CDataDlg)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnComboAdd();
	afx_msg void OnListAdd();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnDblclkList1();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATADLG_H__E4F05BB5_0857_11D2_B6E8_B785B166E236__INCLUDED_)
