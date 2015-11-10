// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__F9DB2CC5_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_)
#define AFX_MAINFRM_H__F9DB2CC5_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:
	enum ViewType{ FORMVIEW, FONTVIEW, PAINTVIEW }; // 뷰의 종류 설정

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SwitchView(ViewType nType);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFontView();
	afx_msg void OnUpdateFontView(CCmdUI* pCmdUI);
	afx_msg void OnFormView();
	afx_msg void OnUpdateFormView(CCmdUI* pCmdUI);
	afx_msg void OnPaintView();
	afx_msg void OnUpdatePaintView(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__F9DB2CC5_5269_11D2_93C8_CA5AB7097F1E__INCLUDED_)
