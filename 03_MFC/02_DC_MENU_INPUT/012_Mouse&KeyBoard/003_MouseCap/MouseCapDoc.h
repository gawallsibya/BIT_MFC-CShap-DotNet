// MouseCapDoc.h : interface of the CMouseCapDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSECAPDOC_H__24C7EE36_CCDF_45F0_935C_8CCBF2A80244__INCLUDED_)
#define AFX_MOUSECAPDOC_H__24C7EE36_CCDF_45F0_935C_8CCBF2A80244__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMouseCapDoc : public CDocument
{
protected: // create from serialization only
	CMouseCapDoc();
	DECLARE_DYNCREATE(CMouseCapDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseCapDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMouseCapDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMouseCapDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSECAPDOC_H__24C7EE36_CCDF_45F0_935C_8CCBF2A80244__INCLUDED_)
