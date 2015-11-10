#if !defined(AFX_MOVINGGRAPH_H__6286DB93_F8E0_11D4_AD1C_00A024695220__INCLUDED_)
#define AFX_MOVINGGRAPH_H__6286DB93_F8E0_11D4_AD1C_00A024695220__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MovingGraph.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMovingGraph window

class CMovingGraph : public CStatic
{
// Construction
public:
	CMovingGraph();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMovingGraph)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetBackBitmap( UINT nBackBmpID );
	void DrawPoint( unsigned short nPoint);
	void SetLineColor(COLORREF col ){	m_lineColor = col;}
	void SetLimitColor(COLORREF col ){	m_limitColor = col;}
	virtual ~CMovingGraph();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMovingGraph)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CPoint m_oldPoint;	
	BOOL m_bFirst;
	unsigned short m_nDX;
	UINT m_nOffset;
	CDC m_drawDC;
	CDC m_backDC;
	COLORREF m_limitColor;
	COLORREF m_lineColor;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVINGGRAPH_H__6286DB93_F8E0_11D4_AD1C_00A024695220__INCLUDED_)
