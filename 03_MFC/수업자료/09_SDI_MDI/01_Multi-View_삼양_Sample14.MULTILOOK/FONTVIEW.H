#if !defined(AFX_FONTVIEW_H__AF617301_5403_11D2_93C8_F33CC61341A6__INCLUDED_)
#define AFX_FONTVIEW_H__AF617301_5403_11D2_93C8_F33CC61341A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FontView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFontView view

class CFontView : public CView
{
public:
	CFontView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFontView)

// Attributes
public:
	LOGFONT  m_lf; // 논리 글꼴 구조체
	COLORREF m_color; // 글자 색상
	CString  m_strFaceName; // 글꼴 이름 
	int      m_nFontSize; // 글꼴 크기
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFontView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CFontView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTVIEW_H__AF617301_5403_11D2_93C8_F33CC61341A6__INCLUDED_)
