// ImageView.h : interface of the CImageView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEVIEW_H__50C34FCC_6E25_4724_B51D_5C33F04C55DA__INCLUDED_)
#define AFX_IMAGEVIEW_H__50C34FCC_6E25_4724_B51D_5C33F04C55DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ImageDoc.h"

class CImageView : public CView
{
protected: // create from serialization only
	CImageView();
	DECLARE_DYNCREATE(CImageView)

// Attributes
public:
	
	HBITMAP m_hBitmap;
	BITMAP  m_bm; // bitmap의 헤더 정보(크기)를 담을 구조체

	CImageDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageView)
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
	void Refresh( CString path );
	virtual ~CImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImageView.cpp
inline CImageDoc* CImageView::GetDocument()
   { return (CImageDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEVIEW_H__50C34FCC_6E25_4724_B51D_5C33F04C55DA__INCLUDED_)
