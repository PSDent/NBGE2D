#pragma once

//===========
// DEFINE
//===========
#define _CRTDBG_MAP_ALLOC	// Detecting Memory Leaks

//============
// INCLUDE
//============
#include <stdlib.h>
#include <crtdbg.h>
#include <Windows.h>

#include "System.h"

//===========
// GLOBAL
//===========
HWND g_hWnd;
LPCWSTR title = L"Engine";
System *GameSystem = NULL;

//=====================
// Function ProtoType
//=====================

// Entry Point of Program.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

// Window Procedure (Window Event)
LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Initialize Window and Create.
int InitWnd(HINSTANCE hInstance, int nCmdShow);