// Single.h : main header file for the SINGLE application
//

#if !defined(AFX_SINGLE_H__EEBFAD37_69C5_42F3_8357_27F66F9148CE__INCLUDED_)
#define AFX_SINGLE_H__EEBFAD37_69C5_42F3_8357_27F66F9148CE__INCLUDED_				
/*
(1) ��� �ߺ� ����(Ư���� ���ڿ��� ���� ��������.)
    - Ư���� ���ڿ��� �ߺ��� Ȯ���� ���� 0�̴�. ���� �̹� �����ϴ� �ٸ� ����� 
	  �Ͱ� �ߺ����� ����
*/



#if _MSC_VER > 1000																	
/*
(2) Microsoft C++�� �� ������ ���� �����Ѵ�.
���� ���������� ��� ������ �ѹ��� �����ϴ� ����� �������� �ʾҴ�.
*/


#pragma once					
/*
(3) ����� ��ũ ���� �߿� �� ���� ���Ե� ���� �����Ѵ�.
    �� �ѹ��� ���� ��ġ     
*/


#endif // _MSC_VER > 1000



#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSingleApp:
// See Single.cpp for the implementation of this class
//



/*
(4) MFC�������α׷��� CwinApp�� ��ӹ޾� �����Ѵ�.
    CwinApp�� ���� Ŭ������ CcmdTarget�� �ִٴ� �Ϳ� ��������.
    (CwinApp�� ������ �޽����� ���� �� �ִٴ� ���� �ǹ��Ѵ�.)

    CSingleApp Ŭ������ �����ڴ� 
	WinMain()���� ���� ȣ��ȴٴ� ��ǿ� ����
    ���� WinMain() ȣ������ �ؾ� �� ���� �ִٸ� ���⼭ �Ѵ�.
*/
class CSingleApp : public CWinApp													
{
public:
	CSingleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleApp)
	public:
	virtual BOOL InitInstance();													
	//}}AFX_VIRTUAL

	/*
	(5)	InitInstance() �� ��ť��Ʈ, �����Ӱ� �� ��ü�� �������� �����,
	    ���� �������� ShowWindow()�� UpdateWindow() �� ȣ��
   */

// Implementation
	//{{AFX_MSG(CSingleApp)
	afx_msg void OnAppAbout();														
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG

	/*
	(6)	�ҽ����� �̹� ���ε� �޽��� �ڵ鷯�� 
        afx_msg �� ȣ�����(��� ���ۿ��� ���� ����.)
        - �ɹ��Լ��� ȣ����ʴ� thiscall�̴�. ( __stdcall �� �ƴ�)

        - //{{AFX_VIRTUAL(CSingleApp) ���⸦ �ּ�ó���ϸ�?
          �ڵ鷯�� Ư���� �ּ��� ���� ���ο��� �ִ�.(�ǹ� �ִ� �ּ���)
          Ŭ���� �����尡 ����ϴ� ������(������ �ڵ� ���� ����)
          �����尡 �����Լ��� �����ϱ� ���� //{{AFX_VIRTUAL�� ���۵Ǵ� �ڸ�Ʈ�� ã�´�.
          ���� �޽��� �ڵ鷯�� �����ϱ� ���� //{{AFX_MSG�� ã�´�.
	*/



	DECLARE_MESSAGE_MAP()
	/*
	(7) �޽��� �� ����ü�� ���� ��ũ�� 
	    DECLARE_MESSAGE_MAP ������ F12��ư Ŭ��
	    ����� �ҽ��� �̵���(AFXWIN.h)
	    ���� ����ü �迭�� ������
*/

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLE_H__EEBFAD37_69C5_42F3_8357_27F66F9148CE__INCLUDED_)
