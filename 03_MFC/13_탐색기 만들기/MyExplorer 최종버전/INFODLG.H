#if !defined(AFX_INFODLG_H__4798FD79_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
#define AFX_INFODLG_H__4798FD79_3B8A_11D2_A360_D86A33074DD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog

class CInfoDlg : public CDialog
{
// Construction
public:
	CInfoDlg(CWnd* pParent = NULL);   // standard constructor

public:
	void	SetInfo(CObList* pFileList);

// Dialog Data
	//{{AFX_DATA(CInfoDlg)
	enum { IDD = IDD_INFO_DLG };
	BOOL	m_bArchive;
	BOOL	m_bHidden;
	BOOL	m_bReadOnly;
	BOOL	m_bSystem;
	CString	m_strCreationTime;
	CString	m_strFileName;
	CString	m_strFileSize;
	CString	m_strKind;
	CString	m_strLastAccessTime;
	CString	m_strLastWriteTime;
	CString	m_strName;
	CString	m_strPath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInfoDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFODLG_H__4798FD79_3B8A_11D2_A360_D86A33074DD9__INCLUDED_)
