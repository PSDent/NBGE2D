#pragma once
#include <Windows.h>

class System
{
public:
	System();
	~System();

public:
	void SetUpSystem(HWND &hWnd);

	bool GetWindowedMode();
	void GetWindowedSize(int &width, int &height);
	void GetFullSize(int &width, int &height);

private:
	void SetWndSize(HWND &hWnd);
	void SetVsync();

private:
	int m_screenWidth, m_screenHeight;
	bool m_isFullScreen, m_prevFullScreen;
	bool m_isVsync, m_prevIsVsync;

	//===========
	// CONSTANT
	//===========
	const int m_WINDOW_WIDTH = 1280;
	const int m_WINDOW_HEIGHT = 800;
};

