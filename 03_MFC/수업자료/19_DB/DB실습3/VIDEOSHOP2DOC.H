// VideoShop2Doc.h : interface of the CVideoShop2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOSHOP2DOC_H__83BD48AB_399B_11D2_941F_006097DCA739__INCLUDED_)
#define AFX_VIDEOSHOP2DOC_H__83BD48AB_399B_11D2_941F_006097DCA739__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "VideoShop2Set.h"

class CVideoShop2Doc : public CDocument
{
protected: // create from serialization only
	CVideoShop2Doc();
	DECLARE_DYNCREATE(CVideoShop2Doc)

// Attributes
public:
	CVideoShop2Set* m_videoShop2Set;
	CDatabase m_DB;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoShop2Doc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVideoShop2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVideoShop2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOSHOP2DOC_H__83BD48AB_399B_11D2_941F_006097DCA739__INCLUDED_)
