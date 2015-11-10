#include "CWinApp.h"
#include "CView.h"
#include "resource.h"
#include "Step2Dlg.h"

IMPLEMENT_DYNCREATE(CView)

BEGIN_MESSAGE_MAP(CView)
    { WM_PAINT,       (CCmdTargetFunPointer)CView::OnDraw },
    { WM_DESTROY,     (CCmdTargetFunPointer)CView::OnDestroy },
    { WM_LBUTTONDOWN, (CCmdTargetFunPointer)CView::OnLButtonDown },
    { WM_COMMAND,     (CCmdTargetFunPointer)CView::OnCommand },
END_MESSAGE_MAP()

CWinApp app;

CView::CView()
{
    strcpy( m_str, "hello" );
}//CView::CView()

//CView Event handler------------------------------------------------
void CView::OnDraw(WPARAM, LPARAM)
{
    HDC             hdc;
    PAINTSTRUCT     ps;
    RECT            rect;

    hdc = BeginPaint( GetSafeHwnd(), &ps );
    GetClientRect( GetSafeHwnd(), &rect );
    DrawText( hdc, "Hello, Windows!", -1, &rect,
        DT_SINGLELINE|DT_CENTER|DT_VCENTER );
    EndPaint( GetSafeHwnd(), &ps );
}//CView::OnDraw()

void CView::OnDestroy(WPARAM, LPARAM)
{
    PostQuitMessage(0);
}//CView::OnDestroy()

void CView::OnLButtonDown(WPARAM, LPARAM)
{
    HDC hdc;

    hdc = GetDC( GetSafeHwnd() );
    Ellipse( hdc, 0, 0, 300, 300 );
    ReleaseDC( GetSafeHwnd(), hdc );
}

/***************************************************************
 [ 매시지 맵의 사용 ]

  API함수를 이용하여 구현(클래스 미사용)

  1) 사용자는 DialogBox()를 호출하여, 대화상자 출력
	 DialogBox의 마지막 파라미터는 사용자 정의 대화상자의
     프로시저의 시작 주소

  2) DialogBox는 대화상자 윈도우를 만들고, 운영체제는 대화
     상자 메시지 루프에서 이벤트 처리 

  3) 이벤트가 발생하면 메시지는 대화상자 프로시저로 전송

  4) 대화상자 프로시저에서 필요한 메시지 처리
     메시지를 처리한 경우는 FALSE를 리턴
	 FALSE를 리턴한 경우, 운영체제는 DialogProc을 호출하여 
	 디폴트 처리 수행

  5) 사용자는 대화상자를 종료하기 위해 EndDialog를 호출
     리턴값으로 2번째 파라미터 저장 

  6) 종료 플래그가 설정되어 있으므로 메시지 루프 종료
     저장값 리턴 
****************************************************************/
void CView::OnCommand(WPARAM wParam, LPARAM lParam) 
{
    int         iRet = 0;
    CStep2Dlg   dlg;

    switch( LOWORD(wParam) )
    {
    case IDM_DOIT:
        strcpy(dlg.m_strEdit1, m_str);
        iRet = dlg.DoModal();			// dlg 호출 

        if (iRet == IDOK)
        {
            strcpy(m_str, dlg.m_strEdit1);
        }
        break;

    case IDM_EXIT:
        DestroyWindow(GetSafeHwnd());
        break;
    }
}
