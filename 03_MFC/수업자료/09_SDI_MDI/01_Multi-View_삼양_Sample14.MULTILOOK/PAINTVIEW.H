#if !defined(AFX_PAINTVIEW_H__AF617302_5403_11D2_93C8_F33CC61341A6__INCLUDED_)
#define AFX_PAINTVIEW_H__AF617302_5403_11D2_93C8_F33CC61341A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaintView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaintView view
class CPaintView : public CScrollView
{
public:
	CPaintView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPaintView)

// Attributes
public:

// Operations
public:
	CPoint m_start; // 시작 위치 저장
	CPtrArray m_ptArray; // 점(위치)이 저장되는 배열 
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPaintView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTVIEW_H__AF617302_5403_11D2_93C8_F33CC61341A6__INCLUDED_)
