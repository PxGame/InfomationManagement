#pragma once
# include <Windows.h>

# define BT_LOGON    1
# define ET_INPUT    2

class CUser
{
private :
    LONG lPassword;//����
    HWND hWnd;//Ŀ�Ĵ��ھ��
    HINSTANCE hInstance;//Ŀ��ʵ�����

private ://�ؼ�
    HWND hButton_Logon;
    HWND hEdit_Input;

private :
    void CreateControl(void);

public :
    CUser (void);
    void Initialize(HINSTANCE hInstance, HWND hWnd);
    void Show(int nCmdShow);
};

