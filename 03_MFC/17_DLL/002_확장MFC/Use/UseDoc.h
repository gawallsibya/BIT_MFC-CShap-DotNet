// UseDoc.h : interface of the CUseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEDOC_H__1F6BB647_266B_469A_874F_4299A1DC6E47__INCLUDED_)
#define AFX_USEDOC_H__1F6BB647_266B_469A_874F_4299A1DC6E47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUseDoc : public CDocument
{
protected: // create from serialization only
	CUseDoc();
	DECLARE_DYNCREATE(CUseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEDOC_H__1F6BB647_266B_469A_874F_4299A1DC6E47__INCLUDED_)
