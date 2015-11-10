// ImageDoc.h : interface of the CImageDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEDOC_H__8FDEA8C7_EBED_453A_B7D9_030F1AE9CB82__INCLUDED_)
#define AFX_IMAGEDOC_H__8FDEA8C7_EBED_453A_B7D9_030F1AE9CB82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImageDoc : public CDocument
{
protected: // create from serialization only
	CImageDoc();
	DECLARE_DYNCREATE(CImageDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEDOC_H__8FDEA8C7_EBED_453A_B7D9_030F1AE9CB82__INCLUDED_)
