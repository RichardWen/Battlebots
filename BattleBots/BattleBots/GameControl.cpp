#include "GameControl.h"

GameState *GameControl::currentState;
bool GameControl::Loading;

void GameControl::Init() {
	Loading = true;
	currentState = 0;
}

void GameControl::LoadInitialState(GameState* Menu){
	Loading = true;
	currentState = Menu;
	currentState->Load();
	Loading = false;
}
void GameControl::SwitchState(GameState* newState) {
	Loading = true;
	currentState->Unload();
	newState->Load();
	delete currentState;
	currentState = newState; 
	Loading = false;
}

void GameControl::Render(int LaneNumber) {
	if (Loading) {
		return;
	}
	currentState->Render(LaneNumber);
}
void GameControl::Update() {
	if (Loading) {
		return;
	}
	currentState->Update();
}