#pragma once
# include <Windows.h>

# define BT_LOGON    1
# define ET_INPUT    2

class CUser
{
private :
    char FilePassword[11];
    char EditPassword[11];//hEdit_Input字符密码
    HWND hWnd;//目的窗口句柄
    HINSTANCE hInstance;//目的实例句柄

private ://控件
    HWND hButton_Logon;
    HWND hEdit_Input;
    HWND hStatic_LogonInfo;

private :
    void CreateControl(void);

public :
    CUser (void);
    void Initialize(HINSTANCE hInstance, HWND hWnd);
    void Show(int nCmdShow);
    bool TestPassword(void);
};

