// CriticalSectionDemoDlg.h : header file
//

#if !defined(AFX_CRITICALSECTIONDEMODLG_H__FD3E0290_188C_4B8E_B76F_02EACBCFEF1E__INCLUDED_)
#define AFX_CRITICALSECTIONDEMODLG_H__FD3E0290_188C_4B8E_B76F_02EACBCFEF1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionDemoDlg dialog

class CCriticalSectionDemoDlg : public CDialog
{
// Construction
public:
	CCriticalSectionDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCriticalSectionDemoDlg)
	enum { IDD = IDD_CRITICALSECTIONDEMO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCriticalSectionDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCriticalSectionDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonThread1();
	afx_msg void OnButtonThread2();
	afx_msg void OnButtonGetString();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRITICALSECTIONDEMODLG_H__FD3E0290_188C_4B8E_B76F_02EACBCFEF1E__INCLUDED_)
