#pragma once

#include <Windows.h>
#include <d2d1.h>

class Graphics {
	ID2D1Factory *factory;
	ID2D1HwndRenderTarget *renderTarget;
	ID2D1SolidColorBrush *brush;

public:
	Graphics();
	~Graphics();

	bool Init(HWND inputWindow);
	void BeginDraw() {
		renderTarget->BeginDraw();
	}
	void EndDraw() {
		renderTarget->EndDraw();
	}
	void ClearScreen(float r, float g, float b);
	void DrawChomper(float x, float y, float width, float height, float r, float g, float b, float a);
};