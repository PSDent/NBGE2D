#pragma once

#include "System.h"
#include "Graphics.h"
#include "Input.h"
#include "FPS.h"
#include "Audio.h"
#include "Physics.h"
#include "Timer.h"

class Engine
{
public:
	Engine();

	LRESULT MsgHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void Init(HWND hwnd);

	void Run(HWND hWnd);

	virtual ~Engine();

private:
	System *system;
	Graphics *graphic; 
	Input *input;
	FPS *fps;
	Timer *timer;	
};

