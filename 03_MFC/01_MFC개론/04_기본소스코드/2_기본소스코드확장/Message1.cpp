// Message1 : MFC Message Map Macro ����ϱ�.

#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point)
	{
		MessageBox("LButton");
	}

	DECLARE_MESSAGE_MAP()
};


BEGIN_MESSAGE_MAP( CMainFrame, CFrameWnd )

ON_WM_LBUTTONDOWN()

END_MESSAGE_MAP()


//////////////////////////////////////////////

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		CMainFrame* pFrame = new CMainFrame;

		pFrame->Create(0, "Message");
		pFrame->ShowWindow( SW_SHOW );
		pFrame->UpdateWindow( );

		m_pMainWnd = pFrame;

		return TRUE;
	}
};

CMyApp theApp;
