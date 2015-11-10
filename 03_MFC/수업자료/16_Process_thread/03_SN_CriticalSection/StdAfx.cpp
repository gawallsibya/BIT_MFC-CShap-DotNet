// stdafx.cpp : source file that includes just the standard includes
//	CriticalSectionDemo.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

//ũ��Ƽ�� ����
CCriticalSection	g_CS;
char* g_pszBuffer = NULL;


//�޸𸮸� �����ϰ� �ٽ� �Ҵ���� ��, ���ڿ��� �ִ� �Լ�.
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

//���ڿ��� �о�� �� �޸𸮸� �����ϴ� �Լ�.
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
