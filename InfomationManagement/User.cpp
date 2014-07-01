# include "User.h"
# include "SetControl.h"

CUser::CUser (void)
{
    hWnd = NULL;
    hInstance = NULL;

    hButton_Logon = NULL;
    hEdit_Input = NULL;
    hStatic_LogonInfo = NULL;
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

    //目标窗口用户区的中点坐标
    int Center_x = (rt.right - rt.left) / 2;
    int Center_y = (rt.bottom - rt.top) / 2;  

    //创建控件
    hButton_Logon = CreateWindow("BUTTON", "登录", BS_PUSHBUTTON | WS_CHILD, 
        Center_x - 50, Center_y + 20, 100, 25, hWnd, (HMENU)BT_LOGON, hInstance, NULL);
    
    hEdit_Input = CreateWindow("EDIT", NULL, ES_PASSWORD | ES_NUMBER | WS_CHILD | ES_LEFT | ES_AUTOHSCROLL | WS_BORDER, 
        Center_x - 100, Center_y - 50, 200, 30, hWnd, (HMENU)ET_INPUT, hInstance, NULL);

    hStatic_LogonInfo = CreateWindow("STATIC", "用户登录", WS_CHILD, 
        Center_x - 100, Center_y - 120, 200, 50, hWnd, NULL, hInstance, NULL);

    //设置字体
    SetFont(hEdit_Input, NULL, 25, NULL);
    SetFont(hStatic_LogonInfo, NULL, 50, 100);

    //设置背景
    ::SetBkMode(GetDC(hStatic_LogonInfo), TRANSPARENT);

}

void CUser::Show(int nCmdShow)
{
    ShowWindow(hButton_Logon, nCmdShow);//hButton_Logon
    ShowWindow(hEdit_Input, nCmdShow);//hEdit_Input
    ShowWindow(hStatic_LogonInfo, nCmdShow);//hStatic_LogonInfo

}

bool CUser::TestPassword(void)
{
        ::GetWindowText(hEdit_Input, EditPassword, 11);//取输入值
        if( !strcmp(EditPassword, "12345678"))
        {
            return true;
        }
        else
        {
            return false;
        }
}