#include "GameControl.h"
#include "InGame.h"
#include "Graphics.h"

void InGame::Load() {
	x = 0.0f;
	xSpeed = 1.0f;
}
void InGame::Unload() {

}
void InGame::Render(){
	gfx->ClearScreen(0.0f, 0.0f, 0.0f);
	gfx->DrawChomper(x, 50, 25, 25, 1.0f, 1.0f, 1.0f, 1.0);
}

void InGame::Update() {
	x += xSpeed;
	if (x > 975) {
		x = 975;
		xSpeed = 0.0f;
	}
}