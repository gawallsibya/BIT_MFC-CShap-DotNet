// CListDoc.h : interface of the CCListDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLISTDOC_H__D18469D7_475B_454E_9B33_132C84F3A4D2__INCLUDED_)
#define AFX_CLISTDOC_H__D18469D7_475B_454E_9B33_132C84F3A4D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCListDoc : public CDocument
{
protected: // create from serialization only
	CCListDoc();
	DECLARE_DYNCREATE(CCListDoc)

	CList<CPoint, CPoint&> list;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCListDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCListDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCListDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLISTDOC_H__D18469D7_475B_454E_9B33_132C84F3A4D2__INCLUDED_)
