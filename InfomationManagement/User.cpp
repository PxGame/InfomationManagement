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
    //���ݲ���
    this->hWnd = hWnd;
    this->hInstance = hInstance;

    CUser::CreateControl();//�����ؼ�
}

void CUser::CreateControl(void)
{
    RECT rt;
    GetClientRect(hWnd, &rt);//��ȡĿ�Ĵ����û�����С

    //Ŀ�괰���û������е�����
    int Center_x = (rt.right - rt.left) / 2;
    int Center_y = (rt.bottom - rt.top) / 2;  

    //�����ؼ�
    hButton_Logon = CreateWindow("BUTTON", "��¼", BS_PUSHBUTTON | WS_CHILD, 
        Center_x - 50, Center_y + 20, 100, 25, hWnd, (HMENU)BT_LOGON, hInstance, NULL);
    
    hEdit_Input = CreateWindow("EDIT", NULL, ES_PASSWORD | ES_NUMBER | WS_CHILD | ES_LEFT | ES_AUTOHSCROLL | WS_BORDER, 
        Center_x - 100, Center_y - 50, 200, 30, hWnd, (HMENU)ET_INPUT, hInstance, NULL);

    hStatic_LogonInfo = CreateWindow("STATIC", "�û���¼", WS_CHILD, 
        Center_x - 100, Center_y - 120, 200, 50, hWnd, NULL, hInstance, NULL);

    //��������
    SetFont(hEdit_Input, NULL, 25, NULL);
    SetFont(hStatic_LogonInfo, NULL, 50, 100);

    //���ñ���
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
        ::GetWindowText(hEdit_Input, EditPassword, 11);//ȡ����ֵ
        if( !strcmp(EditPassword, "12345678"))
        {
            return true;
        }
        else
        {
            return false;
        }
}