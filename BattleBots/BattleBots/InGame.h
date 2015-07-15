#pragma once
#include "Graphics.h"
#include "GameState.h"

class InGame : public GameState {
	float x;
	float xSpeed;
public:
	void Load() override;
	void Unload() override;
	void Render() override;
	void Update() override;
};