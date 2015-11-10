// Single.h : main header file for the SINGLE application
//

#if !defined(AFX_SINGLE_H__EEBFAD37_69C5_42F3_8357_27F66F9148CE__INCLUDED_)
#define AFX_SINGLE_H__EEBFAD37_69C5_42F3_8357_27F66F9148CE__INCLUDED_				
/*
(1) 헤더 중복 방지(특별한 문자열에 의해 감싸진다.)
    - 특별한 문자열이 중복될 확률은 거의 0이다. 따라서 이미 존재하는 다른 헤더의 
	  것과 중복되지 않음
*/



#if _MSC_VER > 1000																	
/*
(2) Microsoft C++의 옛 버전을 위해 존재한다.
하위 버전에서는 헤더 파일을 한번만 포함하는 기술을 지원하지 않았다.
*/


#pragma once					
/*
(3) 헤더가 링크 과정 중에 한 번만 포함될 것을 지시한다.
    또 한번의 안전 장치     
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
(4) MFC응용프로그램은 CwinApp를 상속받아 구현한다.
    CwinApp의 상위 클래스로 CcmdTarget이 있다는 것에 주의하자.
    (CwinApp가 윈도우 메시지를 가질 수 있다는 것을 의미한다.)

    CSingleApp 클래스의 생성자는 
	WinMain()보다 먼저 호출된다는 사실에 주의
    만약 WinMain() 호출전에 해야 할 일이 있다면 여기서 한다.
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
	(5)	InitInstance() 는 다큐먼트, 프레임과 뷰 객체를 동적으로 만들고,
	    메인 윈도우의 ShowWindow()와 UpdateWindow() 를 호출
   */

// Implementation
	//{{AFX_MSG(CSingleApp)
	afx_msg void OnAppAbout();														
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG

	/*
	(6)	소스에서 이미 매핑된 메시지 핸들러임 
        afx_msg 는 호출관례(없어도 동작에는 문제 없다.)
        - 맴버함수의 호출관례는 thiscall이다. ( __stdcall 이 아님)

        - //{{AFX_VIRTUAL(CSingleApp) 여기를 주석처리하면?
          핸들러는 특별한 주석에 의해 감싸여져 있다.(의미 있는 주석임)
          클래스 위저드가 사용하는 영역임(위저드 코드 관리 영역)
          위저드가 가상함수를 관리하기 위해 //{{AFX_VIRTUAL로 시작되는 코멘트를 찾는다.
          또한 메시지 핸들러를 관리하기 위해 //{{AFX_MSG를 찾는다.
	*/



	DECLARE_MESSAGE_MAP()
	/*
	(7) 메시지 맵 구조체의 선언 매크로 
	    DECLARE_MESSAGE_MAP 위에서 F12버튼 클릭
	    선언된 소스로 이동됨(AFXWIN.h)
	    정적 구조체 배열을 선언함
*/

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLE_H__EEBFAD37_69C5_42F3_8357_27F66F9148CE__INCLUDED_)
