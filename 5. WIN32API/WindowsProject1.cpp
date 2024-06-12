// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject1.h"
#include <list>
#include <math.h>
#define MAX_LOADSTRING 100
//==============================================
typedef struct _tagRectangle
{
    float left, top, right, bottom;
}RECTANGLE, *PRECTANGLE;

typedef struct _tagSphere
{
    float x, y; 
    float r; 
}SPHERE, *PSPHERE;

typedef struct _tagBullet {
    SPHERE sp;
    float fDist; 
    float fLimitDist;
    float fAngle; 
}BULLET, *PBULLET;

typedef struct _tagMonster {
    SPHERE sp;
    float fSpeed; 
    float fTime; 
    float fLimitTime; 
    int iDir;
}MONSTER, *PMONSTER;

#define Pi 3.14159f 

//==============================================
// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND g_hwnd;
bool g_bLoop = true;
HDC  g_hdc; //무언가를 출력할 때는 HDC가 필요하다.

// 시간을 구하기 위한 
LARGE_INTEGER g_tSecond; 
LARGE_INTEGER g_tTime; 
float         g_fDeletaTime;
SPHERE g_Player = {100, 100, 50}; //Long타입은 정수임. 
std::list<BULLET> g_PlayerBulletList; //플레이어 총알
POINT   g_GunPos; 
float   g_GunLen = 70.f;
float   g_PlayerAngle; 
MONSTER g_tMonster; 
std::list<BULLET> g_MonsterBulletList; 
                                      
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

struct _tagArea
{
    bool bStart;
    POINT ptStart; 
    POINT ptEnd;
};

_tagArea g_tArea; 

