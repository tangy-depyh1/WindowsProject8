// WindowsProject8.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject8.h"
#include <time.h>
#define MAX_LOADSTRING 100

#define NUM_KNIVES 3
#include<stdio.h>
// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

#define DEBUG_GAME 

// Отправить объявления функций, включенных в этот модуль кода:
enum Modes {
    START,
    GAME,
    VICTORY,
    LOSS,
    FINAL
};

enum Modes mode = START;

int step = 0;


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT8));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT8));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT8);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}



struct Image { int cx; int cy; int vx; int vy; };
struct Image imYagoda = { 680,200,10,0 };
struct Image imStech = { 280,630,0,10 };
struct Image imYagoda1 = { 150,650,0,10 };
struct Image imYagoda2 = { 370,950,0,-10 };
struct Image imYagoda3 = { 590,650,0,10 };






void DrawFifi(HDC hdc, int cx, int cy) {
    //кролик ФИФИ
        //контур
    HBRUSH hBrush1;
    hBrush1 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush1);
    HBRUSH hBrush4;
    hBrush4 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush4);
    Rectangle(hdc, 20 - 130 + cx, 10 - 110 + cy, 50 - 130 + cx, 20 - 110 + cy);
    Rectangle(hdc, 10 - 130 + cx, 20 - 110 + cy, 20 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 20 - 130 + cx, 50 - 110 + cy, 40 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 40 - 130 + cx, 60 - 110 + cy, 70 - 130 + cx, 70 - 110 + cy);
    Rectangle(hdc, 50 - 130 + cx, 20 - 110 + cy, 70 - 130 + cx, 30 - 110 + cy);
    Rectangle(hdc, 70 - 130 + cx, 30 - 110 + cy, 80 - 130 + cx, 40 - 110 + cy);
    Rectangle(hdc, 80 - 130 + cx, 40 - 110 + cy, 90 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 90 - 130 + cx, 50 - 110 + cy, 110 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 80 - 130 + cx, 60 - 110 + cy, 90 - 130 + cx, 70 - 110 + cy);
    Rectangle(hdc, 70 - 130 + cx, 70 - 110 + cy, 80 - 130 + cx, 80 - 110 + cy);
    Rectangle(hdc, 110 - 130 + cx, 40 - 110 + cy, 150 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 150 - 130 + cx, 50 - 110 + cy, 170 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 170 - 130 + cx, 40 - 110 + cy, 180 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 180 - 130 + cx, 30 - 110 + cy, 190 - 130 + cx, 40 - 110 + cy);
    Rectangle(hdc, 190 - 130 + cx, 20 - 110 + cy, 210 - 130 + cx, 30 - 110 + cy);
    Rectangle(hdc, 210 - 130 + cx, 10 - 110 + cy, 240 - 130 + cx, 20 - 110 + cy);
    Rectangle(hdc, 240 - 130 + cx, 20 - 110 + cy, 250 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 220 - 130 + cx, 50 - 110 + cy, 240 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 190 - 130 + cx, 60 - 110 + cy, 220 - 130 + cx, 70 - 110 + cy);
    Rectangle(hdc, 180 - 130 + cx, 70 - 110 + cy, 190 - 130 + cx, 80 - 110 + cy);
    Rectangle(hdc, 170 - 130 + cx, 60 - 110 + cy, 180 - 130 + cx, 70 - 110 + cy);
    Rectangle(hdc, 190 - 130 + cx, 80 - 110 + cy, 200 - 130 + cx, 100 - 110 + cy);
    Rectangle(hdc, 200 - 130 + cx, 100 - 110 + cy, 210 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 210 - 130 + cx, 120 - 110 + cy, 220 - 130 + cx, 170 - 110 + cy);
    Rectangle(hdc, 200 - 130 + cx, 170 - 110 + cy, 210 - 130 + cx, 190 - 110 + cy);
    Rectangle(hdc, 180 - 130 + cx, 190 - 110 + cy, 200 - 130 + cx, 200 - 110 + cy);
    Rectangle(hdc, 80 - 130 + cx, 20 - 110 + cy, 180 - 130 + cx, 210 - 110 + cy);
    Rectangle(hdc, 60 - 130 + cx, 190 - 110 + cy, 80 - 130 + cx, 200 - 110 + cy);
    Rectangle(hdc, 50 - 130 + cx, 170 - 110 + cy, 60 - 130 + cx, 190 - 110 + cy);
    Rectangle(hdc, 40 - 130 + cx, 120 - 110 + cy, 50 - 130 + cx, 170 - 110 + cy);
    Rectangle(hdc, 50 - 130 + cx, 100 - 110 + cy, 60 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 60 - 130 + cx, 80 - 110 + cy, 70 - 130 + cx, 100 - 110 + cy);
    Rectangle(hdc, 90 - 130 + cx, 100 - 110 + cy, 100 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 80 - 130 + cx, 110 - 110 + cy, 90 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 160 - 130 + cx, 100 - 110 + cy, 170 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 150 - 130 + cx, 110 - 110 + cy, 160 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 120 - 130 + cx, 110 - 110 + cy, 130 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 110 - 130 + cx, 120 - 110 + cy, 120 - 130 + cx, 130 - 110 + cy);
    Rectangle(hdc, 130 - 130 + cx, 120 - 110 + cy, 140 - 130 + cx, 130 - 110 + cy);

    //уши и живот
    HPEN hPen2;
    hPen2 = CreatePen(PS_SOLID, 4, RGB(255, 105, 180));
    SelectObject(hdc, hPen2);
    HBRUSH hBrush2;
    hBrush2 = CreateSolidBrush(RGB(255, 105, 180));
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, 50 - 130 + cx, 40 - 110 + cy, 70 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 70 - 130 + cx, 50 - 110 + cy, 90 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 170 - 130 + cx, 50 - 110 + cy, 190 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 190 - 130 + cx, 40 - 110 + cy, 210 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 110 - 130 + cx, 160 - 110 + cy, 140 - 130 + cx, 170 - 110 + cy);
    Rectangle(hdc, 100 - 130 + cx, 170 - 110 + cy, 150 - 130 + cx, 180 - 110 + cy);
    Rectangle(hdc, 90 - 130 + cx, 180 - 110 + cy, 170 - 130 + cx, 190 - 110 + cy);
    Rectangle(hdc, 90 - 130 + cx, 190 - 110 + cy, 170 - 130 + cx, 200 - 110 + cy);

    //закрашенное туловище
    HPEN hPen3;
    hPen3 = CreatePen(PS_SOLID, 4, RGB(70, 130, 180));
    SelectObject(hdc, hPen3);
    HBRUSH hBrush3;
    hBrush3 = CreateSolidBrush(RGB(70, 130, 180));
    SelectObject(hdc, hBrush3);
    Rectangle(hdc, 20 - 130 + cx, 20 - 110 + cy, 50 - 130 + cx, 40 - 110 + cy);
    Rectangle(hdc, 50 - 130 + cx, 30 - 110 + cy, 70 - 130 + cx, 40 - 110 + cy);
    Rectangle(hdc, 20 - 130 + cx, 40 - 110 + cy, 50 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 40 - 130 + cx, 50 - 110 + cy, 70 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 70 - 130 + cx, 40 - 110 + cy, 80 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 70 - 130 + cx, 60 - 110 + cy, 80 - 130 + cx, 70 - 110 + cy);
    Rectangle(hdc, 210 - 130 + cx, 20 - 110 + cy, 240 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 190 - 130 + cx, 30 - 110 + cy, 210 - 130 + cx, 40 - 110 + cy);
    Rectangle(hdc, 180 - 130 + cx, 40 - 110 + cy, 190 - 130 + cx, 50 - 110 + cy);
    Rectangle(hdc, 190 - 130 + cx, 50 - 110 + cy, 220 - 130 + cx, 60 - 110 + cy);
    Rectangle(hdc, 180 - 130 + cx, 60 - 110 + cy, 190 - 130 + cx, 70 - 110 + cy);
    Rectangle(hdc, 110 - 130 + cx, 50 - 110 + cy, 150 - 130 + cx, 110 - 110 + cy);
    Rectangle(hdc, 150 - 130 + cx, 60 - 110 + cy, 170 - 130 + cx, 100 - 110 + cy);
    Rectangle(hdc, 90 - 130 + cx, 60 - 110 + cy, 110 - 130 + cx, 100 - 110 + cy);
    Rectangle(hdc, 50 - 130 + cx, 120 - 110 + cy, 110 - 130 + cx, 170 - 110 + cy);
    Rectangle(hdc, 70 - 130 + cx, 80 - 110 + cy, 90 - 130 + cx, 100 - 110 + cy);
    Rectangle(hdc, 60 - 130 + cx, 100 - 110 + cy, 80 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 80 - 130 + cx, 70 - 110 + cy, 90 - 130 + cx, 80 - 110 + cy);
    Rectangle(hdc, 60 - 130 + cx, 170 - 110 + cy, 90 - 130 + cx, 190 - 110 + cy);
    Rectangle(hdc, 80 - 130 + cx, 190 - 110 + cy, 90 - 130 + cx, 200 - 110 + cy);
    Rectangle(hdc, 90 - 130 + cx, 170 - 110 + cy, 100 - 130 + cx, 180 - 110 + cy);
    Rectangle(hdc, 140 - 130 + cx, 120 - 110 + cy, 210 - 130 + cx, 170 - 110 + cy);
    Rectangle(hdc, 170 - 130 + cx, 170 - 110 + cy, 200 - 130 + cx, 190 - 110 + cy);
    Rectangle(hdc, 150 - 130 + cx, 170 - 110 + cy, 170 - 130 + cx, 180 - 110 + cy);
    Rectangle(hdc, 170 - 130 + cx, 190 - 110 + cy, 180 - 130 + cx, 200 - 110 + cy);
    Rectangle(hdc, 170 - 130 + cx, 80 - 110 + cy, 190 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 170 - 130 + cx, 70 - 110 + cy, 180 - 130 + cx, 80 - 110 + cy);
    Rectangle(hdc, 190 - 130 + cx, 100 - 110 + cy, 200 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 100 - 130 + cx, 100 - 110 + cy, 110 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 110 - 130 + cx, 110 - 110 + cy, 120 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 130 - 130 + cx, 110 - 110 + cy, 150 - 130 + cx, 120 - 110 + cy);
    Rectangle(hdc, 110 - 130 + cx, 130 - 110 + cy, 150 - 130 + cx, 160 - 110 + cy);
    Rectangle(hdc, 120 - 130 + cx, 120 - 110 + cy, 130 - 130 + cx, 130 - 110 + cy);

    DeleteObject(hBrush1);
    DeleteObject(hBrush4);
    DeleteObject(hPen2);
    DeleteObject(hBrush2);
    DeleteObject(hPen3);
    DeleteObject(hBrush3);




