// MultiLookView.h : interface of the CMultiLookView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTILOOKVIEW_H__F9DB2CC9_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_)
#define AFX_MULTILOOKVIEW_H__F9DB2CC9_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiLookView : public CFormView
{
public: // create from serialization only
	CMultiLookView();
	DECLARE_DYNCREATE(CMultiLookView)

public:
	//{{AFX_DATA(CMultiLookView)
	enum { IDD = IDD_MULTILOOK_FORM };
	//}}AFX_DATA

// Attributes
public:
	CMultiLookDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiLookView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitRichEdit();
	void SetTailFormat(CHARFORMAT& cf, PARAFORMAT& pf);
	void SetHeadFormat(CHARFORMAT& cf);
	virtual ~CMultiLookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiLookView)
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiLookView.cpp
inline CMultiLookDoc* CMultiLookView::GetDocument()
   { return (CMultiLookDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTILOOKVIEW_H__F9DB2CC9_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_)
