#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "BulletN.h"

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

//define animation
#define WTURRET_ANI_APPEAR		17000

#define WTURRET_ANI_LEFT30		17010
#define WTURRET_ANI_LEFT60		17011
#define WTURRET_ANI_LEFT90		17012
#define WTURRET_ANI_LEFT120		17013
#define WTURRET_ANI_LEFT150		17014

#define WTURRET_ANI_RIGHT30		17020
#define WTURRET_ANI_RIGHT60		17021
#define WTURRET_ANI_RIGHT90		17022
#define WTURRET_ANI_RIGHT120	17023
#define WTURRET_ANI_RIGHT150	17024

#define WTURRET_ANI_UP			17030
#define WTURRET_ANI_DOWN		17031

#define WTURRET_BOX_WIDTH 64
#define WTURRET_BOX_HEIGHT 64

class CWallTurret : public CGameObject
{
private:
	int timeleft;
	int HP;
	vector<vector<LPBULLET>> waveContainer;
	float gunx;
	float guny;	
	int waveLeft;
	int timeLeft;

public:
	CWallTurret(float x, float y);
	void TakeDamage(int damage) {
		this->HP -= damage;
	}

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

	int CalculateAngle();
	vector<LPBULLET> ShootNormalBullet(int angle);
	void AddBullet();
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();
};
typedef CWallTurret* LPWALLTURRET;