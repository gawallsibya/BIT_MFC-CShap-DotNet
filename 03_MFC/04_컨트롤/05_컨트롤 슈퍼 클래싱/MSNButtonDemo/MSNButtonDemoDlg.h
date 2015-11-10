// MSNButtonDemoDlg.h : header file
//

#if !defined(AFX_MSNBUTTONDEMODLG_H__74B66AB2_5BB6_4653_A9D9_25E7ED91ADDC__INCLUDED_)
#define AFX_MSNBUTTONDEMODLG_H__74B66AB2_5BB6_4653_A9D9_25E7ED91ADDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MSNButton.h"

/////////////////////////////////////////////////////////////////////////////
// CMSNButtonDemoDlg dialog

class CMSNButtonDemoDlg : public CDialog
{
// Construction
public:
	CMSNButtonDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMSNButtonDemoDlg)
	enum { IDD = IDD_MSNBUTTONDEMO_DIALOG };
	CMSNButton	m_Button_MSN;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSNButtonDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMSNButtonDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSNBUTTONDEMODLG_H__74B66AB2_5BB6_4653_A9D9_25E7ED91ADDC__INCLUDED_)
