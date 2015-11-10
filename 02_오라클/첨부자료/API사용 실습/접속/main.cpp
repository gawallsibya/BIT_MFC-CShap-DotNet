//main.cpp
#include "std.h"


CtrListView* listView;


BOOL CALLBACK DlgProc( HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam )
{
	switch( iMsg )
	{
	case WM_INITDIALOG:			return OnInitDialog( hWnd );
	case WM_COMMAND:			return OnCommand( hWnd, LOWORD( wParam ), HIWORD( wParam) );	
	}
	return FALSE;
}


INT APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{
	DialogBox( hInst, MAKEINTRESOURCE(IDD_DIALOG1), HWND_DESKTOP, DlgProc );
	return 0;
}







