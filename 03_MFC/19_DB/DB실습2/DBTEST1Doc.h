// DBTEST1Doc.h : interface of the CDBTEST1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBTEST1DOC_H__B8CE82F7_3FC4_401F_B17F_FF6094F81EF7__INCLUDED_)
#define AFX_DBTEST1DOC_H__B8CE82F7_3FC4_401F_B17F_FF6094F81EF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "DBTEST1Set.h"


class CDBTEST1Doc : public CDocument
{
protected: // create from serialization only
	CDBTEST1Doc();
	DECLARE_DYNCREATE(CDBTEST1Doc)

// Attributes
public:
	CDBTEST1Set m_dBTEST1Set;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBTEST1Doc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDBTEST1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBTEST1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBTEST1DOC_H__B8CE82F7_3FC4_401F_B17F_FF6094F81EF7__INCLUDED_)
