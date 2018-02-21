#include "System.h"

System::System()
{
	m_screenWidth	= GetSystemMetrics(SM_CXSCREEN);
	m_screenHeight	= GetSystemMetrics(SM_CYSCREEN);
	m_prevFullScreen = m_isFullScreen = false;
	m_prevIsVsync = m_isVsync = true;
}


System::~System()
{
}

void System::GetWindowedSize(int &width, int &height) {
	width = m_WINDOW_WIDTH;
	height = m_WINDOW_HEIGHT;
	return;
}

void System::GetFullSize(int &width, int &height) {
	width = m_screenWidth;
	height = m_screenHeight;
	return;
}

bool System::GetWindowedMode() {
	return m_isFullScreen;
}

void System::SetUpSystem(HWND &hWnd)
{
	if (m_prevFullScreen != m_isFullScreen)
		SetWndSize(hWnd);

	if (m_prevIsVsync != m_isVsync)
		SetVsync();

	return;
}

void System::SetWndSize(HWND &hWnd)
{
	DEVMODE devSet;

	if (!m_isFullScreen) {
		int xpos = (m_screenWidth - m_WINDOW_WIDTH) / 2;
		int ypos = (m_screenHeight - m_WINDOW_HEIGHT) / 2;

		MoveWindow(hWnd, xpos, ypos, m_WINDOW_WIDTH, m_WINDOW_HEIGHT, TRUE);
	}
	else {
		memset(&devSet, 0, sizeof(devSet));

		devSet.dmSize = sizeof(devSet);
		devSet.dmPelsWidth = (unsigned long)m_screenWidth;
		devSet.dmPelsHeight = (unsigned long)m_screenHeight;
		devSet.dmBitsPerPel = 32;
		devSet.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&devSet, CDS_FULLSCREEN);

		MoveWindow(hWnd, 0, 0, m_screenWidth, m_screenHeight, TRUE);
	}
	return;
}

void System::SetVsync()
{
	if (m_isVsync);

	else

	return;
}