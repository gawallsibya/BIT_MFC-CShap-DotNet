//ui.cpp
#include "std.h"

void ui_InitControl(HWND hwnd)
{
	listView = new CtrListView( GetDlgItem( hwnd, IDC_LIST1 ) );

	listView->AddHead( "이름" );
	listView->AddHead( "학번" );
	listView->AddHead( "전화번호" );
	listView->AddHead( "이메일" );	
}

void ui_BtnState(HWND hWnd, BOOL fCTable, BOOL fDTable, BOOL DataInsert, BOOL DataDel)
{
	HWND hCTable	= GetDlgItem(hWnd, IDC_CTABLE);
	HWND hDTable	= GetDlgItem(hWnd, IDC_DTABLE);
	HWND hDInsert	= GetDlgItem(hWnd, IDC_TINSERT);
	HWND hDDelete	= GetDlgItem(hWnd, IDC_TDEL);

	EnableWindow(hCTable, fCTable);
	EnableWindow(hDTable, fDTable);
	EnableWindow(hDInsert, DataInsert);
	EnableWindow(hDDelete, DataDel);
}

void ui_Refresh(int idx, char*name, char*num, char*phoneNumber, char*email)
{
	if( idx == 0 )
		listView->RmoveAllList();
	else if( idx == -1)
	{
		listView->RmoveAllList();
		return;
	}
	
	listView->ShowListView(idx,0,name);
	listView->ShowListView(idx,1,num);
	listView->ShowListView(idx,2,phoneNumber);
	listView->ShowListView(idx,3,email);	
}