#pragma once
#include "GameObject.h"
#define WATER_BOX_WIDTH 32
#define WATER_BOX_HEIGHT 32
class CWater : public CGameObject
{
public:
	CWater(float x, float y);

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL) {};
	void CreateBox(DWORD dt);
};
typedef CWater* LPWATER;