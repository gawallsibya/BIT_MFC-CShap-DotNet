#pragma once

#include <windows.h>
#include <commctrl.h>

#pragma comment(lib,"comctl32")

class CtrListView
{
	HWND hList;

	LVCOLUMN headList;
	int headUsage;
	LVITEM item;

public:
	CtrListView( HWND hList );
	virtual ~CtrListView(void);

	int GetHeadUsage()const;
	void AddHead(const char* hName);
	void ShowListView(int iItem, int subtem, const char* str);
	void RmoveAllList();
};
