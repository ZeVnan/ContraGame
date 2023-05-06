#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

//define state
#define WTURRET_STATE_APPEAR	0
#define WTURRET_STATE_LEFT30	1
#define WTURRET_STATE_LEFT60	2
#define WTURRET_STATE_LEFT90	3		
#define WTURRET_STATE_LEFT120	4
#define WTURRET_STATE_LEFT150	5
#define WTURRET_STATE_RIGHT30	6
#define WTURRET_STATE_RIGHT60	7
#define WTURRET_STATE_RIGHT90	8
#define WTURRET_STATE_RIGHT120	9
#define WTURRET_STATE_RIGHT150	10
#define WTURRET_STATE_UP		11
#define WTURRET_STATE_DOWN		12

//define temporary animation time
#define WTURRET_TIME_APPEAR		700
#define WTURRET_TIME_ROTATE		500

//define animation
#define WTURRET_ANI_APPEAR		600
#define WTURRET_ANI_LEFT30		601
#define WTURRET_ANI_LEFT60		602
#define WTURRET_ANI_LEFT90		603
#define WTURRET_ANI_LEFT120		604
#define WTURRET_ANI_LEFT150		605
#define WTURRET_ANI_RIGHT30		606
#define WTURRET_ANI_RIGHT60		607
#define WTURRET_ANI_RIGHT90		608
#define WTURRET_ANI_RIGHT120	609
#define WTURRET_ANI_RIGHT150	610
#define WTURRET_ANI_UP			611
#define WTURRET_ANI_DOWN		612

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
};