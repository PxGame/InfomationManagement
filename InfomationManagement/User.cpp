#include "User.h"

CUser::CUser (void)
{
    lPassword = 0;
    hWnd = NULL;

    hButton_Logon = NULL;
    hEdit_Input = NULL;
}

void CUser::Initialize(HINSTANCE hInstance, HWND hWnd)
{
    //传递参数
    this->hWnd = hWnd;
    this->hInstance = hInstance;

    CUser::CreateControl();//创建控件

}

void CUser::CreateControl(void)
{
    RECT rt;
    GetClientRect(hWnd, &rt);//获取目的窗口用户区大小

    int Center_x = (rt.right - rt.left) / 2;
    int Center_y = (rt.bottom - rt.top) / 2;  

    hButton_Logon = CreateWindow("BUTTON", "登录", BS_PUSHBUTTON | WS_CHILD, 
        Center_x - 50, Center_y + 50, 100, 25, hWnd, (HMENU)BT_LOGON, hInstance, NULL);

}

void CUser::Show(int nCmdShow)
{
    ShowWindow(hButton_Logon, nCmdShow);//hButton_Logon
}