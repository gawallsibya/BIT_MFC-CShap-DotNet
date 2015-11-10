// CriticalSectionDlg.h : header file
//

#if !defined(AFX_CRITICALSECTIONDLG_H__81AEDCE2_E6A0_4540_A362_A15513996FF4__INCLUDED_)
#define AFX_CRITICALSECTIONDLG_H__81AEDCE2_E6A0_4540_A362_A15513996FF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCriticalSectionDlg dialog

class CCriticalSectionDlg : public CDialog
{
// Construction
public:
	CCriticalSectionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCriticalSectionDlg)
	enum { IDD = IDD_CRITICALSECTION_DIALOG };
	CButton	m_ctrlDraw;
	CButton	m_ctrlReceive;
	//}}AFX_DATA
	CProgressCtrl	m_ctrlProgress[10];

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCriticalSectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCriticalSectionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

UINT Thread_for_DataDraw(LPVOID pParam);
UINT Thread_for_DataReceive(LPVOID pParam);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRITICALSECTIONDLG_H__81AEDCE2_E6A0_4540_A362_A15513996FF4__INCLUDED_)