#ifdef DEBUG_GAME  
    HPEN hPenZone = CreatePen(PS_SOLID, 2, RGB(0, 0, 0, ));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 50, cy, NULL);
    LineTo(hdc, cx + 50, cy);
    MoveToEx(hdc, cx, cy - 50, NULL);
    LineTo(hdc, cx, cy + 50);

    DeleteObject(hPenZone);


#endif 
}
void DrawDjevi(HDC hdc, int cx, int cy) {
    //покемон ДЖЕВИ
            //контур
    HPEN hPen4;
    hPen4 = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
    SelectObject(hdc, hPen4);
    HBRUSH hBrush4;
    hBrush4 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush4);
    Rectangle(hdc, 300 - 360 + cx, 20 - 120 + cy, 310 - 360 + cx, 30 - 120 + cy);
    Rectangle(hdc, 290 - 360 + cx, 30 - 120 + cy, 300 - 360 + cx, 70 - 120 + cy);
    Rectangle(hdc, 280 - 360 + cx, 70 - 120 + cy, 290 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 290 - 360 + cx, 90 - 120 + cy, 310 - 360 + cx, 100 - 120 + cy);
    Rectangle(hdc, 290 - 360 + cx, 100 - 120 + cy, 300 - 360 + cx, 130 - 120 + cy);
    Rectangle(hdc, 300 - 360 + cx, 120 - 120 + cy, 310 - 360 + cx, 140 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 140 - 120 + cy, 330 - 360 + cx, 150 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 150 - 120 + cy, 320 - 360 + cx, 160 - 120 + cy);
    Rectangle(hdc, 300 - 360 + cx, 160 - 120 + cy, 310 - 360 + cx, 200 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 200 - 120 + cy, 330 - 360 + cx, 210 - 120 + cy);
    Rectangle(hdc, 330 - 360 + cx, 210 - 120 + cy, 370 - 360 + cx, 220 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 200 - 120 + cy, 390 - 360 + cx, 210 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 190 - 120 + cy, 410 - 360 + cx, 200 - 120 + cy);
    Rectangle(hdc, 410 - 360 + cx, 180 - 120 + cy, 420 - 360 + cx, 190 - 120 + cy);
    Rectangle(hdc, 420 - 360 + cx, 160 - 120 + cy, 430 - 360 + cx, 180 - 120 + cy);
    Rectangle(hdc, 430 - 360 + cx, 150 - 120 + cy, 440 - 360 + cx, 160 - 120 + cy);
    Rectangle(hdc, 410 - 360 + cx, 140 - 120 + cy, 430 - 360 + cx, 150 - 120 + cy);
    Rectangle(hdc, 380 - 360 + cx, 150 - 120 + cy, 410 - 360 + cx, 160 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 140 - 120 + cy, 390 - 360 + cx, 150 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 120 - 120 + cy, 400 - 360 + cx, 140 - 120 + cy);
    Rectangle(hdc, 400 - 360 + cx, 90 - 120 + cy, 410 - 360 + cx, 130 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 90 - 120 + cy, 400 - 360 + cx, 100 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 100 - 120 + cy, 320 - 360 + cx, 120 - 120 + cy);
    Rectangle(hdc, 320 - 360 + cx, 110 - 120 + cy, 330 - 360 + cx, 130 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 110 - 120 + cy, 380 - 360 + cx, 130 - 120 + cy);
    Rectangle(hdc, 380 - 360 + cx, 100 - 120 + cy, 390 - 360 + cx, 120 - 120 + cy);
    Rectangle(hdc, 410 - 360 + cx, 70 - 120 + cy, 420 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 400 - 360 + cx, 30 - 120 + cy, 410 - 360 + cx, 70 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 20 - 120 + cy, 400 - 360 + cx, 30 - 120 + cy);
    Rectangle(hdc, 380 - 360 + cx, 30 - 120 + cy, 390 - 360 + cx, 50 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 50 - 120 + cy, 380 - 360 + cx, 80 - 120 + cy);
    Rectangle(hdc, 330 - 360 + cx, 40 - 120 + cy, 370 - 360 + cx, 50 - 120 + cy);
    Rectangle(hdc, 320 - 360 + cx, 50 - 120 + cy, 330 - 360 + cx, 80 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 30 - 120 + cy, 320 - 360 + cx, 50 - 120 + cy);
    Rectangle(hdc, 330 - 360 + cx, 150 - 120 + cy, 370 - 360 + cx, 160 - 120 + cy);

    //глаза
    HPEN hPen5;
    hPen5 = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));
    SelectObject(hdc, hPen5);
    HBRUSH hBrush5;
    hBrush5 = CreateSolidBrush(RGB(255, 0, 0));
    SelectObject(hdc, hBrush5);
    Rectangle(hdc, 320 - 360 + cx, 100 - 120 + cy, 330 - 360 + cx, 110 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 100 - 120 + cy, 380 - 360 + cx, 110 - 120 + cy);

    //покраска 
    HPEN hPen6;
    hPen6 = CreatePen(PS_SOLID, 4, RGB(153, 50, 204));
    SelectObject(hdc, hPen6);
    HBRUSH hBrush6;
    hBrush6 = CreateSolidBrush(RGB(153, 50, 204));
    SelectObject(hdc, hBrush6);
    Rectangle(hdc, 300 - 360 + cx, 30 - 120 + cy, 310 - 360 + cx, 70 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 50 - 120 + cy, 320 - 360 + cx, 80 - 120 + cy);
    Rectangle(hdc, 290 - 360 + cx, 70 - 120 + cy, 300 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 300 - 360 + cx, 80 - 120 + cy, 310 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 300 - 360 + cx, 70 - 120 + cy, 310 - 360 + cx, 80 - 120 + cy);
    Rectangle(hdc, 330 - 360 + cx, 50 - 120 + cy, 370 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 90 - 120 + cy, 340 - 360 + cx, 100 - 120 + cy);
    Rectangle(hdc, 360 - 360 + cx, 90 - 120 + cy, 390 - 360 + cx, 100 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 80 - 120 + cy, 330 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 30 - 120 + cy, 400 - 360 + cx, 70 - 120 + cy);
    Rectangle(hdc, 380 - 360 + cx, 50 - 120 + cy, 390 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 80 - 120 + cy, 380 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 70 - 120 + cy, 410 - 360 + cx, 90 - 120 + cy);
    Rectangle(hdc, 300 - 360 + cx, 100 - 120 + cy, 310 - 360 + cx, 120 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 120 - 120 + cy, 320 - 360 + cx, 140 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 100 - 120 + cy, 400 - 360 + cx, 120 - 120 + cy);
    Rectangle(hdc, 380 - 360 + cx, 120 - 120 + cy, 390 - 360 + cx, 140 - 120 + cy);
    Rectangle(hdc, 330 - 360 + cx, 100 - 120 + cy, 370 - 360 + cx, 120 - 120 + cy);
    Rectangle(hdc, 320 - 360 + cx, 150 - 120 + cy, 330 - 360 + cx, 180 - 120 + cy);
    Rectangle(hdc, 310 - 360 + cx, 160 - 120 + cy, 320 - 360 + cx, 200 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 160 - 120 + cy, 420 - 360 + cx, 180 - 120 + cy);
    Rectangle(hdc, 410 - 360 + cx, 150 - 120 + cy, 430 - 360 + cx, 160 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 150 - 120 + cy, 380 - 360 + cx, 160 - 120 + cy);
    Rectangle(hdc, 360 - 360 + cx, 160 - 120 + cy, 370 - 360 + cx, 170 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 180 - 120 + cy, 390 - 360 + cx, 190 - 120 + cy);
    Rectangle(hdc, 400 - 360 + cx, 180 - 120 + cy, 410 - 360 + cx, 190 - 120 + cy);

    //покраска два
    HPEN hPen7;
    hPen7 = CreatePen(PS_SOLID, 4, RGB(147, 112, 219));
    SelectObject(hdc, hPen7);
    HBRUSH hBrush7;
    hBrush7 = CreateSolidBrush(RGB(147, 112, 219));
    SelectObject(hdc, hBrush7);
    Rectangle(hdc, 340 - 360 + cx, 90 - 120 + cy, 360 - 360 + cx, 100 - 120 + cy);
    Rectangle(hdc, 330 - 360 + cx, 120 - 120 + cy, 370 - 360 + cx, 150 - 120 + cy);
    Rectangle(hdc, 320 - 360 + cx, 130 - 120 + cy, 330 - 360 + cx, 140 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 130 - 120 + cy, 380 - 360 + cx, 140 - 120 + cy);
    Rectangle(hdc, 330 - 360 + cx, 160 - 120 + cy, 360 - 360 + cx, 210 - 120 + cy);
    Rectangle(hdc, 320 - 360 + cx, 180 - 120 + cy, 330 - 360 + cx, 200 - 120 + cy);
    Rectangle(hdc, 360 - 360 + cx, 170 - 120 + cy, 370 - 360 + cx, 210 - 120 + cy);
    Rectangle(hdc, 370 - 360 + cx, 190 - 120 + cy, 390 - 360 + cx, 200 - 120 + cy);
    Rectangle(hdc, 390 - 360 + cx, 180 - 120 + cy, 400 - 360 + cx, 190 - 120 + cy);

    DeleteObject(hPen4);
    DeleteObject(hBrush4);
    DeleteObject(hPen5);
    DeleteObject(hBrush5);
    DeleteObject(hPen6);
    DeleteObject(hBrush6);
    DeleteObject(hPen7);
    DeleteObject(hBrush7);




