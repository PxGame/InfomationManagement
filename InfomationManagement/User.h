#pragma once
# include <Windows.h>

# define BT_LOGON    1
# define ET_INPUT    2

class CUser
{
private :
    LONG lPassword;//密码
    HWND hWnd;//目的窗口句柄
    HINSTANCE hInstance;//目的实例句柄

private ://控件
    HWND hButton_Logon;
    HWND hEdit_Input;

private :
    void CreateControl(void);

public :
    CUser (void);
    void Initialize(HINSTANCE hInstance, HWND hWnd);
    void Show(int nCmdShow);
};

