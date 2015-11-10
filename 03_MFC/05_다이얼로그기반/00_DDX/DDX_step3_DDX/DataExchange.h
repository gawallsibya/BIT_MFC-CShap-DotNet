#if !defined(_CDATAEXCHANGE_DEFINED_)
#define _CDATAEXCHANGE_DEFINED_

#include "CWnd.h"

/*
 DDX : 텍스트 박스 컨트롤과 컨트롤에 대응된 멤버 변수 코드 자동화
 - DoDataExchange()
 - UpdateData()
 - DDX_  전역함수 

 DDX의 원리 
 - 사용자는 다이얼로그 데이터 교환을 위해 updateData()호출
 - 다이얼로그 클래스의 베이스 클래스인 CDialog UpdateData()는
   가상 함수 DoDataExchange()를 호출
 - 사용자는 교환을 원하는 데이터를, 상속받은 DoDataExchange()
   함수에 구현 
*/



/*
데이터 교환의 전송 방향을 결정하는 클래스 선언
*/

class CDataExchange
{
// Attributes
public:

	// TRUE => 컨트롤의 값을 맴버 변수로 전송 
    BOOL m_bSaveAndValidate;   

	// 데이터 교환하는 윈도우 객체  
    CWnd* m_pDlgWnd;           

    /*
// Operations (for implementors of DDX and DDV procs)
    HWND PrepareCtrl(int nIDC);     // return HWND of control
    HWND PrepareEditCtrl(int nIDC); // return HWND of control
    void Fail();                    // will throw exception

#ifndef _AFX_NO_OCC_SUPPORT
    CWnd* PrepareOleCtrl(int nIDC); // for OLE controls in dialog
#endif
    */


	// 생성자 
    CDataExchange(CWnd* pDlgWnd, BOOL bSaveAndValidate);
    /*
    HWND m_hWndLastControl;    // last control used (for validation)
    BOOL m_bEditLastControl;   // last control was an edit item
    */
};//class CDataExchange

#endif // !defined(_CDATAEXCHANGE_DEFINED_)
