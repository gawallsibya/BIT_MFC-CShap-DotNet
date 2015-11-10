// GraphExampleDlg.h : header file
//

#if !defined(AFX_GRAPHEXAMPLEDLG_H__DD5AF0BB_089D_4826_8F0A_38DA7AE87D1A__INCLUDED_)
#define AFX_GRAPHEXAMPLEDLG_H__DD5AF0BB_089D_4826_8F0A_38DA7AE87D1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MovingGraph.h"

/////////////////////////////////////////////////////////////////////////////
// CGraphExampleDlg dialog

class CGraphExampleDlg : public CDialog
{
// Construction
public:
	CGraphExampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGraphExampleDlg)
	enum { IDD = IDD_GRAPHEXAMPLE_DIALOG };
	CMovingGraph	m_graph;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphExampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGraphExampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStart();
	afx_msg void OnBtnStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHEXAMPLEDLG_H__DD5AF0BB_089D_4826_8F0A_38DA7AE87D1A__INCLUDED_)
