// VisualKBView.h : interface of the CVisualKBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VISUALKBVIEW_H__EE481D06_2828_483B_B653_533F2329DAD8__INCLUDED_)
#define AFX_VISUALKBVIEW_H__EE481D06_2828_483B_B653_533F2329DAD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_STRINGS 12
class CVisualKBView : public CView
{
protected:
	int	m_cxChar;				// 평균 문자 폭
	int	m_cyChar;				// 평균 문자 높이

	int	m_cyLine;				// 메시지 상자의 수직 줄 간견
	int m_nTextPos;				// 텍스트 상자의 현재 문자 위치
	int	m_nTabStops[7];			// 탭 처리된 출력의 탭 위치 
	int m_nTextLimit;			// 텍스트 상자의 최대 폭
	int m_nMsgPos;				// m_strMessages 배열에서의 현재 위치

	HCURSOR	m_hCursorArrow;		// 화살표 커서의 핸들
	HCURSOR m_hCursorIBeam;		// I- 막대 커서의 핸들

	CPoint	m_ptTextOrigin;		// 입력 텍스트의 그리기 원점
	CPoint	m_ptHeaderOrigin;	// 머리글 텍스트의 그리기 원점
	CPoint	m_ptUpperMsgOrigin;	// 메시지 상자의 첫 줄 원점
	CPoint	m_ptLowerMsgOrigin;	// 메시지 상자의 마지막 줄 원점
	CPoint	m_ptCaretPos;		// 현재 캐럿 위치

	CRect	m_rcTextBox;		// 텍스트 상자의 좌표
	CRect	m_rcTextBoxBorder;	// 텍스트 상자 경계 좌표
	CRect	m_rcMsgBoxBorder;	// 메시지 상자 경계 좌표
	CRect	m_rcScroll;			// 스크롤 사각형 좌표

	CString m_strInputText;				// 입력 테스트
	CString m_strMessages[MAX_STRINGS];	// 메시지 문자열 배열


protected: // create from serialization only
	CVisualKBView();
	DECLARE_DYNCREATE(CVisualKBView)

// Attributes
public:
	CVisualKBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisualKBView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawMessages( CDC *pDC);
	virtual ~CVisualKBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void DrawMessageHeader( CDC *pDC);
	void DrawInputText( CDC *pDC);
	void PositionCaret(CDC *pDC = NULL);
	int GetNearestPos(CPoint point);
	void ShowMessage(LPCTSTR pszMessage, UINT nChar, UINT nRepCnt, UINT nFlags);


	//{{AFX_MSG(CVisualKBView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VisualKBView.cpp
inline CVisualKBDoc* CVisualKBView::GetDocument()
   { return (CVisualKBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISUALKBVIEW_H__EE481D06_2828_483B_B653_533F2329DAD8__INCLUDED_)
