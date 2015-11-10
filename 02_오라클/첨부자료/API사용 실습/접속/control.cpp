//control.cpp

#include "std.h"

BOOL control_Init(HWND hwnd)
{
	// ui ��Ʈ�� �ʱ�ȭ
	ui_InitControl(hwnd);

	// ��ư ��Ʈ�� �ʱ�ȭ
	ui_BtnState(hwnd, TRUE, FALSE, FALSE, FALSE);
	
	// oracle db ����
	if (mydb_DBConnect() == FALSE) 
	{
		MessageBox(hwnd,"������ ���̽��� ������ �� �����ϴ�","����",MB_OK);
		return FALSE;
	}
	return TRUE;
}


void control_CreateTable(HWND hwnd)
{
	if(mydb_CreateTable())
		ui_BtnState(hwnd, FALSE, TRUE, TRUE, FALSE);
	else
	{
		MessageBox(NULL, "���̺��� �����մϴ�.", "�˸�", MB_OK);
		ui_BtnState(hwnd, FALSE, TRUE, FALSE, FALSE);
	}
}


void control_DeleteTable(HWND hwnd)
{
	if(mydb_DeleteTable())
		ui_BtnState(hwnd, TRUE, FALSE, FALSE, FALSE);
	else
		ui_BtnState(hwnd, FALSE, TRUE, FALSE, FALSE);
}

void control_InsertData(HWND hWnd)
{
	for(int i=0; i<DATA_MAX; i++)
		mydb_InsertData( student_GetData(i) );

	ui_BtnState(hWnd, FALSE, TRUE, FALSE, TRUE);

	// ������ ȹ�� ��û
	mydb_SelectData();
}

void control_DeleteData(HWND hwnd)
{
	if(mydb_DeleteData())
	{
		ui_BtnState(hwnd, FALSE, TRUE, FALSE, FALSE);
		ui_Refresh(-1);
	}
	else
		ui_BtnState(hwnd, TRUE, TRUE, TRUE, TRUE);
}

// db ==> control
void control_GetData(int idx, char *name, char *num, char*phoneNumber, char*email )
{
	ui_Refresh(idx, name, num, phoneNumber, email);
}