#ifdef DEBUG_GAME  
    HPEN hPenZone = CreatePen(PS_SOLID, 2, RGB(0, 0, 0, ));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 50, cy, NULL);
    LineTo(hdc, cx + 50, cy);
    MoveToEx(hdc, cx, cy - 50, NULL);
    LineTo(hdc, cx, cy + 50);

    DeleteObject(hPenZone);


#endif 
}
void DrawStich(HDC hdc, int cx, int cy) {
    //стич контур
    HPEN hPen12;
    hPen12 = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
    SelectObject(hdc, hPen12);
    HBRUSH hBrush12;
    hBrush12 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush12);
    Rectangle(hdc, 30 - 140 + cx, 260 - 310 + cy, 50 - 140 + cx, 270 - 310 + cy);
    Rectangle(hdc, 50 - 140 + cx, 270 - 310 + cy, 60 - 140 + cx, 290 - 310 + cy);
    Rectangle(hdc, 20 - 140 + cx, 270 - 310 + cy, 30 - 140 + cx, 330 - 310 + cy);
    Rectangle(hdc, 30 - 140 + cx, 330 - 310 + cy, 50 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 50 - 140 + cx, 340 - 310 + cy, 60 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 60 - 140 + cx, 290 - 310 + cy, 70 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 70 - 140 + cx, 300 - 310 + cy, 80 - 140 + cx, 310 - 310 + cy);
    Rectangle(hdc, 80 - 140 + cx, 290 - 310 + cy, 90 - 140 + cx, 300 - 310 + cy);
    Rectangle(hdc, 90 - 140 + cx, 280 - 310 + cy, 100 - 140 + cx, 290 - 310 + cy);
    Rectangle(hdc, 100 - 140 + cx, 270 - 310 + cy, 120 - 140 + cx, 280 - 310 + cy);
    Rectangle(hdc, 110 - 140 + cx, 280 - 310 + cy, 120 - 140 + cx, 300 - 310 + cy);
    Rectangle(hdc, 120 - 140 + cx, 290 - 310 + cy, 140 - 140 + cx, 300 - 310 + cy);
    Rectangle(hdc, 140 - 140 + cx, 280 - 310 + cy, 150 - 140 + cx, 290 - 310 + cy);
    Rectangle(hdc, 120 - 140 + cx, 260 - 310 + cy, 130 - 140 + cx, 270 - 310 + cy);
    Rectangle(hdc, 130 - 140 + cx, 250 - 310 + cy, 150 - 140 + cx, 260 - 310 + cy);
    Rectangle(hdc, 150 - 140 + cx, 260 - 310 + cy, 160 - 140 + cx, 270 - 310 + cy);
    Rectangle(hdc, 160 - 140 + cx, 270 - 310 + cy, 180 - 140 + cx, 280 - 310 + cy);
    Rectangle(hdc, 180 - 140 + cx, 280 - 310 + cy, 190 - 140 + cx, 290 - 310 + cy);
    Rectangle(hdc, 190 - 140 + cx, 290 - 310 + cy, 200 - 140 + cx, 300 - 310 + cy);
    Rectangle(hdc, 200 - 140 + cx, 300 - 310 + cy, 210 - 140 + cx, 310 - 310 + cy);
    Rectangle(hdc, 210 - 140 + cx, 290 - 310 + cy, 220 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 220 - 140 + cx, 270 - 310 + cy, 230 - 140 + cx, 290 - 310 + cy);
    Rectangle(hdc, 230 - 140 + cx, 260 - 310 + cy, 250 - 140 + cx, 270 - 310 + cy);
    Rectangle(hdc, 250 - 140 + cx, 270 - 310 + cy, 260 - 140 + cx, 330 - 310 + cy);
    Rectangle(hdc, 230 - 140 + cx, 330 - 310 + cy, 250 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 220 - 140 + cx, 340 - 310 + cy, 230 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 200 - 140 + cx, 350 - 310 + cy, 210 - 140 + cx, 360 - 310 + cy);
    Rectangle(hdc, 80 - 140 + cx, 360 - 310 + cy, 200 - 140 + cx, 370 - 310 + cy);
    Rectangle(hdc, 70 - 140 + cx, 350 - 310 + cy, 80 - 140 + cx, 360 - 310 + cy);
    //глаза
    Rectangle(hdc, 80 - 140 + cx, 310 - 310 + cy, 100 - 140 + cx, 320 - 310 + cy);
    Rectangle(hdc, 70 - 140 + cx, 320 - 310 + cy, 90 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 80 - 140 + cx, 340 - 310 + cy, 100 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 90 - 140 + cx, 330 - 310 + cy, 110 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 100 - 140 + cx, 320 - 310 + cy, 110 - 140 + cx, 330 - 310 + cy);
    Rectangle(hdc, 180 - 140 + cx, 310 - 310 + cy, 200 - 140 + cx, 320 - 310 + cy);
    Rectangle(hdc, 170 - 140 + cx, 320 - 310 + cy, 190 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 180 - 140 + cx, 340 - 310 + cy, 200 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 190 - 140 + cx, 330 - 310 + cy, 210 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 200 - 140 + cx, 320 - 310 + cy, 210 - 140 + cx, 330 - 310 + cy);
    Rectangle(hdc, 120 - 140 + cx, 330 - 310 + cy, 160 - 140 + cx, 350 - 310 + cy);

    //стич закраска
    HPEN hPen13;
    hPen13 = CreatePen(PS_SOLID, 4, RGB(30, 144, 255));
    SelectObject(hdc, hPen13);
    HBRUSH hBrush13;
    hBrush13 = CreateSolidBrush(RGB(30, 144, 255));
    SelectObject(hdc, hBrush13);
    Rectangle(hdc, 70 - 140 + cx, 310 - 310 + cy, 80 - 140 + cx, 320 - 310 + cy);
    Rectangle(hdc, 70 - 140 + cx, 340 - 310 + cy, 80 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 200 - 140 + cx, 310 - 310 + cy, 210 - 140 + cx, 320 - 310 + cy);
    Rectangle(hdc, 200 - 140 + cx, 340 - 310 + cy, 210 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 100 - 140 + cx, 340 - 310 + cy, 120 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 160 - 140 + cx, 340 - 310 + cy, 180 - 140 + cx, 350 - 310 + cy);
    Rectangle(hdc, 110 - 140 + cx, 300 - 310 + cy, 120 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 160 - 140 + cx, 320 - 310 + cy, 170 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 120 - 140 + cx, 300 - 310 + cy, 160 - 140 + cx, 330 - 310 + cy);
    Rectangle(hdc, 160 - 140 + cx, 280 - 310 + cy, 180 - 140 + cx, 320 - 310 + cy);
    Rectangle(hdc, 180 - 140 + cx, 290 - 310 + cy, 190 - 140 + cx, 310 - 310 + cy);
    Rectangle(hdc, 190 - 140 + cx, 300 - 310 + cy, 200 - 140 + cx, 310 - 310 + cy);
    Rectangle(hdc, 90 - 140 + cx, 290 - 310 + cy, 110 - 140 + cx, 310 - 310 + cy);
    Rectangle(hdc, 80 - 140 + cx, 300 - 310 + cy, 90 - 140 + cx, 310 - 310 + cy);
    Rectangle(hdc, 100 - 140 + cx, 280 - 310 + cy, 110 - 140 + cx, 290 - 310 + cy);
    Rectangle(hdc, 100 - 140 + cx, 310 - 310 + cy, 110 - 140 + cx, 320 - 310 + cy);
    Rectangle(hdc, 120 - 140 + cx, 270 - 310 + cy, 140 - 140 + cx, 290 - 310 + cy);
    Rectangle(hdc, 130 - 140 + cx, 260 - 310 + cy, 150 - 140 + cx, 270 - 310 + cy);
    Rectangle(hdc, 140 - 140 + cx, 270 - 310 + cy, 160 - 140 + cx, 280 - 310 + cy);
    Rectangle(hdc, 150 - 140 + cx, 280 - 310 + cy, 160 - 140 + cx, 300 - 310 + cy);
    Rectangle(hdc, 140 - 140 + cx, 290 - 310 + cy, 150 - 140 + cx, 300 - 310 + cy);

    //подбородок
    HPEN hPen14;
    hPen14 = CreatePen(PS_SOLID, 4, RGB(135, 206, 250));
    SelectObject(hdc, hPen14);
    HBRUSH hBrush14;
    hBrush14 = CreateSolidBrush(RGB(135, 206, 250));
    SelectObject(hdc, hBrush14);
    Rectangle(hdc, 80 - 140 + cx, 350 - 310 + cy, 200 - 140 + cx, 360 - 310 + cy);

    //уши стич закраска
    HPEN hPen15;
    hPen15 = CreatePen(PS_SOLID, 4, RGB(240, 128, 128));
    SelectObject(hdc, hPen15);
    HBRUSH hBrush15;
    hBrush15 = CreateSolidBrush(RGB(240, 128, 128));
    SelectObject(hdc, hBrush15);
    Rectangle(hdc, 30 - 140 + cx, 270 - 310 + cy, 50 - 140 + cx, 330 - 310 + cy);
    Rectangle(hdc, 50 - 140 + cx, 290 - 310 + cy, 60 - 140 + cx, 340 - 310 + cy);
    Rectangle(hdc, 230 - 140 + cx, 270 - 310 + cy, 250 - 140 + cx, 330 - 310 + cy);
    Rectangle(hdc, 220 - 140 + cx, 290 - 310 + cy, 230 - 140 + cx, 340 - 310 + cy);

    DeleteObject(hPen12);
    DeleteObject(hBrush12);
    DeleteObject(hPen13);
    DeleteObject(hBrush13);
    DeleteObject(hPen14);
    DeleteObject(hBrush14);
    DeleteObject(hPen15);
    DeleteObject(hBrush15);
