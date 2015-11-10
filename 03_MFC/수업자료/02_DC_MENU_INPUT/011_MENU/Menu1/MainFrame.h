// MainFrame.h

#ifndef _MAIN_FRAME_
#define _MAIN_FRAME_

#include <afxwin.h>
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
public:
	// Doc/View를 사용하지 않은때 View에서 메뉴을 처리할수 있게
	// 하는 방법.
	virtual BOOL OnCmdMsg( UINT nID, int nCode, 
						   void* pExtra, 
						   AFX_CMDHANDLERINFO* pHandlerInfo );

	void OnExit();
	CChildView m_wndView;

	CMainFrame();
	~CMainFrame();

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg int OnCreate(LPCREATESTRUCT lpc);
	afx_msg void OnSetFocus(CWnd* );

	DECLARE_MESSAGE_MAP()
};
#endif // _MAIN_FRAME_