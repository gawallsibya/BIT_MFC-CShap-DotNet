
// 0325.h : 0325 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy0325App:
// �� Ŭ������ ������ ���ؼ��� 0325.cpp�� �����Ͻʽÿ�.
//

class CMy0325App : public CWinApp
{
public:
	CMy0325App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
	void App_foo(int num, int num1);
};

extern CMy0325App theApp;
