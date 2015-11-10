// Paint1View.h : interface of the CPaint1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAINT1VIEW_H__879568CE_0E3B_4E93_B0F3_80F4405806A3__INCLUDED_)
#define AFX_PAINT1VIEW_H__879568CE_0E3B_4E93_B0F3_80F4405806A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPaint1View : public CView
{
protected: // create from serialization only
	CPaint1View();
	DECLARE_DYNCREATE(CPaint1View)

// Attributes
public:
	CPoint	m_nowPoint;	// 마우스 커서 눌러진 좌표 저장
	CPoint	m_OldPoint;
	int		m_SelectTool;
	CPaint1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaint1View)
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
	virtual ~CPaint1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPaint1View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg void OnShape(UINT nID);
	afx_msg void OnUpdateShape(CCmdUI *pCmdUI);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Paint1View.cpp
inline CPaint1Doc* CPaint1View::GetDocument()
   { return (CPaint1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINT1VIEW_H__879568CE_0E3B_4E93_B0F3_80F4405806A3__INCLUDED_)
