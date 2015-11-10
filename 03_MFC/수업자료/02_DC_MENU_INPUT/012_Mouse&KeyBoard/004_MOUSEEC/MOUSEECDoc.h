// MOUSEECDoc.h : interface of the CMOUSEECDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSEECDOC_H__0D2C9DB8_E1A4_4FF6_9A98_AB39A1E54162__INCLUDED_)
#define AFX_MOUSEECDOC_H__0D2C9DB8_E1A4_4FF6_9A98_AB39A1E54162__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMOUSEECDoc : public CDocument
{
protected: // create from serialization only
	CMOUSEECDoc();
	DECLARE_DYNCREATE(CMOUSEECDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMOUSEECDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMOUSEECDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMOUSEECDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEECDOC_H__0D2C9DB8_E1A4_4FF6_9A98_AB39A1E54162__INCLUDED_)
