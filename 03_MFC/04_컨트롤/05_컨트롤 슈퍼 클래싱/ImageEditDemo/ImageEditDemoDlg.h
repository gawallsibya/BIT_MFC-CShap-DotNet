// ImageEditDemoDlg.h : header file
//

#if !defined(AFX_IMAGEEDITDEMODLG_H__B581EFCD_C9DF_4CF3_A8AB_965FB2A67ED5__INCLUDED_)
#define AFX_IMAGEEDITDEMODLG_H__B581EFCD_C9DF_4CF3_A8AB_965FB2A67ED5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImageEdit.h"

/////////////////////////////////////////////////////////////////////////////
// CImageEditDemoDlg dialog

class CImageEditDemoDlg : public CDialog
{
// Construction
public:
	CImageEditDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CImageEditDemoDlg)
	enum { IDD = IDD_IMAGEEDITDEMO_DIALOG };
	CImageEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageEditDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImageEditDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITDEMODLG_H__B581EFCD_C9DF_4CF3_A8AB_965FB2A67ED5__INCLUDED_)
