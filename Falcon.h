#pragma once
#include "debug.h"

#include "Aircraft.h"

#define FALCON_CLOSE_TIME 1500
#define FALCON_OPEN_TIME 1500
#define FALCON_CLOSING_TIME 300
#define FALCON_OPENING_TIME 300

#define FALCON_STATE_CLOSE 0
#define FALCON_STATE_OPEN 1
#define FALCON_STATE_CLOSING 2
#define FALCON_STATE_OPENING 3

#define FALCON_ANI_CLOSED		16000
#define FALCON_ANI_OPENING		16001
#define FALCON_ANI_OPENED		16002
#define FALCON_ANI_CLOSING		16003

#define FALCON_BOX_WIDTH 62
#define FALCON_BOX_HEIGHT 62

class CFalcon : public CGameObject
{
private:
	//state: 0:close 1:opening 2:open 3:closing
	int timeleft;
public:
	CFalcon(float x, float y);
	
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() { return !isExploded; }
};