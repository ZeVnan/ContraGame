#pragma once
#include "GameObject.h"

#define BRIDGEPART_WIDTH 64
#define BRIDGEPART_HEIGHT 64

#define TIME_TO_EXPLODE 1000

#define BRIDGEPART_STATE_NORMAL 0
#define BRIDGEPART_STATE_TRIGGER 1
#define BRIDGEPART_STATE_EXPLODE 2

#define BRIDGEPART_ANI_UPLEFT 20030
#define BRIDGEPART_ANI_UPRIGHT 20031
#define BRIDGEPART_ANI_DOWNBEGIN 20032
#define BRIDGEPART_ANI_DOWN 20033
#define BRIDGEPART_ANI_DOWNEND 20034

class CBridgePart : public CGameObject
{
private:
	int number;
	int timeLeft;
	int isTriggered;
public:
	CBridgePart(float x, float y, int number);
	
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
};
typedef CBridgePart* LPBRIDGEPART;