#ifdef DEBUG_GAME  
    HPEN hPenZone = CreatePen(PS_SOLID, 2, RGB(0, 0, 0, ));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 50, cy, NULL);
    LineTo(hdc, cx + 50, cy);
    MoveToEx(hdc, cx, cy - 50, NULL);
    LineTo(hdc, cx, cy + 50);

    DeleteObject(hPenZone);


#endif 
}
void DrawYogoda(HDC hdc, int cx, int cy) {
    //контур ягоды
    HPEN hPen16;
    hPen16 = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
    SelectObject(hdc, hPen16);
    HBRUSH hBrush16;
    hBrush16 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush16);
    Rectangle(hdc, 700 - 750 + cx, 30 - 130 + cy, 730 - 750 + cx, 40 - 130 + cy);
    Rectangle(hdc, 730 - 750 + cx, 20 - 130 + cy, 740 - 750 + cx, 50 - 130 + cy);
    Rectangle(hdc, 680 - 750 + cx, 40 - 130 + cy, 700 - 750 + cx, 50 - 130 + cy);
    Rectangle(hdc, 670 - 750 + cx, 50 - 130 + cy, 680 - 750 + cx, 80 - 130 + cy);
    Rectangle(hdc, 680 - 750 + cx, 70 - 130 + cy, 700 - 750 + cx, 80 - 130 + cy);
    Rectangle(hdc, 690 - 750 + cx, 80 - 130 + cy, 700 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 700 - 750 + cx, 100 - 130 + cy, 720 - 750 + cx, 110 - 130 + cy);
    Rectangle(hdc, 720 - 750 + cx, 90 - 130 + cy, 740 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 730 - 750 + cx, 70 - 130 + cy, 740 - 750 + cx, 90 - 130 + cy);
    Rectangle(hdc, 740 - 750 + cx, 100 - 130 + cy, 760 - 750 + cx, 110 - 130 + cy);
    Rectangle(hdc, 760 - 750 + cx, 70 - 130 + cy, 770 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 770 - 750 + cx, 90 - 130 + cy, 780 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 780 - 750 + cx, 100 - 130 + cy, 800 - 750 + cx, 110 - 130 + cy);
    Rectangle(hdc, 800 - 750 + cx, 70 - 130 + cy, 810 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 810 - 750 + cx, 70 - 130 + cy, 830 - 750 + cx, 80 - 130 + cy);
    Rectangle(hdc, 820 - 750 + cx, 50 - 130 + cy, 830 - 750 + cx, 70 - 130 + cy);
    Rectangle(hdc, 800 - 750 + cx, 40 - 130 + cy, 820 - 750 + cx, 50 - 130 + cy);
    Rectangle(hdc, 770 - 750 + cx, 30 - 130 + cy, 800 - 750 + cx, 40 - 130 + cy);
    Rectangle(hdc, 760 - 750 + cx, 20 - 130 + cy, 770 - 750 + cx, 50 - 130 + cy);
    Rectangle(hdc, 740 - 750 + cx, 10 - 130 + cy, 760 - 750 + cx, 20 - 130 + cy);
    Rectangle(hdc, 830 - 750 + cx, 80 - 130 + cy, 840 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 840 - 750 + cx, 100 - 130 + cy, 850 - 750 + cx, 150 - 130 + cy);
    Rectangle(hdc, 830 - 750 + cx, 150 - 130 + cy, 840 - 750 + cx, 170 - 130 + cy);
    Rectangle(hdc, 820 - 750 + cx, 170 - 130 + cy, 830 - 750 + cx, 190 - 130 + cy);
    Rectangle(hdc, 810 - 750 + cx, 190 - 130 + cy, 820 - 750 + cx, 210 - 130 + cy);
    Rectangle(hdc, 800 - 750 + cx, 210 - 130 + cy, 810 - 750 + cx, 220 - 130 + cy);
    Rectangle(hdc, 790 - 750 + cx, 220 - 130 + cy, 800 - 750 + cx, 230 - 130 + cy);
    Rectangle(hdc, 770 - 750 + cx, 230 - 130 + cy, 790 - 750 + cx, 240 - 130 + cy);
    Rectangle(hdc, 730 - 750 + cx, 240 - 130 + cy, 770 - 750 + cx, 250 - 130 + cy);
    Rectangle(hdc, 710 - 750 + cx, 230 - 130 + cy, 730 - 750 + cx, 240 - 130 + cy);
    Rectangle(hdc, 700 - 750 + cx, 220 - 130 + cy, 710 - 750 + cx, 230 - 130 + cy);
    Rectangle(hdc, 690 - 750 + cx, 210 - 130 + cy, 700 - 750 + cx, 220 - 130 + cy);
    Rectangle(hdc, 680 - 750 + cx, 190 - 130 + cy, 690 - 750 + cx, 210 - 130 + cy);
    Rectangle(hdc, 670 - 750 + cx, 170 - 130 + cy, 680 - 750 + cx, 190 - 130 + cy);
    Rectangle(hdc, 660 - 750 + cx, 150 - 130 + cy, 670 - 750 + cx, 170 - 130 + cy);
    Rectangle(hdc, 650 - 750 + cx, 100 - 130 + cy, 660 - 750 + cx, 150 - 130 + cy);
    Rectangle(hdc, 660 - 750 + cx, 80 - 130 + cy, 670 - 750 + cx, 100 - 130 + cy);

    //ягода закраска
    HPEN hPen17;
    hPen17 = CreatePen(PS_SOLID, 4, RGB(255, 20, 147));
    SelectObject(hdc, hPen17);
    HBRUSH hBrush17;
    hBrush17 = CreateSolidBrush(RGB(255, 20, 147));
    SelectObject(hdc, hBrush17);
    Rectangle(hdc, 670 - 750 + cx, 80 - 130 + cy, 690 - 750 + cx, 110 - 130 + cy);
    Rectangle(hdc, 670 - 750 + cx, 130 - 130 + cy, 690 - 750 + cx, 170 - 130 + cy);
    Rectangle(hdc, 690 - 750 + cx, 110 - 130 + cy, 740 - 750 + cx, 150 - 130 + cy);
    Rectangle(hdc, 690 - 750 + cx, 150 - 130 + cy, 710 - 750 + cx, 210 - 130 + cy);
    Rectangle(hdc, 710 - 750 + cx, 170 - 130 + cy, 740 - 750 + cx, 210 - 130 + cy);
    Rectangle(hdc, 740 - 750 + cx, 140 - 130 + cy, 780 - 750 + cx, 180 - 130 + cy);
    Rectangle(hdc, 760 - 750 + cx, 100 - 130 + cy, 780 - 750 + cx, 140 - 130 + cy);
    Rectangle(hdc, 740 - 750 + cx, 200 - 130 + cy, 770 - 750 + cx, 240 - 130 + cy);
    Rectangle(hdc, 760 - 750 + cx, 180 - 130 + cy, 800 - 750 + cx, 200 - 130 + cy);
    Rectangle(hdc, 780 - 750 + cx, 110 - 130 + cy, 810 - 750 + cx, 150 - 130 + cy);
    Rectangle(hdc, 800 - 750 + cx, 100 - 130 + cy, 840 - 750 + cx, 110 - 130 + cy);
    Rectangle(hdc, 810 - 750 + cx, 80 - 130 + cy, 830 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 810 - 750 + cx, 130 - 130 + cy, 830 - 750 + cx, 170 - 130 + cy);
    Rectangle(hdc, 830 - 750 + cx, 110 - 130 + cy, 840 - 750 + cx, 150 - 130 + cy);
    Rectangle(hdc, 800 - 750 + cx, 150 - 130 + cy, 810 - 750 + cx, 210 - 130 + cy);
    Rectangle(hdc, 780 - 750 + cx, 170 - 130 + cy, 800 - 750 + cx, 180 - 130 + cy);
    Rectangle(hdc, 810 - 750 + cx, 170 - 130 + cy, 820 - 750 + cx, 190 - 130 + cy);
    Rectangle(hdc, 740 - 750 + cx, 110 - 130 + cy, 760 - 750 + cx, 120 - 130 + cy);
    Rectangle(hdc, 720 - 750 + cx, 100 - 130 + cy, 740 - 750 + cx, 110 - 130 + cy);
    Rectangle(hdc, 730 - 750 + cx, 150 - 130 + cy, 740 - 750 + cx, 170 - 130 + cy);
    Rectangle(hdc, 770 - 750 + cx, 200 - 130 + cy, 800 - 750 + cx, 210 - 130 + cy);
    Rectangle(hdc, 790 - 750 + cx, 210 - 130 + cy, 800 - 750 + cx, 220 - 130 + cy);
    Rectangle(hdc, 730 - 750 + cx, 210 - 130 + cy, 740 - 750 + cx, 240 - 130 + cy);
    Rectangle(hdc, 700 - 750 + cx, 210 - 130 + cy, 710 - 750 + cx, 220 - 130 + cy);
    Rectangle(hdc, 680 - 750 + cx, 170 - 130 + cy, 690 - 750 + cx, 190 - 130 + cy);
    Rectangle(hdc, 690 - 750 + cx, 100 - 130 + cy, 700 - 750 + cx, 110 - 130 + cy);
    Rectangle(hdc, 660 - 750 + cx, 100 - 130 + cy, 670 - 750 + cx, 150 - 130 + cy);

    //зелень ягоды закраска
    HPEN hPen18;
    hPen18 = CreatePen(PS_SOLID, 4, RGB(34, 139, 34));
    SelectObject(hdc, hPen18);
    HBRUSH hBrush18;
    hBrush18 = CreateSolidBrush(RGB(34, 139, 34));
    SelectObject(hdc, hBrush18);
    Rectangle(hdc, 680 - 750 + cx, 50 - 130 + cy, 700 - 750 + cx, 70 - 130 + cy);
    Rectangle(hdc, 700 - 750 + cx, 40 - 130 + cy, 720 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 720 - 750 + cx, 40 - 130 + cy, 730 - 750 + cx, 90 - 130 + cy);
    Rectangle(hdc, 730 - 750 + cx, 50 - 130 + cy, 740 - 750 + cx, 70 - 130 + cy);
    Rectangle(hdc, 740 - 750 + cx, 20 - 130 + cy, 760 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 760 - 750 + cx, 50 - 130 + cy, 770 - 750 + cx, 70 - 130 + cy);
    Rectangle(hdc, 770 - 750 + cx, 40 - 130 + cy, 780 - 750 + cx, 90 - 130 + cy);
    Rectangle(hdc, 780 - 750 + cx, 40 - 130 + cy, 800 - 750 + cx, 100 - 130 + cy);
    Rectangle(hdc, 800 - 750 + cx, 50 - 130 + cy, 820 - 750 + cx, 70 - 130 + cy);

    DeleteObject(hPen16);
    DeleteObject(hBrush16);
    DeleteObject(hPen17);
    DeleteObject(hBrush17);
    DeleteObject(hPen18);
    DeleteObject(hBrush18);
