// TextProgressDemoDlg.h : header file
//

#if !defined(AFX_TEXTPROGRESSDEMODLG_H__9EC0EF22_6445_4778_A2D8_79A8AA47FE27__INCLUDED_)
#define AFX_TEXTPROGRESSDEMODLG_H__9EC0EF22_6445_4778_A2D8_79A8AA47FE27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TextProgress.h"

/////////////////////////////////////////////////////////////////////////////
// CTextProgressDemoDlg dialog

class CTextProgressDemoDlg : public CDialog
{
// Construction
public:
	CTextProgressDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTextProgressDemoDlg)
	enum { IDD = IDD_TEXTPROGRESSDEMO_DIALOG };
	CTextProgress	m_Progress;
	int		m_nData;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextProgressDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextProgressDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonSetValue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTPROGRESSDEMODLG_H__9EC0EF22_6445_4778_A2D8_79A8AA47FE27__INCLUDED_)
