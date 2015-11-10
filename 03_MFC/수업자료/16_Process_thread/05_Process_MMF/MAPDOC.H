// MapDoc.h : interface of the CMapDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPDOC_H__12CA386B_545D_11D2_A843_00A02486730F__INCLUDED_)
#define AFX_MAPDOC_H__12CA386B_545D_11D2_A843_00A02486730F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMapDoc : public CDocument
{
protected: // create from serialization only
	CMapDoc();
	DECLARE_DYNCREATE(CMapDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMapDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMapDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPDOC_H__12CA386B_545D_11D2_A843_00A02486730F__INCLUDED_)
