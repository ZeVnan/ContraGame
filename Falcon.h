#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

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

#define FALCON_ANI_CLOSED		500
#define FALCON_ANI_OPENING		501
#define FALCON_ANI_OPENED		502
#define FALCON_ANI_CLOSING		503

class CFalcon : public CGameObject
{
private:
	//state: 0:close 1:opening 2:open 3:closing
	int timeleft;
public:
	CFalcon(float x, float y);
	
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};