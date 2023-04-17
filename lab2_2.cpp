#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <list>
#include <cmath>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
#define MAX_LOADSTRING 100
int APIENTRY WinMain(HINSTANCE This, HINSTANCE Prev, LPSTR cmd, int mode)
{
    HWND hwnd;
    MSG msg;
    WNDCLASS wc{};
    wc.hInstance = This;
    wc.lpszClassName = WinName;
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    if (!RegisterClass(&wc))
    {
        return 0;
    }

    hwnd = CreateWindow(WinName, _T("Каркас Windows-приложения"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_DESKTOP, NULL, This, NULL);

    ShowWindow(hwnd, mode);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
class Shape
{
public:
    Shape() {};
    virtual void Draw(HDC hdc) = 0;
    virtual ~Shape() {};
};

class Circle : public Shape
{
public:
    Circle(int center, int radius) : startCoord_{ center - radius }, endCoord_{ center + radius }
    {}
    void Draw(HDC hdc)
    {
        Ellipse(hdc, startCoord_, 0, endCoord_, endCoord_);
    }

private:
    const int startCoord_; const int endCoord_;
};

class Rect : public Shape
{
public:
    // Конструктор из условия
    Rect(int start, int width, int height) :
        startCoord_{ start }, rightCoord_{ startCoord_ + width }, bottomCoord_{ height }
    {}

    void Draw(HDC hdc)
    {
        Rectangle(hdc, startCoord_, 0, rightCoord_, bottomCoord_);
    }

private:
    const int startCoord_;
    const int rightCoord_;
    const int bottomCoord_;
};

std::vector<Shape*> figuresStorage;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    int x{}, y{};
    static int startx, starty, step, lenght, sx, sy;
    switch (message)
    {
    case WM_CREATE:
        figuresStorage.push_back(new Circle(200, 200));
        figuresStorage.push_back(new Rect(500, 300, 400));
        break;
    case WM_SIZE:
        sx = LOWORD(wParam);
        sy = LOWORD(lParam);
        break;
    case WM_PAINT:
        // Рисование окружности  и прямоугольника
        hdc = BeginPaint(hWnd, &ps);
        for (std::vector <Shape*>::iterator iter = figuresStorage.begin(); iter != figuresStorage.end(); ++iter)
        {
            (*iter)->Draw(hdc);
        }
        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        for (std::vector <Shape*>::iterator iter = figuresStorage.begin(); iter != figuresStorage.end(); ++iter)
        {
            delete (*iter);
        }
        figuresStorage.clear();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
