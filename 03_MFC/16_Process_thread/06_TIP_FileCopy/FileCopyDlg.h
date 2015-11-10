// FileCopyDlg.h : header file
//

#if !defined(AFX_FILECOPYDLG_H__E08E8EC7_AA29_43FD_8DF7_C3F2FFEE6283__INCLUDED_)
#define AFX_FILECOPYDLG_H__E08E8EC7_AA29_43FD_8DF7_C3F2FFEE6283__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileCopyDlg dialog

class CFileCopyDlg : public CDialog
{
// Construction
public:
	CFileCopyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileCopyDlg)
	enum { IDD = IDD_FILECOPY_DIALOG };
	CListBox	m_ctrlListBox;
	CString	m_strDest;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileCopyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileCopyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFrom();
	afx_msg void OnTo();
	afx_msg void OnStartCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


UINT ThreadFunc(LPVOID pParam);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILECOPYDLG_H__E08E8EC7_AA29_43FD_8DF7_C3F2FFEE6283__INCLUDED_)
