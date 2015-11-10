#if !defined(AFX_CONNECTDLG_H__99F4C3F7_5C5B_11D2_93C8_941A6CE10812__INCLUDED_)
#define AFX_CONNECTDLG_H__99F4C3F7_5C5B_11D2_93C8_941A6CE10812__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConnectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConnectDlg dialog
#include "RoundButton.h"
class CConnectDlg : public CDialog
{
// Construction
public:
	CConnectDlg(CWnd* pParent = NULL);   // standard constructor
	CString  m_strAddress;

// Dialog Data
	//{{AFX_DATA(CConnectDlg)
	enum { IDD = IDD_CONNECT_DLG };
	CRoundButton	m_Ok;
	CRoundButton	m_Cancel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConnectDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTDLG_H__99F4C3F7_5C5B_11D2_93C8_941A6CE10812__INCLUDED_)
