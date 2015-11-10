// ChildView.h

#ifndef _CHILD_VIEW_
#define _CHILD_VIEW_

#include <afxwin.h>
#include <afxtempl.h> // MFC 의 template class 사용하기.

class CChildView : public CWnd
{
public:
	CArray<CPoint, CPoint> m_buf;

	void OnPaint();
	CChildView();
	~CChildView();

	virtual BOOL PreCreateWindow( CREATESTRUCT& cs);

	afx_msg void OnLButtonDown( UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown( UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};

#endif // _CHILD_VIEW_