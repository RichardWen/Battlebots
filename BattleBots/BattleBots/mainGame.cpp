#include <Windows.h>
#include "Graphics.h"

#include "InGame.h"
#include "GameControl.h"
Graphics* graphics;
bool beginUpdate = false;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	RAWINPUTDEVICE rID[2];
	
	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}
	else if (uMsg == WM_LBUTTONUP) {
		beginUpdate = true;
	}
	
	
	DefWindowProc(hwnd, uMsg, wParam, lParam);
	
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCMDShow) {
	WNDCLASSEX gameWindow;
	ZeroMemory(&gameWindow, sizeof(WNDCLASSEX));
	gameWindow.cbSize = sizeof(WNDCLASSEX);
	gameWindow.hbrBackground = (HBRUSH)COLOR_WINDOW;
	gameWindow.hInstance = hInstance;
	gameWindow.lpfnWndProc = WindowProc;
	gameWindow.lpszClassName = "Battlebots";
	gameWindow.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&gameWindow);

	RECT rect = { 0, 0, 1000, 500 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "Battlebots", "Alpha", WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);
	
	if (!windowHandle) {
		return -1;
	}
	
	graphics = new Graphics(); 
	if (!graphics->Init(windowHandle)) {
		delete graphics;
		return -1;
	}

	GameState::Init(graphics);

	ShowWindow(windowHandle, nCMDShow);

	GameControl::LoadInitialState(new InGame());

	MSG message;
	message.message = WM_NULL;
	while (message.message != WM_QUIT) {
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&message);
		}
		else if(beginUpdate){
			graphics->BeginDraw();
			GameControl::Update();
			GameControl::Render();
			graphics->EndDraw();
			}
	
	}
	delete graphics;
	return 0;
}