#ifdef DEBUG_GAME  
    HPEN hPenZone = CreatePen(PS_SOLID, 2, RGB(0, 0, 0, ));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 50, cy, NULL);
    LineTo(hdc, cx + 50, cy);
    MoveToEx(hdc, cx, cy - 50, NULL);
    LineTo(hdc, cx, cy + 50);

    DeleteObject(hPenZone);


#endif 
}
void DrawKnife(HDC hdc, int cx, int cy) {
    //нож контур, рукоядка
    HPEN hPen19;
    hPen19 = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
    SelectObject(hdc, hPen19);
    HBRUSH hBrush19;
    hBrush19 = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hBrush19);
    Rectangle(hdc, 900 - 930 + cx, 130 - 100 + cy, 910 - 930 + cx, 140 - 100 + cy);
    Rectangle(hdc, 910 - 930 + cx, 110 - 100 + cy, 930 - 930 + cx, 120 - 100 + cy);
    Rectangle(hdc, 910 - 930 + cx, 120 - 100 + cy, 920 - 930 + cx, 130 - 100 + cy);
    Rectangle(hdc, 930 - 930 + cx, 100 - 100 + cy, 940 - 930 + cx, 110 - 100 + cy);
    Rectangle(hdc, 940 - 930 + cx, 90 - 100 + cy, 950 - 930 + cx, 100 - 100 + cy);
    Rectangle(hdc, 950 - 930 + cx, 100 - 100 + cy, 960 - 930 + cx, 120 - 100 + cy);
    Rectangle(hdc, 940 - 930 + cx, 120 - 100 + cy, 950 - 930 + cx, 130 - 100 + cy);
    Rectangle(hdc, 930 - 930 + cx, 130 - 100 + cy, 950 - 930 + cx, 140 - 100 + cy);
    Rectangle(hdc, 910 - 930 + cx, 140 - 100 + cy, 930 - 930 + cx, 150 - 100 + cy);
    Rectangle(hdc, 960 - 930 + cx, 120 - 100 + cy, 970 - 930 + cx, 130 - 100 + cy);
    Rectangle(hdc, 970 - 930 + cx, 130 - 100 + cy, 980 - 930 + cx, 140 - 100 + cy);
    Rectangle(hdc, 980 - 930 + cx, 140 - 100 + cy, 990 - 930 + cx, 150 - 100 + cy);
    Rectangle(hdc, 990 - 930 + cx, 150 - 100 + cy, 1000 - 930 + cx, 170 - 100 + cy);
    Rectangle(hdc, 970 - 930 + cx, 160 - 100 + cy, 980 - 930 + cx, 170 - 100 + cy);
    Rectangle(hdc, 970 - 930 + cx, 170 - 100 + cy, 990 - 930 + cx, 180 - 100 + cy);
    Rectangle(hdc, 960 - 930 + cx, 150 - 100 + cy, 970 - 930 + cx, 160 - 100 + cy);
    Rectangle(hdc, 950 - 930 + cx, 140 - 100 + cy, 960 - 930 + cx, 150 - 100 + cy);

    //лезвие контур 
    HPEN hPen20;
    hPen20 = CreatePen(PS_SOLID, 4, RGB(128, 128, 128));
    SelectObject(hdc, hPen20);
    HBRUSH hBrush20;
    hBrush20 = CreateSolidBrush(RGB(128, 128, 128));
    SelectObject(hdc, hBrush20);
    Rectangle(hdc, 860 - 930 + cx, 20 - 100 + cy, 870 - 930 + cx, 70 - 100 + cy);
    Rectangle(hdc, 870 - 930 + cx, 30 - 100 + cy, 880 - 930 + cx, 40 - 100 + cy);
    Rectangle(hdc, 880 - 930 + cx, 40 - 100 + cy, 890 - 930 + cx, 50 - 100 + cy);
    Rectangle(hdc, 890 - 930 + cx, 50 - 100 + cy, 900 - 930 + cx, 60 - 100 + cy);
    Rectangle(hdc, 900 - 930 + cx, 60 - 100 + cy, 910 - 930 + cx, 70 - 100 + cy);
    Rectangle(hdc, 910 - 930 + cx, 70 - 100 + cy, 920 - 930 + cx, 80 - 100 + cy);
    Rectangle(hdc, 920 - 930 + cx, 80 - 100 + cy, 930 - 930 + cx, 90 - 100 + cy);
    Rectangle(hdc, 930 - 930 + cx, 90 - 100 + cy, 940 - 930 + cx, 100 - 100 + cy);
    Rectangle(hdc, 870 - 930 + cx, 70 - 100 + cy, 880 - 930 + cx, 80 - 100 + cy);
    Rectangle(hdc, 880 - 930 + cx, 80 - 100 + cy, 890 - 930 + cx, 90 - 100 + cy);
    Rectangle(hdc, 890 - 930 + cx, 90 - 100 + cy, 900 - 930 + cx, 100 - 100 + cy);
    Rectangle(hdc, 900 - 930 + cx, 100 - 100 + cy, 910 - 930 + cx, 110 - 100 + cy);

    //рукоядка закраска
    HPEN hPen21;
    hPen21 = CreatePen(PS_SOLID, 4, RGB(105, 105, 105));
    SelectObject(hdc, hPen21);
    HBRUSH hBrush21;
    hBrush21 = CreateSolidBrush(RGB(105, 105, 105));
    SelectObject(hdc, hBrush21);
    Rectangle(hdc, 940 - 930 + cx, 100 - 100 + cy, 950 - 930 + cx, 120 - 100 + cy);
    Rectangle(hdc, 930 - 930 + cx, 110 - 100 + cy, 940 - 930 + cx, 130 - 100 + cy);
    Rectangle(hdc, 920 - 930 + cx, 120 - 100 + cy, 930 - 930 + cx, 140 - 100 + cy);
    Rectangle(hdc, 910 - 930 + cx, 130 - 100 + cy, 920 - 930 + cx, 140 - 100 + cy);
    Rectangle(hdc, 950 - 930 + cx, 120 - 100 + cy, 960 - 930 + cx, 140 - 100 + cy);
    Rectangle(hdc, 960 - 930 + cx, 130 - 100 + cy, 970 - 930 + cx, 150 - 100 + cy);
    Rectangle(hdc, 970 - 930 + cx, 140 - 100 + cy, 980 - 930 + cx, 160 - 100 + cy);
    Rectangle(hdc, 980 - 930 + cx, 150 - 100 + cy, 990 - 930 + cx, 170 - 100 + cy);

    //закраска нож
    HPEN hPen22;
    hPen22 = CreatePen(PS_SOLID, 4, RGB(169, 169, 169));
    SelectObject(hdc, hPen22);
    HBRUSH hBrush22;
    hBrush22 = CreateSolidBrush(RGB(169, 169, 169));
    SelectObject(hdc, hBrush22);
    Rectangle(hdc, 870 - 930 + cx, 40 - 100 + cy, 880 - 930 + cx, 50 - 100 + cy);
    Rectangle(hdc, 880 - 930 + cx, 50 - 100 + cy, 890 - 930 + cx, 70 - 100 + cy);
    Rectangle(hdc, 890 - 930 + cx, 60 - 100 + cy, 900 - 930 + cx, 80 - 100 + cy);
    Rectangle(hdc, 900 - 930 + cx, 70 - 100 + cy, 910 - 930 + cx, 90 - 100 + cy);
    Rectangle(hdc, 910 - 930 + cx, 80 - 100 + cy, 920 - 930 + cx, 100 - 100 + cy);
    Rectangle(hdc, 920 - 930 + cx, 90 - 100 + cy, 930 - 930 + cx, 110 - 100 + cy);

    DeleteObject(hPen19);
    DeleteObject(hBrush19);
    DeleteObject(hPen20);
    DeleteObject(hBrush20);
    DeleteObject(hPen21);
    DeleteObject(hBrush21);
    DeleteObject(hPen22);
    DeleteObject(hBrush22);
