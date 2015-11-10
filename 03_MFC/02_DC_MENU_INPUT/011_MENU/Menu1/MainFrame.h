// MainFrame.h

#ifndef _MAIN_FRAME_
#define _MAIN_FRAME_

#include <afxwin.h>
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
public:
	// Doc/View�� ������� ������ View���� �޴��� ó���Ҽ� �ְ�
	// �ϴ� ���.
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