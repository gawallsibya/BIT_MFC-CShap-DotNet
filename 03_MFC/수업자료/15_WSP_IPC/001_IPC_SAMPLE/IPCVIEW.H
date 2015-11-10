// IPCView.h : interface of the CIPCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPCVIEW_H__441082AD_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_)
#define AFX_IPCVIEW_H__441082AD_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_MY_MSG   WM_USER+7 // 사용자 정의 메시지

class CIPCView : public CFormView
{
protected: // create from serialization only
	CIPCView();
	DECLARE_DYNCREATE(CIPCView)

public:
	//{{AFX_DATA(CIPCView)
	enum{ IDD = IDD_IPC_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CIPCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIPCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIPCView)
	afx_msg void OnCopyData();
	afx_msg void OnUserMsg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in IPCView.cpp
inline CIPCDoc* CIPCView::GetDocument()
   { return (CIPCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCVIEW_H__441082AD_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_)
