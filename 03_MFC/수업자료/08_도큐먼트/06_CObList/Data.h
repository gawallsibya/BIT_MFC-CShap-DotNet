#if !defined(AFX_DATA_H__18E2C1A0_B1F4_4067_BBCA_D384012FB64A__INCLUDED_)
#define AFX_DATA_H__18E2C1A0_B1F4_4067_BBCA_D384012FB64A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Data.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CData command target

class CData : public CObject
{
// Attributes
public:
	CPoint		m_ptHead;
	CPoint		m_ptTail;
	int			m_nType;
	COLORREF	m_colorPen;
	COLORREF	m_colorBrush;

// Operations
public:
	CData();
	virtual ~CData();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CData)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CData)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATA_H__18E2C1A0_B1F4_4067_BBCA_D384012FB64A__INCLUDED_)
