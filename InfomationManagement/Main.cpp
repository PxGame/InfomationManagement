# include <Windows.h>

//��ȡϵͳ����
const int sWidth = GetSystemMetrics(SM_CXSCREEN);
const int sHeight = GetSystemMetrics(SM_CYSCREEN);


//����ȫ�ֱ���
HINSTANCE hInst;//ʵ�����
LPCSTR lpClassName = "MainWindow";//��������
HWND hWnd;//�����ھ��

const int wWidth = 600;//���ڴ�С
const int wHeight = 400;

//����
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

    hInst = hInstance;//��ȡʵ�����

    MyRegistClass(hInstance);//ע�ᴰ����

    if (InitializeWindow(hInstance, SW_SHOW) == NULL)//��ʼ������
    {
        return FALSE;
    }

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
        (sWidth - wWidth) / 2, (sHeight - wHeight) / 2, wWidth, wHeight, 
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
    switch(uMsg)
    {
    case WM_PAINT :
        DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    case WM_COMMAND :
        DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    case WM_CLOSE :
        if (IDOK == MessageBox(hWnd, "�Ƿ�رճ���", "��ʾ", MB_OKCANCEL))
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