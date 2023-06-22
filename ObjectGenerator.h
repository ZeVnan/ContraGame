#pragma once
#include "GameObject.h"

#define OBJ_GENERATOR_WAIT_TIME 1000
#define OBJ_GENERATOR_ACTIVE_RADIUS 500

class CWorldPart;
typedef CWorldPart* LPWORLDPART;
class CObjectGenerator : public CGameObject
{
private:
	int type;
	int stage;
	LPWORLDPART parent;
	int timeLeft;
	vector<LPGAMEOBJECT> objects;
	bool isActivated;
public:
	CObjectGenerator(float x, float y, int type, int stage);
	void AddObject();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void UpdateObjects();
	void watchBill();
	//void Render();
	bool isCollidable() { return false; }

	void setParent(LPWORLDPART parent) {
		this->parent = parent;
	}
	bool InScreen();
};
typedef CObjectGenerator* LPOBJECTGENERATOR;

