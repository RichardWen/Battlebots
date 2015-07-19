#pragma once

#include "GameState.h"

class GameControl
{
	GameControl() {

	}
	static GameState *currentState;
public:
	static bool Loading;
	static void Init();
	static void LoadInitialState(GameState* state);
	static void SwitchState(GameState* state);
	static void Render(int LaneNumber);
	static void Update();
};