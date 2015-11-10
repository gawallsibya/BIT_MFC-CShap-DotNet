// HTStaticDemoDlg.h : header file
//

#if !defined(AFX_HTSTATICDEMODLG_H__BC178917_096D_4951_8D70_54C02A470129__INCLUDED_)
#define AFX_HTSTATICDEMODLG_H__BC178917_096D_4951_8D70_54C02A470129__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "HTStatic.h"
#include "GraphStatic.h"

/////////////////////////////////////////////////////////////////////////////
// CHTStaticDemoDlg dialog

class CHTStaticDemoDlg : public CDialog
{
// Construction
public:
	CHTStaticDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHTStaticDemoDlg)
	enum { IDD = IDD_HTSTATICDEMO_DIALOG };
	CGraphStatic	m_Static_Graph;
	CStatic	m_Static_Normal;
	CHTStatic	m_Static_HT;
	int		m_nData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHTStaticDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHTStaticDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButtonSetData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HTSTATICDEMODLG_H__BC178917_096D_4951_8D70_54C02A470129__INCLUDED_)
