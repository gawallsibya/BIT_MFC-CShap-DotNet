// CountDlg.h : header file
//

#if !defined(AFX_COUNTDLG_H__A2FECC47_3557_11D2_93C8_994F20443AA5__INCLUDED_)
#define AFX_COUNTDLG_H__A2FECC47_3557_11D2_93C8_994F20443AA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCountDlg dialog

class CMyThread; // 후위 참조를 위해
class CCountDlg : public CDialog
{
// Construction
public:
	CCountDlg(CWnd* pParent = NULL);	// standard constructor
	static UINT MySumProc(void * lParam); // 작업 스레드 함수 
	CMyThread* m_pMyThread;
// Dialog Data
	//{{AFX_DATA(CCountDlg)
	enum { IDD = IDD_COUNT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCountDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCountDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartCount();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStartProgress();
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COUNTDLG_H__A2FECC47_3557_11D2_93C8_994F20443AA5__INCLUDED_)
