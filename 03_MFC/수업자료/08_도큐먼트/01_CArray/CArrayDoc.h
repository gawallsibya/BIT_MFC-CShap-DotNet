// CArrayDoc.h : interface of the CCArrayDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARRAYDOC_H__1D899B53_379B_4318_AC4E_0C15E7FBC650__INCLUDED_)
#define AFX_CARRAYDOC_H__1D899B53_379B_4318_AC4E_0C15E7FBC650__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "Afxtempl.h"			// stdafx.h에 추가 		

class CCArrayDoc : public CDocument
{
protected: // create from serialization only
	CCArrayDoc();
	DECLARE_DYNCREATE(CCArrayDoc)


	// 2. CArray 선언 ---------------------------------------

	CArray<CPoint, CPoint> arr;

	//--------------------------------------------------------

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArrayDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCArrayDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCArrayDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAYDOC_H__1D899B53_379B_4318_AC4E_0C15E7FBC650__INCLUDED_)
