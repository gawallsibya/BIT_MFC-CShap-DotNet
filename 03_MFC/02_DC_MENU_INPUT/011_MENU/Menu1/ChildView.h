// ChildView.h

#ifndef _CHILD_VIEW_
#define _CHILD_VIEW_

#include <afxwin.h>

class CChildView : public CWnd
{
public:
	void OnUpdate(CCmdUI* pCmdUI);
	void OnColor(UINT nID);
	void OnPaint();
	COLORREF m_color; // ���� ��Ÿ���� type

	CChildView();
	~CChildView();

	virtual BOOL PreCreateWindow( CREATESTRUCT& cs);

	afx_msg void OnLButtonDown( UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown( UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};

#endif // _CHILD_VIEW_