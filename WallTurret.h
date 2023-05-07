#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

//define state
#define WTURRET_STATE_APPEAR	0
#define WTURRET_STATE_LEFT30	10
#define WTURRET_STATE_LEFT60	11
#define WTURRET_STATE_LEFT90	12		
#define WTURRET_STATE_LEFT120	13
#define WTURRET_STATE_LEFT150	14
#define WTURRET_STATE_RIGHT30	20
#define WTURRET_STATE_RIGHT60	21
#define WTURRET_STATE_RIGHT90	22
#define WTURRET_STATE_RIGHT120	23
#define WTURRET_STATE_RIGHT150	24
#define WTURRET_STATE_UP		30
#define WTURRET_STATE_DOWN		31
#define WTURRET_STATE_EXPLODE	40

//define temporary animation time
#define WTURRET_TIME_APPEAR		700
#define WTURRET_TIME_ROTATE		500
#define WTURRET_TIME_EXPLODE	600

//define animation
#define WTURRET_ANI_APPEAR		10700

#define WTURRET_ANI_LEFT30		10710
#define WTURRET_ANI_LEFT60		10711
#define WTURRET_ANI_LEFT90		10712
#define WTURRET_ANI_LEFT120		10713
#define WTURRET_ANI_LEFT150		10714

#define WTURRET_ANI_RIGHT30		10720
#define WTURRET_ANI_RIGHT60		10721
#define WTURRET_ANI_RIGHT90		10722
#define WTURRET_ANI_RIGHT120	10723
#define WTURRET_ANI_RIGHT150	10724

#define WTURRET_ANI_UP			10730
#define WTURRET_ANI_DOWN		10731

#define WTURRET_BOX_WIDTH 32
#define WTURRET_BOX_HEIGHT 32

class CWallTurret : public CGameObject
{
private:
	int timeleft;
public:
	CWallTurret(float x, float y);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	bool isBlocking() { return false; }
	bool isCollidable() {
		return !isExploded;
	}
};
typedef CWallTurret* LPWALLTURRET;