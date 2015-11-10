// MainFrame.h

#ifndef _MAIN_FRAME_
#define _MAIN_FRAME_

#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
	~CMainFrame();

	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	DECLARE_MESSAGE_MAP()
};
#endif // _MAIN_FRAME_