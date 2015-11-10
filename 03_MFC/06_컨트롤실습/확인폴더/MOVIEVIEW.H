// MovieView.h : interface of the CMovieView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVIEVIEW_H__E4F05BAE_0857_11D2_B6E8_B785B166E236__INCLUDED_)
#define AFX_MOVIEVIEW_H__E4F05BAE_0857_11D2_B6E8_B785B166E236__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "PixelDlg.h"

class CMovieView : public CFormView
{
protected: // create from serialization only
	CMovieView();
	DECLARE_DYNCREATE(CMovieView)

public:
	//{{AFX_DATA(CMovieView)
	enum{ IDD = IDD_MOVIE_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CMovieDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMovieView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnProperties();
	virtual ~CMovieView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CPixelDlg* m_pDlg; // 모덜리스 다이얼로그 객체의 포인터
	//{{AFX_MSG(CMovieView)
	afx_msg void OnFormModal();
	afx_msg void OnFormModeless();
	afx_msg void OnFormProperty();
	afx_msg void OnFormWizard();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MovieView.cpp
inline CMovieDoc* CMovieView::GetDocument()
   { return (CMovieDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVIEVIEW_H__E4F05BAE_0857_11D2_B6E8_B785B166E236__INCLUDED_)
