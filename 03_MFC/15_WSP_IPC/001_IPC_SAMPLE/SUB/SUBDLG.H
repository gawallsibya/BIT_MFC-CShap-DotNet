// SubDlg.h : header file
//

#if !defined(AFX_SUBDLG_H__441082BA_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_)
#define AFX_SUBDLG_H__441082BA_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSubDlg dialog 

#define WM_MY_MSG   WM_USER+7 // 사용자 정의 메시지를 정의한다.

class CSubDlg : public CDialog
{
// Construction
public:
	CSubDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSubDlg)
	enum { IDD = IDD_SUB_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSubDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	LONG OnMyUserProc(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLG_H__441082BA_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_)