#ifdef DEBUG_GAME  
    HPEN hPenZone = CreatePen(PS_SOLID, 2, RGB(0, 0, 0, ));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 70, cy - 70, cx + 70, cy + 70);

    MoveToEx(hdc, cx - 50, cy, NULL);
    LineTo(hdc, cx + 50, cy);
    MoveToEx(hdc, cx, cy - 50, NULL);
    LineTo(hdc, cx, cy + 50);

    DeleteObject(hPenZone);


#endif 
}

void DrawStart(HDC hdc) {
    DrawFifi(hdc, 220, 350);
    DrawStich(hdc, imStech.cx, imStech.cy);
    DrawDjevi(hdc, 1300, 550);
    DrawKnife(hdc, 1450, 550);
    DrawYogoda(hdc, imYagoda.cx, imYagoda.cy);
}

void DrawVictory(HDC hdc) {

    int y = 50;

    int i = 0;
    do {
        int x = 50;
        int j = 0;
        do {
            DrawYogoda(hdc, x, y);
            x += 200;
            j++;
        } while (j < 4 + step);
        y += 100;
        i++;
    } while (i < 1 + step);


}
void DrawLoss(HDC hdc) {

    int y = 50;

    int i = 0;
    do {
        int x = 50;
        int j = 0;
        do {
            DrawDjevi(hdc, x, y);
            x += 200;
            j++;
        } while (j < 4 + step);
        y += 100;
        i++;
    } while (i < 1 + step);

}

