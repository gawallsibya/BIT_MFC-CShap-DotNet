#if !defined(AFX_MAPDIALOG_H__D27CB328_7993_4E3D_9EF3_9DEDEDC98745__INCLUDED_)
#define AFX_MAPDIALOG_H__D27CB328_7993_4E3D_9EF3_9DEDEDC98745__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MapDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMapDialog dialog

class CMapDialog : public CDialog
{
// Construction
public:
	CMapDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMapDialog)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_ctrlEdit;
	CListBox	m_ctrlList;
	CString	m_editStr;
	CString	m_listStr;
	//}}AFX_DATA
	CString m_strSelected[10];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMapDialog)
	afx_msg void OnAdd();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPDIALOG_H__D27CB328_7993_4E3D_9EF3_9DEDEDC98745__INCLUDED_)
