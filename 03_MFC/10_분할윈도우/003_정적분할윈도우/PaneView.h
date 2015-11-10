#if !defined(AFX_PANEVIEW_H__E70ACAA9_0A4E_48EA_9CFD_332F478CC761__INCLUDED_)
#define AFX_PANEVIEW_H__E70ACAA9_0A4E_48EA_9CFD_332F478CC761__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaneView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaneView view

#include "SampleDoc.h"

class CPaneView : public CView
{
protected:
	CPaneView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPaneView)

// Attributes
public:

// Operations
public:
	CSampleDoc* GetDocument();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaneView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPaneView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CPaneView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PANEVIEW_H__E70ACAA9_0A4E_48EA_9CFD_332F478CC761__INCLUDED_)
