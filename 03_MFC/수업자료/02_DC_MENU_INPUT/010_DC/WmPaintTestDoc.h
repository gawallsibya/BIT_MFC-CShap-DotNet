// WmPaintTestDoc.h : interface of the CWmPaintTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WMPAINTTESTDOC_H__13A28044_C9A7_4A36_9A30_AADC2E23B992__INCLUDED_)
#define AFX_WMPAINTTESTDOC_H__13A28044_C9A7_4A36_9A30_AADC2E23B992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWmPaintTestDoc : public CDocument
{
protected: // create from serialization only
	CWmPaintTestDoc();
	DECLARE_DYNCREATE(CWmPaintTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWmPaintTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWmPaintTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWmPaintTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPAINTTESTDOC_H__13A28044_C9A7_4A36_9A30_AADC2E23B992__INCLUDED_)
