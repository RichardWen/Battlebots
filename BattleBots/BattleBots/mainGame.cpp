#include <Windows.h>
#include <WindowsX.h>
#include "Graphics.h"

#include "InGame.h"
#include "GameControl.h"
Graphics* graphics;

bool beginUpdateLane1 = false;
bool beginUpdateLane2 = false;
bool beginUpdateLane3 = false;
bool beginUpdateLane4 = false;
bool beginUpdateLane5 = false;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	RAWINPUTDEVICE rID[2];
	int xPos = GET_X_LPARAM(lParam);
	int yPos = GET_Y_LPARAM(lParam);
	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}
	else if (uMsg == WM_LBUTTONDOWN && yPos < 100) {
		 beginUpdateLane5 = false;
		 beginUpdateLane2 = false;
		 beginUpdateLane3 = false;
		 beginUpdateLane4 = false;
		beginUpdateLane1 = true;

	}
	else if (uMsg == WM_LBUTTONDOWN && yPos >= 100 && yPos < 200) {
		beginUpdateLane5 = false;
		beginUpdateLane1 = false;
		beginUpdateLane3 = false;
		beginUpdateLane4 = false;
		beginUpdateLane2 = true;

	}
	else if (uMsg == WM_LBUTTONDOWN && yPos >= 200 && yPos < 300) {
		beginUpdateLane5 = false;
		beginUpdateLane2 = false;
		beginUpdateLane1 = false;
		beginUpdateLane4 = false;
		beginUpdateLane3 = true;

	}
	else if (uMsg == WM_LBUTTONDOWN && yPos >= 300 && yPos < 400) {
		beginUpdateLane5 = false;
		beginUpdateLane2 = false;
		beginUpdateLane3 = false;
		beginUpdateLane1 = false;
		beginUpdateLane4 = true;

	}
	else if (uMsg == WM_LBUTTONDOWN) {
		beginUpdateLane1 = false;
		beginUpdateLane2 = false;
		beginUpdateLane3 = false;
		beginUpdateLane4 = false;
		beginUpdateLane5 = true;

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
		else if(beginUpdateLane1){
			graphics->BeginDraw();
			GameControl::Update();
			GameControl::Render(1);
			graphics->EndDraw();
			}
		else if (beginUpdateLane2){
			graphics->BeginDraw();
			GameControl::Update();
			GameControl::Render(2);
			graphics->EndDraw();
		}
		else if (beginUpdateLane3){
			graphics->BeginDraw();
			GameControl::Update();
			GameControl::Render(3);
			graphics->EndDraw();
		}
		else if (beginUpdateLane4){
			graphics->BeginDraw();
			GameControl::Update();
			GameControl::Render(4);
			graphics->EndDraw();
		}
		else if (beginUpdateLane5){
			graphics->BeginDraw();
			GameControl::Update();
			GameControl::Render(5);
			graphics->EndDraw();
		}
		else {
		}
	}
	delete graphics;
	return 0;
}

