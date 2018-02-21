#include "Engine.h"

Engine::Engine()
{
	system = NULL;
	graphic = NULL;
	input = NULL;
	fps = NULL;
	timer = NULL;
}

Engine::~Engine()
{

}

LRESULT Engine::MsgHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, msg, wParam, lParam);

}

void Engine::Init(HWND hWnd)
{
	system = new System;
	system->SetUpSystem(hWnd);

	input = new Input;
	input->Init();

	return;
}

void Engine::Run(HWND hWnd)
{

} 