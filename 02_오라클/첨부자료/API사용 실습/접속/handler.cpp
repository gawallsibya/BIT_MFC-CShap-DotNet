//handler.cpp

#include "std.h"

DWORD OnInitDialog( HWND hWnd )
{
	if(control_Init(hWnd))
		return TRUE;
	return FALSE;	
}


DWORD OnCommand( HWND hWnd, WORD conID, WORD msg )
{
	switch( conID )
	{
	case IDC_CTABLE:	control_CreateTable(hWnd);  break;
	case IDC_DTABLE :   control_DeleteTable(hWnd);  break;
	case IDC_TINSERT :	control_InsertData(hWnd);	break;
	case IDC_TDEL : 	control_DeleteData(hWnd);	break;
	case IDCANCEL:
		EndDialog( hWnd, IDCANCEL );
		break;
	}

	return TRUE;
}