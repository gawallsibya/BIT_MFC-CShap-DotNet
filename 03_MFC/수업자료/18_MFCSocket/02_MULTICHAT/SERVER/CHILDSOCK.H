#if !defined(AFX_CHILDSOCK_H__99F4C3E1_5C5B_11D2_93C8_941A6CE10812__INCLUDED_)
#define AFX_CHILDSOCK_H__99F4C3E1_5C5B_11D2_93C8_941A6CE10812__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChildSock.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CChildSock command target

class CChildSock : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CChildSock();
	virtual ~CChildSock();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildSock)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CChildSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDSOCK_H__99F4C3E1_5C5B_11D2_93C8_941A6CE10812__INCLUDED_)
