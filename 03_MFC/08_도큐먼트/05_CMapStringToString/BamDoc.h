// BamDoc.h : interface of the CBamDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BAMDOC_H__28FE2079_7E84_4837_83A4_AA635ED3D728__INCLUDED_)
#define AFX_BAMDOC_H__28FE2079_7E84_4837_83A4_AA635ED3D728__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBamDoc : public CDocument
{
protected: // create from serialization only
	CBamDoc();
	DECLARE_DYNCREATE(CBamDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBamDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBamDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAMDOC_H__28FE2079_7E84_4837_83A4_AA635ED3D728__INCLUDED_)
