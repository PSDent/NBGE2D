#include "WinMain.h"

// Entry Point of Program.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
// Check Memory Leaks if turned on Debug build.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	
	InitWnd(hInstance, nCmdShow);

	MSG Message = { 0 };
	while (WM_QUIT != Message.message)
	{
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else {
		}
	}

	return (int)Message.wParam;

}

// Window Procedure (Window Event)
LRESULT CALLBACK WinProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//return 
}

// Initialize Window and Create.
int InitWnd(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wndEx;
	int xpos = 0, ypos = 0;
	int width, height;

	wndEx.cbSize = sizeof(WNDCLASSEX);
	wndEx.cbClsExtra = 0;
	wndEx.cbWndExtra = 0;
	wndEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndEx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndEx.hIconSm = NULL;
	wndEx.hInstance = hInstance;
	wndEx.lpfnWndProc = WinProc;
	wndEx.lpszClassName = title;
	wndEx.lpszMenuName = NULL;
	wndEx.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	RegisterClassEx(&wndEx);

	// if window mode 
	if (!GameSystem->GetWindowedMode()) { 
		GameSystem->GetWindowedSize(width, height);

		GameSystem->GetFullSize(xpos, ypos);
		xpos = (xpos - width) / 2;
		ypos = (ypos - height) / 2;
	}
	// if Fullscreen mode 
	else
		GameSystem->GetFullSize(width, height);

	g_hWnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		title,
		title,
		WS_OVERLAPPED,// | WS_CAPTION,
		xpos,
		ypos,
		width,
		height,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	if (!g_hWnd)
		return false;

	ShowWindow(g_hWnd, nCmdShow);

	return S_OK;
}

