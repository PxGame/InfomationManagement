# include <Windows.h>


//设置字体
void SetFont(HWND hWnd, LPSTR FontName, int Size, int Weight)
{
    //HDC hdc = GetDC(hWnd);

    LOGFONT LogFont;
    ::memset(&LogFont, 0, sizeof(LOGFONT));
    lstrcpy(LogFont.lfFaceName, FontName);
    LogFont.lfWeight = Weight;
    LogFont.lfHeight = Size; // 字体大小
    LogFont.lfCharSet = 134;
    LogFont.lfOutPrecision = 3;
    LogFont.lfClipPrecision = 2;
    LogFont.lfOrientation = 45;
    LogFont.lfQuality = 1;
    LogFont.lfPitchAndFamily = 2;

    // 创建字体

    HFONT hFont = CreateFontIndirect(&LogFont);

    //LPTEXTMETRIC TM;//获取字体信息
    //::GetTextMetrics(hdc, TM);

    //设置背景

    // 设置控件字体
    ::SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, 0); 

    //::ReleaseDC(hWnd, hdc);
}