void DrawFinal(HDC hdc) {
    DrawFifi(hdc, 150, 400);
    DrawYogoda(hdc, imYagoda1.cx, imYagoda1.cy);
    DrawYogoda(hdc, imYagoda2.cx, imYagoda2.cy);
    DrawYogoda(hdc, imYagoda3.cx, imYagoda3.cy);
    DrawStich(hdc, 380, 450);
    DrawDjevi(hdc, 1430, 630);








    HFONT hFont = CreateFont(40, 0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(220, 20, 60));
    TCHAR strT[180] = L"Strawberry Journey. Автор игры: Кирина Дарья Евгеньевна";
    TextOut(hdc, 0, 0, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);

}
void DrawMode0(HDC hdc) {
    DrawFifi(hdc, 130, 110);
    DrawDjevi(hdc, 360, 120);
    DrawStich(hdc, 140, 310);
    DrawYogoda(hdc, 750, 130);
    DrawKnife(hdc, 930, 100);
}

typedef struct Fifi {
    int X;
    int Y;
    int Helth;
    int HasKnife;
}FIFI;
FIFI Fifi = { 100, 200, 2, 0 };

typedef struct Yogoda1 {
    int X;
    int Y;
    int Visible;
} GAMEOBJECT1;
#define NUM_YOGODAS 3 
GAMEOBJECT1 Yogoda1[NUM_YOGODAS] = {
    {600,450,1},
    {550,650,1},
    {170,128,1}
};

typedef struct GameObject2 {
    int X;
    int Y;
    int Visible;

}GAMEOBJECT2;
GAMEOBJECT2 Stich = { 1350, 400, 1 };

typedef struct GameObject3 {
    int X;
    int Y;
    int Visible;

}GAMEOBJECT3;
GAMEOBJECT3 Knife[NUM_KNIVES] = {
    {140,85,1},
    {180,85,1},
    {180,285,1}
};

typedef struct GameObject4 {
    int X;
    int Y;
    int Visible;

}GAMEOBJECT4;
GAMEOBJECT4 Djevi = { 1000, 300, 1 };


typedef struct KnifeFlying {
    int X;
    int Y;

    int VX;
    int VY;
    int Visible;
}KNIFEFLYING;
KNIFEFLYING KnifeFlying = { 0,0,30,0,0 };








void RandomMoveFox() {
    if (Djevi.Visible) {

        int dx = rand() % 21 - 10;
        int dy = rand() % 21 - 10;

        Djevi.X += dx;
        Djevi.Y += dy;
    }

}




void DrawStatus(HDC hdc);

void DrawGame(HDC hdc) {
    if (KnifeFlying.Visible) {
        DrawKnife(hdc, KnifeFlying.X, KnifeFlying.Y);
    }





    if (Djevi.Visible) {
        DrawDjevi(hdc, Djevi.X, Djevi.Y);
    }


    for (int i = 0; i < NUM_KNIVES; i++) {
        if (Knife[i].Visible) {
            DrawKnife(hdc, Knife[i].X, Knife[i].Y);
        }
    }



    for (int i = 0; i < NUM_YOGODAS; i++) {
        if (Yogoda1[i].Visible) {
            DrawYogoda(hdc, Yogoda1[i].X, Yogoda1[i].Y);
        }
    }
    if (Stich.Visible) {
        DrawStich(hdc, Stich.X, Stich.Y);
    }


    if (Fifi.Helth > 0) {
        DrawFifi(hdc, Fifi.X, Fifi.Y);
    }

    DrawStatus(hdc);
}

void TryToEatStich() {
    if (Stich.Visible) {

        if (Fifi.X - 20 < Stich.X
            && Fifi.X + 20 > Stich.X
            && Fifi.Y - 20 < Stich.Y
            && Fifi.Y + 20 > Stich.Y) {

            Stich.Visible = 0;
        }
    }
}





void TryToEatYogoda() {
    for (int i = 0; i < NUM_YOGODAS; i++) {

        if (Yogoda1[i].Visible) {
            if (Fifi.X - 20 < Yogoda1[i].X
                && Fifi.X + 20 > Yogoda1[i].X
                && Fifi.Y - 20 < Yogoda1[i].Y
                && Fifi.Y + 20 > Yogoda1[i].Y) {


                Yogoda1[i].Visible = 0;
                Fifi.Helth += 5;
            }
        }
    }
}

void ContactDjeviAndFifi() {
    if (Djevi.Visible) {
        if (Fifi.X - 20 < Djevi.X
            && Fifi.X + 20 > Djevi.X
            && Fifi.Y - 20 < Djevi.Y
            && Fifi.Y + 20 > Djevi.Y) {

            Fifi.Helth--;
        }
    }
}

void TryToTakeKnife() {
    if (!Fifi.HasKnife) {
        for (int i = 0; i < NUM_KNIVES; i++) {

            if (Knife[i].Visible) {
                if (Knife[i].X - 20 < Fifi.X
                    && Knife[i].X + 20 > Fifi.X
                    && Knife[i].Y - 20 < Fifi.Y
                    && Knife[i].Y + 20 > Fifi.Y) {

                    Knife[i].Visible = 0;

                    Fifi.HasKnife = 1;

                }
            }

        }
    }
}

