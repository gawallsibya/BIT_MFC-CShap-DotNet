#include "CWinApp.h"
#include "CView.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(CView)

BEGIN_MESSAGE_MAP(CView)
    { WM_PAINT,       CView::OnDraw },
    { WM_DESTROY,     CView::OnDestroy },
    { WM_LBUTTONDOWN, CView::OnLButtonDown },
    { WM_COMMAND,     CView::OnCommand },
END_MESSAGE_MAP()

CWinApp app;

BOOL    CALLBACK AboutDlgProc (HWND, UINT, WPARAM, LPARAM) ;

char    g_strEdit1[20];

CView::CView()
{
    strcpy( m_str, "hello" );
}

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
}//CView::OnLButtonDown()


/***************************************************************
 [ 대화 상자의 원리 ]

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
    int iRet = 0;

    switch (wParam)
    {
    case IDM_DOIT:
        strcpy(g_strEdit1, m_str);
        iRet = DialogBox( app.GetInstanceHandle(), "AboutBox", 
                          GetSafeHwnd(), AboutDlgProc );

        if (iRet == 100)
        {
            strcpy(m_str, g_strEdit1);
        }
        break;

    case IDM_EXIT:
        DestroyWindow(GetSafeHwnd());
        break;
    }//switch
}//CView::OnCommand()

BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hEdit1;

    switch (iMsg) 
	{
    case WM_INITDIALOG :
        hEdit1 = GetDlgItem(hDlg, IDC_EDIT1);
        SetDlgItemText(hDlg, IDC_EDIT1, g_strEdit1);        
        return TRUE;

    case WM_COMMAND :
        switch (LOWORD (wParam))
        {
        case IDOK :
            GetDlgItemText(hDlg, IDC_EDIT1, g_strEdit1, 19);
            EndDialog(hDlg, 100);
              //            ^ Note: this is the return value of 'DialogBox()'
            return TRUE;

        case IDCANCEL :
            EndDialog (hDlg, 0) ;
            return TRUE ;
        }
        break;
    }
    return FALSE ;
}
