// stdafx.cpp : source file that includes just the standard includes
//	CriticalSectionDemo.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

//크리티컬 섹션
CCriticalSection	g_CS;
char* g_pszBuffer = NULL;


//메모리를 해제하고 다시 할당받은 후, 문자열을 넣는 함수.
void SetString(char* pszData)
{
	g_CS.Lock();
	if(g_pszBuffer != NULL)
	{
		free(g_pszBuffer);
		g_pszBuffer = (char*)malloc(64);
		::Sleep(1);
		sprintf(g_pszBuffer, "%s", pszData);
	}
	else
	{
		g_pszBuffer = (char*)malloc(64);
		::Sleep(1);
		sprintf(g_pszBuffer, "%s", pszData);
	}
	g_CS.Unlock();
}

//문자열을 읽어온 후 메모리를 해제하는 함수.
BOOL GetString(char* pszData)
{
	g_CS.Lock();
	if(pszData != NULL)
	{
		sprintf(pszData, "%s", g_pszBuffer);
		free(g_pszBuffer);
		g_pszBuffer = NULL;

		g_CS.Unlock();
		return TRUE;
	}

	g_CS.Unlock();
	return FALSE;
}

UINT ThreadFunc1(LPVOID pParam)
{
	while(TRUE)
	{
		::Sleep(1);
		SetString("ThreadFunc1");
	}

	return 0;
}

UINT ThreadFunc2(LPVOID pParam)
{
	while(TRUE)
	{
		::Sleep(1);
		SetString("ThreadFunc2");
	}

	return 0;
}
