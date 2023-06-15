#pragma once
#include "GameObject.h"

#define WAIT_TIME 3000

class CWorldPart;
typedef CWorldPart* LPWORLDPART;
class CObjectGenerator : public CGameObject
{
private:
	int type;
	int stage;
	LPWORLDPART parent;
	int timeLeft;
public:
	CObjectGenerator(float x, float y, int type, int stage);
	void AddObject();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	//void Render();
	bool isCollidable() { return false; }

	void setParent(LPWORLDPART parent) {
		this->parent = parent;
	}
	bool InScreen();
};
typedef CObjectGenerator* LPOBJECTGENERATOR;

