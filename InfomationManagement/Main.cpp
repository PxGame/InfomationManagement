# include <Windows.h>
# include "User.h"

//获取系统参数
const int sWidth = GetSystemMetrics(SM_CXSCREEN);
const int sHeight = GetSystemMetrics(SM_CYSCREEN);


//定义全局变量
LPCSTR lpClassName = "MainWindow";//窗口类名
HINSTANCE hInst;//实例句柄
HWND hWnd;//主窗口句柄
CUser user;//用户登录类

const int wWidth = 800;//窗口大小
const int wHeight = 600;
const int wX = (sWidth - wWidth) / 2;
const int wY = (sHeight - wHeight) / 2;

//声明
ATOM MyRegistClass(HINSTANCE hInstance);
HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WinMainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpClassName,
    int nCmdShow
    )
{
    MSG msg;

    hInst = hInstance;//获取实例句柄

    MyRegistClass(hInstance);//注册窗口类

    hWnd = InitializeWindow(hInstance, SW_SHOW);
    if (hWnd == NULL)//初始化窗口
    {
        return FALSE;
    }
    
    user.Initialize(hInst, hWnd);
    user.Show(SW_SHOW);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

ATOM MyRegistClass(HINSTANCE hInstance)
{
    WNDCLASS win;

    win.cbClsExtra = 0;
    win.cbWndExtra = 0;
    win.hInstance = hInstance;
    win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    win.hCursor = LoadCursor(NULL, IDC_ARROW);
    win.hIcon = LoadIcon(win.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    win.lpfnWndProc = (WNDPROC)WinMainProc;
    win.lpszClassName = lpClassName;
    win.lpszMenuName = NULL;
    win.style = CS_DBLCLKS;

    return RegisterClass(&win);
}

HWND InitializeWindow(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd = CreateWindow(lpClassName, "Infomation Management", WS_CAPTION | WS_SYSMENU, 
        wX, wY, wWidth, wHeight, 
        NULL, NULL, hInstance, NULL);
    
    if (hWnd == NULL)
    {
        return NULL;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return hWnd;
}

LRESULT CALLBACK WinMainProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam
    )
{
    int nEvent;
    int nID;

    switch(uMsg)
    {
    case WM_CREATE :
        DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    case WM_PAINT :
        DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    case WM_COMMAND ://按键事件
        nEvent = HIWORD(wParam);
        nID = LOWORD(wParam);
        switch (nID)
        {
        case BT_LOGON ://登录按钮
            if (user.TestPassword() == true)
            {
                user.Show(SW_HIDE);
            }
            break;
        default :
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }
        break;
    case WM_CLOSE :
        if (IDOK == MessageBox(hWnd, "是否关闭程序？", "提示", MB_OKCANCEL))
        {
            DestroyWindow(hWnd);
        }
        break;
    case WM_DESTROY :
        PostQuitMessage(0);
        break;
    default :
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}