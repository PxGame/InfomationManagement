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
    //���ݲ���
    this->hWnd = hWnd;
    this->hInstance = hInstance;

    CUser::CreateControl();//�����ؼ�

}

void CUser::CreateControl(void)
{
    RECT rt;
    GetClientRect(hWnd, &rt);//��ȡĿ�Ĵ����û�����С

    int Center_x = (rt.right - rt.left) / 2;
    int Center_y = (rt.bottom - rt.top) / 2;  

    hButton_Logon = CreateWindow("BUTTON", "��¼", BS_PUSHBUTTON | WS_CHILD, 
        Center_x - 50, Center_y + 50, 100, 25, hWnd, (HMENU)BT_LOGON, hInstance, NULL);

}

void CUser::Show(int nCmdShow)
{
    ShowWindow(hButton_Logon, nCmdShow);//hButton_Logon
}