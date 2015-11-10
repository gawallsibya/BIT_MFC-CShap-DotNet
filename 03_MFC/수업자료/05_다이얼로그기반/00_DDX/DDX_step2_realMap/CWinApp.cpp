#include "CWinApp.h"

extern CWinApp app;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

char CWinApp::szAppName[] = "generic";

// destructor
CWinApp::~CWinApp()
{
    if ( m_pMainWnd != NULL )
    {
        delete m_pMainWnd;
        m_pMainWnd = NULL;
    }//if
}//CWinApp::~CWinApp()

void CWinApp::AddDocTemplate(CRuntimeClass* pRuntimeClass)
{
    m_pMainWnd = (CWnd*)pRuntimeClass->CreateObject();
    if ( m_pMainWnd == NULL )
        return;

    CREATESTRUCT    cs;

    m_pMainWnd->PreCreateWindow( cs );
    m_pMainWnd->m_hwnd = ::CreateWindow( szAppName,   //window class name
        "RTTI",                 //window caption
        WS_OVERLAPPEDWINDOW,    //window style
        CW_USEDEFAULT,          //initial x position
        CW_USEDEFAULT,          //initial y position
        CW_USEDEFAULT,          //initial x size
        CW_USEDEFAULT,          //initial y size
        NULL,                   //parent window handle
        NULL,                   //window menu handle
        m_hInstance,            //program instance handle
        NULL );                 //creation parameters
}//CWinApp::AddDocTemplate()

void CWinApp::InitInstance(HINSTANCE    hInstance,
                           PSTR         szCmdLine,
                           int          iCmdShow)
{
    WNDCLASSEX  wndclass;

    wndclass.cbSize         = sizeof(wndclass);
    wndclass.style          = CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc    = WndProc;
    wndclass.cbClsExtra     = 0;
    wndclass.cbWndExtra     = 0;
    wndclass.hInstance      = hInstance;
    wndclass.hIcon          = LoadIcon(NULL,IDI_APPLICATION);
    wndclass.hCursor        = LoadCursor(NULL,IDC_ARROW);
    wndclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName   = szAppName;
    wndclass.lpszClassName  = szAppName;
    wndclass.hIconSm        = LoadIcon(NULL,IDI_APPLICATION);

    ::RegisterClassEx(&wndclass);

    m_hInstance = hInstance;

    AddDocTemplate( RUNTIME_CLASS(CView) );    
    
    m_pMainWnd->ShowWindow( iCmdShow );
    m_pMainWnd->UpdateWindow();
}//CWinApp::InitInstance

void CWinApp::Run()
{
    MSG msg;
    int bFlag = TRUE;

    while ( TRUE )
    {
        if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) )
        {
            if ( msg.message == WM_QUIT )
                break;

            TranslateMessage( &msg );
            DispatchMessage( &msg );
            bFlag = TRUE;
        }

        if ( bFlag )
            bFlag = OnIdle();
    }
}

WPARAM CWinApp::ExitInstance()
{
    return 0L;//msg.wParam;
}

int CWinApp::OnIdle()
{
    return FALSE;
}



//Window procedure---------------------------------------------------

// CCmdTarget : 메시지를 처리할 수 있는 공통 클래스 
// 매시지처리와 관련 메크로 먼저 확인(수정 사항)

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    int                     i = 0;
    CCmdTarget*             pMainWnd;
    const MessageMap*       pMessageMap;

    // 1) hwnd에 대응하는 윈도우 객체를 얻어냄 
    pMainWnd    = CWnd::GetWndFromHandle(hwnd);

	// 2) 대상 윈도우의 메시지 맵을 얻어냄 
    pMessageMap = pMainWnd->GetMessageMap();

    // 3) 대상 윈도우의 메시지 맵 검사 
    while ( pMessageMap[i].iMsg != 0 )
    {
        if ( iMsg == pMessageMap[i].iMsg )
        {
			// 4) 해당 핸들러 호출 
            (pMainWnd->*pMessageMap[i].fp)(wParam, lParam);

            return 0;
        }
        ++i;
    }

    return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE    hInstance,
                   HINSTANCE    hPrevInstance,
                   PSTR         szCmdLine,
                   int          iCmdShow)
{
    app.InitInstance( hInstance, szCmdLine, iCmdShow );
    app.Run();

    return app.ExitInstance();
}//WinMain()