void Run();
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    //화면 DC 생성
    g_hdc = GetDC(g_hwnd); 

    g_GunPos.x = g_Player.x + cosf(g_PlayerAngle) * g_GunLen; 
    g_GunPos.y = g_Player.y + sinf(g_PlayerAngle) * g_GunLen;

    
    g_tMonster.sp.x = 800.f - 50.f;
    g_tMonster.sp.y = 50.f;
    g_tMonster.sp.r = 25.0f;
    g_tMonster.fSpeed = 300.f;
    g_tMonster.fTime = 0.0f;
    g_tMonster.fLimitTime = 2.5;
    g_tMonster.iDir = 0; 

    //플레이어 총구의 위치를 구해준다. 

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;
    QueryPerformanceFrequency(&g_tSecond);
    QueryPerformanceCounter(&g_tTime); 

    // 기본 메시지 루프입니다:
    while (g_bLoop)
    { 
        //PeekMessage는 메세지가 메세지큐에 없어도 바로 빠져나온다.
        //true: 메세지가 있을 경우
        //false: 메세지가 없을 경우
        //메세지가 없는 시간이 윈도우의 데드타임이다.
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else //윈도우 데드타임일 경우 이벤트가 발생하지 않은 경우 
        {
            Run(); 
        }
    }
    ReleaseDC(g_hwnd, g_hdc); //루프 끝나면 꼭 릴리즈 DC
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   g_hwnd = hWnd;
   //실제로 윈도우 타이틀이나 메뉴를 포함한 윈도우의 크기를 구해준다
   RECT rc = { 0, 0, 800, 600 };
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
   //위에서 구해준 크기로 윈도우 클라이언트 영역의 크기를 원하는 크기호 맞춰줘야 한다.
   SetWindowPos(hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER); 
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
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

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd); 
            break; 
        default:
            break;
        }
        // 마우스 왼쪽버튼을 눌렸을 때 들어온다.
        // 마우스 위치는 IParam에 들어오게 되는데 16비트를 쪼개서 x, y값이 32비트 변수에 들어오게 된다.
        // LOWORD, HIWORD 매크로를 이용해서 하위, 상위 16비트의 값을 얻어올 수 있다.
    case WM_LBUTTONDOWN:
        if (!g_tArea.bStart)
        {
            g_tArea.bStart = true; 
            // 만약 iParam & 0x12345678 일때 결과는 5678
            g_tArea.ptStart.x = lParam & 0x0000ffff; 
            g_tArea.ptStart.y = lParam >> 16; //1234..
            // 마우스를 클릭할 때 강제로 wm_point메세지를 호출해지는 함수
            InvalidateRect(hWnd, NULL, TRUE);
            // 1.윈도우 핸들
            // 2. 갱신할 영역 
            // NULL: 전체화면을 대상으로 갱신
            // 3. True일경우 현재 화면을 지우고 갱신 False 일 경우 현재 화면을 안지우고 갱신
            
        }
        break;

    case WM_MOUSEMOVE:
        if (g_tArea.bStart)
        {
            g_tArea.ptEnd.x = lParam & 0x0000ffff;
            g_tArea.ptEnd.y = lParam >> 16; //1234..
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break; 
    case WM_LBUTTONUP:
        if (g_tArea.bStart)
        {
            g_tArea.bStart = false;
            g_tArea.ptEnd.x = lParam & 0x0000ffff;
            g_tArea.ptEnd.y = lParam >> 16; //1234..
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // 유니코드 문자열은 " "앞에 L을 붙여서 L" "로 하거나 
            // TEXT 매크로(unicode, multibytecode인지 구분)를 이용한다. 
            TextOut(hdc, 50, 50, L"win32", 5);

            //Rectangle(hdc, 100, 100, 200, 200);

            //MoveToEx(hdc, 300, 100, NULL); 
            //LineTo(hdc, 400, 150);
            //LineTo(hdc, 500, 100); 
            ////이전의 끝점이 Start가 되니깐 새로운 점을 얻고 싶을 때는 MoveToEx를 실행 해준다.
            //
            //MoveToEx(hdc, 500, 200, NULL);
            //LineTo(hdc, 500, 150);

            //Ellipse(hdc, 100, 100, 200, 200);

            //if (g_tArea.bStart)
            //{
            //    Rectangle(hdc, g_tArea.ptStart.x, g_tArea.ptStart.y, g_tArea.ptEnd.x, g_tArea.ptEnd.y);
            //    
            //}

            // 마우스 위치를 출력해보자 
            //TCHAR strMouse[64] = {};
            //// 유니코드 문자열을 만들어 주는 함수 : wsprintf
            //wsprintf(strMouse, TEXT("x: %d, y: %d"), g_tArea.ptStart.x, g_tArea.ptStart.y);
            //// lstrlen : 유니코드 문자열의 길이를 구하는것 
            //TextOut(hdc, 600, 30, strMouse, lstrlen(strMouse));

            EndPaint(hWnd, &ps);
        }
        break;
        // 윈도우를 종료시킬때 들어오는 메세지이다.
    case WM_DESTROY:
        g_bLoop = false; 
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
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

void Run()
{
    // DeltaTime을 구한다. Frame과 Frame 사이의 시간을 DeltaTime이라고 부름
    LARGE_INTEGER tTime; 
   // QueryPerformanceFrequency(&g_tSecond);
    QueryPerformanceCounter(&tTime);
    float fTimeScale = 0;
    g_fDeletaTime = (tTime.QuadPart - g_tTime.QuadPart) / (float)g_tSecond.QuadPart; 
    
    fTimeScale += g_fDeletaTime;
    if (fTimeScale > 1.0f)
        fTimeScale = 1.0f;

    g_tTime = tTime;

    //플레이어 초당 이동속도 : 300
    float fSpeed = 300 * g_fDeletaTime;
    
    
    if (GetAsyncKeyState('D') & 0x8000)
    {
        //초당 180도 돌아가게 한거임.
        g_PlayerAngle += Pi * fSpeed;
    }
    if (GetAsyncKeyState('A') & 0x8000)
    {
        g_PlayerAngle -= Pi * fSpeed;
    }
    if (GetAsyncKeyState('W') & 0x8000)
    {
        g_Player.x += fSpeed * cosf(g_PlayerAngle);
        g_Player.y += fSpeed * sinf(g_PlayerAngle);
    }
    if (GetAsyncKeyState('S') & 0x8000)
    {
        g_Player.x -= fSpeed * cosf(g_PlayerAngle);
        g_Player.y -= fSpeed * sinf(g_PlayerAngle);
    }
    if (GetAsyncKeyState('1') & 0x8000)
    {
        float fAngle = 0; 

        for (int i = 0; i < 36; ++i)
        {
            BULLET rcBullet;
            rcBullet.sp.x = g_GunPos.x + cosf(fAngle) * 25.f;
            rcBullet.sp.y = g_GunPos.y + sinf(fAngle) * 25.f;
            rcBullet.sp.r = 25.f;
            rcBullet.fDist = 0;
            rcBullet.fLimitDist = 500;
            rcBullet.fAngle = fAngle;
            fAngle += Pi / 18;
            g_PlayerBulletList.push_back(rcBullet);
        }
    }

    //총구 위치를 구한다.
    g_GunPos.x = g_Player.x + cosf(g_PlayerAngle) * g_GunLen;
    g_GunPos.y = g_Player.y + sinf(g_PlayerAngle) * g_GunLen;


    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        BULLET rcBullet;
        rcBullet.sp.x = g_GunPos.x + cosf(g_PlayerAngle) * 25.f;
        rcBullet.sp.y = g_GunPos.y + sinf(g_PlayerAngle) * 25.f;
        rcBullet.sp.r = 25.f; 
        rcBullet.fDist = 0; 
        rcBullet.fLimitDist = 500; 
        rcBullet.fAngle = g_PlayerAngle;

        g_PlayerBulletList.push_back(rcBullet);
    }
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
        // 마우스 위치를 얻어온다. 
        POINT ptMouse;
        GetCursorPos(&ptMouse);
        // 스크린 좌쵸를 클라이언트 좌표로 변환한다.
        ScreenToClient(g_hwnd, &ptMouse);
        // 플레이어와 충돌처리한다.
        if (g_Player.x - g_Player.r <= ptMouse.x &&
            ptMouse.x <= g_Player.x + g_Player.r &&
            g_Player.y - g_Player.r <= ptMouse.y &&
            ptMouse.y <= g_Player.y + g_Player.r)
            MessageBox(NULL, L"플레이어 클릭", L"마우스 클릭", MB_OK);

        float fMX = g_tMonster.sp.x - ptMouse.x; 
        float fMY = g_tMonster.sp.y - ptMouse.y; 
        float fMDist = sqrtf(fMX * fMX + fMY * fMY);
        if(g_tMonster.sp.r >= fMDist) 
            MessageBox(NULL, L"몬스터 클릭", L"마우스 클릭", MB_OK);
    }
    
    RECT rcWindow; 
    // GetWindowRect(g_hwnd, &rcWindow); 타이틀이랑 모든걸 포함한
    GetClientRect(g_hwnd, &rcWindow);

    if (g_Player.x - g_Player.r < rcWindow.left)
    {
        g_Player.x = rcWindow.left + 100;
    }
    else if (g_Player.x + g_Player.r > rcWindow.right)
    {
        g_Player.x = rcWindow.right - 100;
    }
    else if (g_Player.y - g_Player.r < rcWindow.top)
    {
        g_Player.y = rcWindow.top + 100;
    }
    else if (g_Player.y + g_Player.r > rcWindow.bottom )
    {
        g_Player.y = rcWindow.bottom - 100;
    }

    Ellipse(g_hdc, g_Player.x - g_Player.r, g_Player.y - g_Player.r,
        g_Player.x + g_Player.r, g_Player.y + g_Player.r);
    g_tMonster.sp.y += g_tMonster.fSpeed * g_fDeletaTime * g_tMonster.iDir; 

    if (g_tMonster.sp.y + g_tMonster.sp.r >= 600) {
        g_tMonster.iDir = -1; 
        g_tMonster.sp.y = 600;

    }
    else if (g_tMonster.sp.y + g_tMonster.sp.r <= 0) {
        g_tMonster.iDir = 1;
        g_tMonster.sp.y = 100;
    }

    //몬스터 통알 발사 로직
    g_tMonster.fTime += g_fDeletaTime; 

    if (g_tMonster.fTime >= g_tMonster.fLimitTime) {
        g_tMonster.fTime -= g_tMonster.fLimitTime; 
    }

    BULLET rcBullet;
    rcBullet.sp.x = g_tMonster.sp.x - g_tMonster.sp.r - 20;
    rcBullet.sp.y = g_tMonster.sp.y ;
    rcBullet.sp.r = 20.f;
    rcBullet.fDist = 0;
    rcBullet.fLimitDist = 500;

    g_MonsterBulletList.push_back(rcBullet);


    std::list<BULLET>::iterator iter;
    std::list<BULLET>::iterator iterEnd = g_PlayerBulletList.end();
    fSpeed = 600.0f * g_fDeletaTime;
    for (iter = g_PlayerBulletList.begin(); iter != iterEnd;)
    {
        (*iter).sp.x += cosf((*iter).fAngle) *fSpeed;
        (*iter).sp.y += sinf((*iter).fAngle) * fSpeed;

        
        (*iter).fDist += fSpeed;
        float fx = (*iter).sp.x - g_tMonster.sp.x;
        float fy = (*iter).sp.y - g_tMonster.sp.y; 
        float fDist = sqrtf(fx * fx + fy * fy);
        //몬스터와 충돌처리
        if (fDist <= (*iter).sp.r + g_tMonster.sp.r)
        {
            iter = g_PlayerBulletList.erase(iter);
            iterEnd = g_PlayerBulletList.end();
        }

        else if ((*iter).fDist >= (*iter).fLimitDist)
        {
            iter = g_PlayerBulletList.erase(iter);
            iterEnd = g_PlayerBulletList.end();
        }
        else if (800 < (*iter).sp.x - (*iter).sp.r)
        {
            iter = g_PlayerBulletList.erase(iter);
            iterEnd = g_PlayerBulletList.end();
        }
       
        else {
            ++iter;
        }
        
    }
    //몬스터 총알
    iterEnd = g_MonsterBulletList.end();
    for (iter = g_MonsterBulletList.begin(); iter != iterEnd;)
    {
        (*iter).sp.x -= fSpeed;
        //(*iter).rc.right -= fSpeed;
        (*iter).fDist += fSpeed;
        if ((*iter).fDist >= (*iter).fLimitDist)
        {
            iter = g_MonsterBulletList.erase(iter);
            iterEnd = g_MonsterBulletList.end();
        }
        else if (800 < (*iter).sp.x - (*iter).sp.r)
        {
            iter = g_MonsterBulletList.erase(iter);
            iterEnd = g_MonsterBulletList.end();
        }
        else if (g_Player.x - g_Player.r <= (*iter).sp.x - (*iter).sp.r &&
            (*iter).sp.x - (*iter).sp.r <= g_Player.x + g_Player.r &&
            g_Player.y - g_Player.r <= (*iter).sp.y + (*iter).sp.r &&
            (*iter).sp.y - (*iter).sp.r <= g_Player.y + g_Player.r
            )
        {
            iter = g_MonsterBulletList.erase(iter);
            iterEnd = g_MonsterBulletList.end();
        }
        else
        {
            ++iter;

        }

    }
    Ellipse(g_hdc, g_tMonster.sp.x - g_tMonster.sp.r, g_tMonster.sp.y - g_tMonster.sp.r,
        g_tMonster.sp.x + g_tMonster.sp.r, g_tMonster.sp.y + g_tMonster.sp.r);

    MoveToEx(g_hdc, g_Player.x, g_Player.y, NULL);
    LineTo(g_hdc, g_GunPos.x, g_GunPos.y);
    iterEnd = g_MonsterBulletList.end();
    for (iter = g_MonsterBulletList.begin(); iter != iterEnd; ++iter)
    {
        Ellipse(g_hdc, (*iter).sp.x - (*iter).sp.r, (*iter).sp.y - (*iter).sp.r,
            (*iter).sp.x + (*iter).sp.r, (*iter).sp.y + (*iter).sp.r);
   

    }
    iterEnd = g_PlayerBulletList.end();
    for (iter = g_PlayerBulletList.begin(); iter != iterEnd; ++iter)
    {
        Ellipse(g_hdc, (*iter).sp.x - (*iter).sp.r, (*iter).sp.y - (*iter).sp.r,
            (*iter).sp.x + (*iter).sp.r, (*iter).sp.y + (*iter).sp.r);

    }
}