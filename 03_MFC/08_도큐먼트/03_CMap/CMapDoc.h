// CMapDoc.h : interface of the CCMapDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMAPDOC_H__A114A107_7D22_4960_9374_E22DFF416BB9__INCLUDED_)
#define AFX_CMAPDOC_H__A114A107_7D22_4960_9374_E22DFF416BB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Afxtempl.h"


class CCMapDoc : public CDocument
{
protected: // create from serialization only
	CCMapDoc();
	DECLARE_DYNCREATE(CCMapDoc)

	// 1. Map ¼±¾ð 
	CMap<int, int, CString, CString> map;
	//---------------------------------------

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMapDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCMapDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCMapDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMAPDOC_H__A114A107_7D22_4960_9374_E22DFF416BB9__INCLUDED_)
