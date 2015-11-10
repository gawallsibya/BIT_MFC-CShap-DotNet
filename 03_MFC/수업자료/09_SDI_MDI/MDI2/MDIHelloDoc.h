// MDIHelloDoc.h : interface of the CMDIHelloDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDIHELLODOC_H__C4E0BDFD_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
#define AFX_MDIHELLODOC_H__C4E0BDFD_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BLACK	RGB(0x00, 0x00, 0x00)
#define RED		RGB(0xff, 0x00, 0x00)
#define GREEN	RGB(0x00, 0xff, 0x00)
#define BLUE	RGB(0x00, 0x00, 0xff)

class CMDIHelloDoc : public CDocument
{
protected: // create from serialization only
	CMDIHelloDoc();
	DECLARE_DYNCREATE(CMDIHelloDoc)

// Attributes
public:
	void SetData(CString str, CPoint point, COLORREF color);
	CPoint GetMax();
	CString GetText();
	void SetMax(CPoint point);
	void SetColor(COLORREF color);
	COLORREF GetColor();
	void SetLocation(CPoint point);
	CPoint GetLocation();
	void SetNullDataForm()
		{ m_pDataForm = NULL; }
protected:
	CString m_strText;
	CPoint m_nMax;
	COLORREF m_clrCur;
	CPoint m_ptLoc;
	CMDIChildWnd* m_pDataForm;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIHelloDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDIHelloDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDIHelloDoc)
	afx_msg void OnColorBlack();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnViewDataform();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIHELLODOC_H__C4E0BDFD_6D79_11D2_B0B6_0080C7C912B9__INCLUDED_)
