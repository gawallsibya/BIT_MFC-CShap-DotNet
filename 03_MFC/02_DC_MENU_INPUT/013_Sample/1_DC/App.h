// App.h
#ifndef _APP_
#define _APP_

#include <afxwin.h>

class CMyApp : public CWinApp
{
public:
	CMyApp();
	~CMyApp();

	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

#endif // _APP_
