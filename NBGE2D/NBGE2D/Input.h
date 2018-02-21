#pragma once
#include <Windows.h>

#define DIRECTINPUT_VERTSION 0x0800

class Input
{
public:
	Input();
	~Input();

	bool Init(HINSTANCE, HWND, int, int);
	void Release();
	void Frame();

private:


};

