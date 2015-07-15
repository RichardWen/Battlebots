#pragma once

#include "Graphics.h"

class GameState {
protected:
	static Graphics* gfx;
public:
	static void Init(Graphics* graphics) {
		gfx = graphics;
	}
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};