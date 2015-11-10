// testDoc.h : interface of the CTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTDOC_H__B2C9545D_F992_4E54_B954_1FC02D4243D8__INCLUDED_)
#define AFX_TESTDOC_H__B2C9545D_F992_4E54_B954_1FC02D4243D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "data.h"
class CTestDoc : public CDocument
{
protected: // create from serialization only
	CTestDoc();
	DECLARE_DYNCREATE(CTestDoc)

// Attributes
public:

// Operations
public:
	CData arr[100];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDOC_H__B2C9545D_F992_4E54_B954_1FC02D4243D8__INCLUDED_)
