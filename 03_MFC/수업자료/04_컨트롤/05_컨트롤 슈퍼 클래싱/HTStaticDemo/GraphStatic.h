#if !defined(AFX_GRAPHSTATIC_H__525F429F_82C1_42DB_83E0_9A8341AE167F__INCLUDED_)
#define AFX_GRAPHSTATIC_H__525F429F_82C1_42DB_83E0_9A8341AE167F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GraphStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGraphStatic window

class CGraphStatic : public CStatic
{
// Construction
public:
	CGraphStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetData(int nNewData);
	int			m_nData;
	virtual ~CGraphStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CGraphStatic)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHSTATIC_H__525F429F_82C1_42DB_83E0_9A8341AE167F__INCLUDED_)