void MoveKnifeFlying() {
    if (KnifeFlying.Visible) {
        KnifeFlying.X += KnifeFlying.VX;
        KnifeFlying.Y += KnifeFlying.VY;
    }
}


void ContactDjeviAndKnifeFlying() {
    if (Djevi.Visible) {
        if (KnifeFlying.Visible) {
            if (KnifeFlying.X - 20 < Djevi.X
                && KnifeFlying.X + 20 > Djevi.X
                && KnifeFlying.Y - 20 < Djevi.Y
                && KnifeFlying.Y + 20 > Djevi.Y) {

                Djevi.Visible = 0;
                KnifeFlying.Visible = 0;
            }
        }
    }
}

void ContactDjeviAndFifi1() {
    if (Djevi.Visible) {
        if (Fifi.X - 20 < Djevi.X
            && Fifi.X + 20 > Djevi.X
            && Fifi.Y - 20 < Djevi.Y
            && Fifi.Y + 20 > Djevi.Y) {

            if (Fifi.HasKnife) {
                Djevi.Visible = 0;
                Fifi.HasKnife = 0;
            }
            else {
                Fifi.Helth--;
            }
        }
    }
}

void DrawStatus(HDC hdc) {
    HFONT hFont = CreateFont(16, 0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");

    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(0, 0, 128));

    char str[180];
    sprintf_s(str, "FifiHelth = %d, FifiHasKnife = %s",
        Fifi.Helth,
        Fifi.HasKnife ? "YES" : "NO");

    TCHAR strT[180];
    OemToCharBuff(str, strT, 180);
    TextOut(hdc, 0, 0, (LPCWSTR)strT, _tcslen(strT));

    DeleteObject(hFont);
}
void fon(HDC hdc) {
    HBRUSH hBrush = CreateSolidBrush(RGB(88, 166, 109));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, -1, -1, 1920, 1080);
    DeleteObject(hBrush);
}
void KeepGame() {
    FILE* fout;
    fopen_s(&fout, "GameState.txt", "wt");
    if (fout == NULL) {
        return;
    }
    fprintf(fout, "%d %d %d %d\n", Fifi.X, Fifi.Y, Fifi.Helth, Fifi.HasKnife);
    for (int i = 0; i < NUM_YOGODAS; i++) {
        fprintf(fout, "%d %d %d\n", Yogoda1[i].X, Yogoda1[i].Y, Yogoda1[i].Visible);
    }
    fprintf(fout, "\n\n\n");

    for (int i = 0; i < NUM_KNIVES; i++) {
        fprintf(fout, "%d %d %d\n", Knife[i].X, Knife[i].Y, Knife[i].Visible);
    }
    fprintf(fout, "\n\n\n");
    fprintf(fout, "%d %d %d \n", Djevi.X, Djevi.Y, Djevi.Visible);

    fprintf(fout, "\n\n\n");

    fprintf(fout, "%d %d %d %d %d\n", KnifeFlying.X, KnifeFlying.Y, KnifeFlying.VX, KnifeFlying.VY, KnifeFlying.Visible);

    fprintf(fout, "%d %d %d\n", Stich.X, Stich.Y, Stich.Visible);

    fclose(fout);


}
void LoadGame() {
    mode = GAME;
    FILE* fin;
    fopen_s(&fin, "GameState.txt", "rt");
    if (fin == NULL) {
        return;
    }

    fscanf_s(fin, "%d %d %d %d\n", &Fifi.X, &Fifi.Y, &Fifi.Helth, &Fifi.HasKnife);
    for (int i = 0; i < NUM_YOGODAS; i++) {
        fscanf_s(fin, "%d %d %d\n", &Yogoda1[i].X, &Yogoda1[i].Y, &Yogoda1[i].Visible);
    }

    for (int i = 0; i < NUM_KNIVES; i++) {
        fscanf_s(fin, "%d %d %d\n", &Knife[i].X, &Knife[i].Y, &Knife[i].Visible);
    }
    fscanf_s(fin, "%d %d %d \n", &Djevi.X, &Djevi.Y, &Djevi.Visible);


    fscanf_s(fin, "%d %d %d %d %d\n", &KnifeFlying.X, &KnifeFlying.Y, &KnifeFlying.VX, &KnifeFlying.VY, &KnifeFlying.Visible);

    fscanf_s(fin, "%d %d %d\n", &Stich.X, &Stich.Y, &Stich.Visible);

    fclose(fin);
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_CREATE:
        SetTimer(hWnd, 1, 100, NULL);
        break;
    case WM_TIMER:
        if (mode == START) {
            imYagoda.cx += imYagoda.vx;
            imYagoda.cy += imYagoda.vy;
            imStech.cy += imStech.vy;
            if (imYagoda.cx == 1000 && imYagoda.cy == 200) {
                imYagoda.vx = 0;
                imYagoda.vy = 10;
            }
            if (imYagoda.cx == 1000 && imYagoda.cy == 500) {
                imYagoda.vx = -10;
                imYagoda.vy = 0;
            }
            if (imYagoda.cx == 680 && imYagoda.cy == 500) {
                imYagoda.vx = 0;
                imYagoda.vy = -10;
            }
            if (imYagoda.cx == 680 && imYagoda.cy == 200) {
                imYagoda.vx = 10;
                imYagoda.vy = 0;
            }
            if (imStech.cy == 900) {
                imStech.vy = -10;
            }
            if (imStech.cy == 630) {
                imStech.vy = 10;
            }
        }
        if (mode == FINAL) {

            imYagoda1.cy += imYagoda1.vy;
            imYagoda2.cy += imYagoda2.vy;
            imYagoda3.cy += imYagoda3.vy;

            if (imYagoda1.cy == 950) {
                imYagoda1.vy = -10;
            }
            if (imYagoda2.cy == 950) {
                imYagoda2.vy = -10;
            }
            if (imYagoda3.cy == 950) {
                imYagoda3.vy = -10;
            }
            if (imYagoda1.cy == 650) {
                imYagoda1.vy = 10;
            }
            if (imYagoda2.cy == 650) {
                imYagoda2.vy = 10;
            }
            if (imYagoda3.cy == 650) {
                imYagoda3.vy = 10;
            }

        }



        ContactDjeviAndFifi1();
        ContactDjeviAndKnifeFlying();
        MoveKnifeFlying();
        TryToTakeKnife();
        TryToEatStich();
        RandomMoveFox();
        if (mode == GAME) {
            if (Stich.Visible == 0) {

            }
        }





        if (mode == GAME) {
            if (Yogoda1[0].Visible == 0 && Yogoda1[1].Visible == 0 && Yogoda1[2].Visible == 0) {
                mode = VICTORY;
            }

        }
        else if (mode == VICTORY || mode == LOSS) {
            step++;
            if (step > 10)
                mode = FINAL;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_KEYDOWN:
        if (mode == START) {
            mode = GAME;
        }
        else if (mode == GAME) {
            switch (wParam)
            {
            case VK_SPACE:
                if (Fifi.HasKnife) {
                    Fifi.HasKnife = 0;
                    KnifeFlying.Visible = 1;
                    KnifeFlying.X = Fifi.X;
                    KnifeFlying.Y = Fifi.Y;
                }
                break;
            case 0x4B://k
                KeepGame();
                break;
            case 0x4c://l
                LoadGame();
                break;
            case VK_UP:
                Fifi.Y -= 10;
                break;
            case VK_DOWN:
                Fifi.Y += 10;
                break;
            case VK_LEFT:
                Fifi.X -= 10;
                break;
            case VK_RIGHT:
                Fifi.X += 10;
                break;
            }
            TryToEatYogoda();
            ContactDjeviAndFifi();
            if (Fifi.Helth < 1) {
                mode = LOSS;
            }
            break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        fon(hdc);
        if (mode == START)
            DrawStart(hdc);
        if (mode == GAME)
            DrawGame(hdc);
        if (mode == VICTORY)
            DrawVictory(hdc);
        if (mode == LOSS)
            DrawLoss(hdc);
        if (mode == FINAL)
            DrawFinal(hdc);




        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return 0;
    }
}


// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
