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
 [ ��ȭ ������ ���� ]

  API�Լ��� �̿��Ͽ� ����(Ŭ���� �̻��)

  1) ����ڴ� DialogBox()�� ȣ���Ͽ�, ��ȭ���� ���
	 DialogBox�� ������ �Ķ���ʹ� ����� ���� ��ȭ������
     ���ν����� ���� �ּ�

  2) DialogBox�� ��ȭ���� �����츦 �����, �ü���� ��ȭ
     ���� �޽��� �������� �̺�Ʈ ó�� 

  3) �̺�Ʈ�� �߻��ϸ� �޽����� ��ȭ���� ���ν����� ����

  4) ��ȭ���� ���ν������� �ʿ��� �޽��� ó��
     �޽����� ó���� ���� FALSE�� ����
	 FALSE�� ������ ���, �ü���� DialogProc�� ȣ���Ͽ� 
	 ����Ʈ ó�� ����

  5) ����ڴ� ��ȭ���ڸ� �����ϱ� ���� EndDialog�� ȣ��
     ���ϰ����� 2��° �Ķ���� ���� 

  6) ���� �÷��װ� �����Ǿ� �����Ƿ� �޽��� ���� ����
     ���尪 ���� 
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
