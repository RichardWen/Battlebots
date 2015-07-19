#pragma once
#include "Graphics.h"
#include "GameState.h"

class InGame : public GameState {
	float x;
	float xSpeed;

	SpriteSheet* Chomper;
public:
	void Load() override;
	void Unload() override;
	void Render(int laneNumber) override;
	void Update() override;
};