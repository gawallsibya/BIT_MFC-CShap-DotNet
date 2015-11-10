// TicTacView.h : interface of the CTicTacView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TICTACVIEW_H__A0B032FE_C82A_402F_A9CE_08B8F9B1D0B6__INCLUDED_)
#define AFX_TICTACVIEW_H__A0B032FE_C82A_402F_A9CE_08B8F9B1D0B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include "MyTic.h"

class CTicTacView : public CFormView
{
private:
	CMyTic *m_pTic;
	bool	m_bGameStart;
	int		m_count;

public:

protected: // create from serialization only
	CTicTacView();
	DECLARE_DYNCREATE(CTicTacView)

// Attributes
public:
	CTicTacDoc* GetDocument();

public:
	//{{AFX_DATA(CAAAAView)
	enum{ IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTicTacView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL

// Implementation
public:
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
	afx_msg void OnGameStart();
	afx_msg void OnGameEnd();
	afx_msg void OnUpdateGameStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGameEnd(CCmdUI* pCmdUI);
	afx_msg void OnGameOne();
	afx_msg void OnGameThree();
	afx_msg void OnGameFive();
	afx_msg void OnTimer(UINT nIDEvent);
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
