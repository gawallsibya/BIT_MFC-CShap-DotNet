// VisualKBView.h : interface of the CVisualKBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VISUALKBVIEW_H__EE481D06_2828_483B_B653_533F2329DAD8__INCLUDED_)
#define AFX_VISUALKBVIEW_H__EE481D06_2828_483B_B653_533F2329DAD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_STRINGS 12
class CVisualKBView : public CView
{
protected:
	int	m_cxChar;				// ��� ���� ��
	int	m_cyChar;				// ��� ���� ����

	int	m_cyLine;				// �޽��� ������ ���� �� ����
	int m_nTextPos;				// �ؽ�Ʈ ������ ���� ���� ��ġ
	int	m_nTabStops[7];			// �� ó���� ����� �� ��ġ 
	int m_nTextLimit;			// �ؽ�Ʈ ������ �ִ� ��
	int m_nMsgPos;				// m_strMessages �迭������ ���� ��ġ

	HCURSOR	m_hCursorArrow;		// ȭ��ǥ Ŀ���� �ڵ�
	HCURSOR m_hCursorIBeam;		// I- ���� Ŀ���� �ڵ�

	CPoint	m_ptTextOrigin;		// �Է� �ؽ�Ʈ�� �׸��� ����
	CPoint	m_ptHeaderOrigin;	// �Ӹ��� �ؽ�Ʈ�� �׸��� ����
	CPoint	m_ptUpperMsgOrigin;	// �޽��� ������ ù �� ����
	CPoint	m_ptLowerMsgOrigin;	// �޽��� ������ ������ �� ����
	CPoint	m_ptCaretPos;		// ���� ĳ�� ��ġ

	CRect	m_rcTextBox;		// �ؽ�Ʈ ������ ��ǥ
	CRect	m_rcTextBoxBorder;	// �ؽ�Ʈ ���� ��� ��ǥ
	CRect	m_rcMsgBoxBorder;	// �޽��� ���� ��� ��ǥ
	CRect	m_rcScroll;			// ��ũ�� �簢�� ��ǥ

	CString m_strInputText;				// �Է� �׽�Ʈ
	CString m_strMessages[MAX_STRINGS];	// �޽��� ���ڿ� �迭


protected: // create from serialization only
	CVisualKBView();
	DECLARE_DYNCREATE(CVisualKBView)

// Attributes
public:
	CVisualKBDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisualKBView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawMessages( CDC *pDC);
	virtual ~CVisualKBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	void DrawMessageHeader( CDC *pDC);
	void DrawInputText( CDC *pDC);
	void PositionCaret(CDC *pDC = NULL);
	int GetNearestPos(CPoint point);
	void ShowMessage(LPCTSTR pszMessage, UINT nChar, UINT nRepCnt, UINT nFlags);


	//{{AFX_MSG(CVisualKBView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VisualKBView.cpp
inline CVisualKBDoc* CVisualKBView::GetDocument()
   { return (CVisualKBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISUALKBVIEW_H__EE481D06_2828_483B_B653_533F2329DAD8__INCLUDED_)
