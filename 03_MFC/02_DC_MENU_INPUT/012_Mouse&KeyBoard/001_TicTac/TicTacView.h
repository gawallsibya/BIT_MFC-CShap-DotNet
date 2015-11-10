// TicTacView.h : interface of the CTicTacView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TICTACVIEW_H__A0B032FE_C82A_402F_A9CE_08B8F9B1D0B6__INCLUDED_)
#define AFX_TICTACVIEW_H__A0B032FE_C82A_402F_A9CE_08B8F9B1D0B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define EX	1
#define OH	2

class CTicTacView : public CView
{
public:
	static const	CRect m_rcSquares[9];	// Grid coordinates
	int		m_nGameGrid[9];					// Grid contents
	int		m_nNextChar;					// Next Caracter( EX or OH)
	int		GetRectID( CPoint point);
	void	DrawX(CDC* pDC, int nPos);
	void	DrawO(CDC* pDC, int nPos);
	void	ResetGame();
	void	CheckForGameOver();
	int		IsWinner();
	BOOL	IsDraw();

protected: // create from serialization only
	CTicTacView();
	DECLARE_DYNCREATE(CTicTacView)

// Attributes
public:
	CTicTacDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicTacView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawBoard(CDC *pDC);
	virtual ~CTicTacView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTicTacView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TicTacView.cpp
inline CTicTacDoc* CTicTacView::GetDocument()
   { return (CTicTacDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TICTACVIEW_H__A0B032FE_C82A_402F_A9CE_08B8F9B1D0B6__INCLUDED_)
