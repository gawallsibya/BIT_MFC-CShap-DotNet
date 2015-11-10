// IPCDoc.h : interface of the CIPCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPCDOC_H__441082AB_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_)
#define AFX_IPCDOC_H__441082AB_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIPCDoc : public CDocument
{
protected: // create from serialization only
	CIPCDoc();
	DECLARE_DYNCREATE(CIPCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIPCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIPCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CIPCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IPCDOC_H__441082AB_3426_11D2_93C8_C3FEBEB1A81C__INCLUDED_)
