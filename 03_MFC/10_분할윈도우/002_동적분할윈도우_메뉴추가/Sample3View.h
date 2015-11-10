// Sample3View.h : interface of the CSample3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLE3VIEW_H__7D132E81_B59F_4B55_906F_5E84C121DC31__INCLUDED_)
#define AFX_SAMPLE3VIEW_H__7D132E81_B59F_4B55_906F_5E84C121DC31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSample3View : public CView
{
protected: // create from serialization only
	CSample3View();
	DECLARE_DYNCREATE(CSample3View)

// Attributes
public:
	CSample3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSample3View)
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
	virtual ~CSample3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSample3View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Sample3View.cpp
inline CSample3Doc* CSample3View::GetDocument()
   { return (CSample3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLE3VIEW_H__7D132E81_B59F_4B55_906F_5E84C121DC31__INCLUDED_)
