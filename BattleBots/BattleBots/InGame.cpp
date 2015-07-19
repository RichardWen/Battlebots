#include "GameControl.h"
#include "InGame.h"
#include "Graphics.h"


void InGame::Load() {
	x = 0.0f;
	xSpeed = 1.5f;

	Chomper = new SpriteSheet(L"Driller.png", gfx);
}
void InGame::Unload() {
	delete Chomper;
}
void InGame::Render(int laneNumber){
	Chomper->Draw(x,50 + 100 * (laneNumber - 1));
}

void InGame::Update() {
	Chomper->Clear();
	x += xSpeed;
	if (x > 975) {
		x = 0;
	}
}