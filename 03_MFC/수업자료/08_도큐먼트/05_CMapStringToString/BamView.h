// BamView.h : interface of the CBamView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BAMVIEW_H__1F69E271_48D1_4D89_AEC8_19DE4DA888F7__INCLUDED_)
#define AFX_BAMVIEW_H__1F69E271_48D1_4D89_AEC8_19DE4DA888F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DlgFind.h"
#include "DlgAdd.h"

class CBamView : public CView
{
protected: // create from serialization only
	CBamView();
	DECLARE_DYNCREATE(CBamView)

// Attributes
public:
	CBamDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBamView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void AddData(CString key, CString val);
	CString FindVal(CString key);
	virtual ~CBamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CString m_strKey;
	CString m_strVal;

	CMapStringToString mapBook;

	//{{AFX_MSG(CBamView)
	afx_msg void OnPhoneFind();
	afx_msg void OnPhoneAdd();
	afx_msg void OnPhoneShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BamView.cpp
inline CBamDoc* CBamView::GetDocument()
   { return (CBamDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAMVIEW_H__1F69E271_48D1_4D89_AEC8_19DE4DA888F7__INCLUDED_)
