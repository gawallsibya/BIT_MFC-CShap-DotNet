// DialogDemoDlg.h : header file
//

#if !defined(AFX_DIALOGDEMODLG_H__EE9259E7_E19F_417C_9618_BB375D4E6BF7__INCLUDED_)
#define AFX_DIALOGDEMODLG_H__EE9259E7_E19F_417C_9618_BB375D4E6BF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TestDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDialogDemoDlg dialog
class CDialogDemoDlg : public CDialog
{
public:
	CTestDlg* m_pMDlg;		// 1. 모달리스 선언

// Construction
public:
	CDialogDemoDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CDialogDemoDlg)
	enum { IDD = IDD_DIALOGDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDialogDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonModaless();
	afx_msg void OnButtonModal();
	afx_msg void OnButtonNModaless();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGDEMODLG_H__EE9259E7_E19F_417C_9618_BB375D4E6BF7__INCLUDED_)
