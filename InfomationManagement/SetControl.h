# include <Windows.h>


//��������
void SetFont(HWND hWnd, LPSTR FontName, int Size, int Weight)
{
    //HDC hdc = GetDC(hWnd);

    LOGFONT LogFont;
    ::memset(&LogFont, 0, sizeof(LOGFONT));
    lstrcpy(LogFont.lfFaceName, FontName);
    LogFont.lfWeight = Weight;
    LogFont.lfHeight = Size; // �����С
    LogFont.lfCharSet = 134;
    LogFont.lfOutPrecision = 3;
    LogFont.lfClipPrecision = 2;
    LogFont.lfOrientation = 45;
    LogFont.lfQuality = 1;
    LogFont.lfPitchAndFamily = 2;

    // ��������

    HFONT hFont = CreateFontIndirect(&LogFont);

    //LPTEXTMETRIC TM;//��ȡ������Ϣ
    //::GetTextMetrics(hdc, TM);

    //���ñ���

    // ���ÿؼ�����
    ::SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, 0); 

    //::ReleaseDC(hWnd, hdc);
}
