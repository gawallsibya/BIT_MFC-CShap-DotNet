// SampleDoc.h : interface of the CSampleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAMPLEDOC_H__A2B52B05_F9C0_41FA_A681_ABEDEAA0D837__INCLUDED_)
#define AFX_SAMPLEDOC_H__A2B52B05_F9C0_41FA_A681_ABEDEAA0D837__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

class CSampleDoc : public CDocument
{
protected: // create from serialization only
	CSampleDoc();
	DECLARE_DYNCREATE(CSampleDoc)

// Attributes
public:
		
	CArray<CRect, CRect> buf;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSampleDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEDOC_H__A2B52B05_F9C0_41FA_A681_ABEDEAA0D837__INCLUDED_)
