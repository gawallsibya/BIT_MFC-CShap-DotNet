// SeriDoc.h : interface of the CSeriDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIDOC_H__051E87B9_363D_483B_8788_AFDA93943DEC__INCLUDED_)
#define AFX_SERIDOC_H__051E87B9_363D_483B_8788_AFDA93943DEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSeriDoc : public CDocument
{
protected: // create from serialization only
	CSeriDoc();
	DECLARE_DYNCREATE(CSeriDoc)

// Attributes
public:
	CObList		m_List;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeriDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSeriDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSeriDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIDOC_H__051E87B9_363D_483B_8788_AFDA93943DEC__INCLUDED_)
