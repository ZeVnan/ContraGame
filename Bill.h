#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#include "Bullet.h"
#include "BulletS.h"
#include "BulletL.h"
#include "BulletF.h"
#include "BulletN.h"
#include "BulletM.h"

#define BILL_RUN_SPEED 0.2f

#define BILL_JUMP_SPEED_Y 0.2f

#define BILL_GRAVITY -0.00025f

#define BILL_STATE_NORMAL 0

#define BILL_STATE_RUN_RIGHT 10
#define BILL_STATE_RUN_LEFT 11

#define BILL_STATE_JUMP 20
#define BILL_STATE_DROP 21

#define BILL_STATE_DOWN 30
#define BILL_STATE_DOWN_RELEASE 31

#define BILL_STATE_UP 40
#define BILL_STATE_UP_RELEASE 41

#define BILL_STATE_SHOOT 50
#define BILL_STATE_SHOOT_RELEASE 51

#define BILL_STATE_SWIM_BEGIN 60
#define BILL_STATE_SWIM 61
#define BILL_STATE_DIVING 62

#define BILL_STATE_DEAD 70



#pragma region
#define BILL_ANI_NORMAL_RIGHT 10000
#define BILL_ANI_NORMAL_LEFT 10001

#define BILL_ANI_RUN_RIGHT 10010
#define BILL_ANI_RUN_LEFT 10011

#define BILL_ANI_JUMP_RIGHT 10020
#define BILL_ANI_JUMP_LEFT 10021

#define BILL_ANI_LAYDOWN_RIGHT 10030
#define BILL_ANI_LAYDOWN_LEFT 10031

#define BILL_ANI_SHOOT_UPRIGHT 10040
#define BILL_ANI_SHOOT_UPLEFT 10041
#define BILL_ANI_SHOOT_DOWNRIGHT 10042
#define BILL_ANI_SHOOT_DOWNLEFT 10043
#define BILL_ANI_SHOOT_UP_RIGHT 10044
#define BILL_ANI_SHOOT_UP_LEFT 10045
#define BILL_ANI_SHOOT_RIGHT 10046
#define BILL_ANI_SHOOT_LEFT 10047

#define BILL_LAY_HEIGHT_ADJUST -10.0f
#define BILL_UP_HEIGHT_ADJUST 6.0f

#define BILL_START_X 100.0f
#define BILL_START_Y 400.0f

#define BILL_WAVE_BULLET_NORMAL 4
#define BILL_WAVE_BULLET_LASER 1
#define BILL_WAVE_BULLET_FLAME 4
#define BILL_WAVE_BULLET_SPREAD 2
#define BILL_WAVE_BULLET_MACHINE 6

#define BILL_BOX_NORMAL_WIDTH 48
#define BILL_BOX_NORMAL_HEIGHT 70
class CBill :public CGameObject
{
	BOOLEAN isLaying;
	BOOLEAN isShooting;
	BOOLEAN isOnPlatform;
	BOOLEAN isDropping;
	int ny;    //normal:0, up:1, down:-1
	float maxVx;
	float maxVy;
	float gunx;
	float guny;

	vector< vector<LPBULLET>>waveContainer;
	int bulletType;
	int waveLeft;

	int bulletMtime;
public:
	CBill(float x, float y);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void KeyDown(int KeyCode);
	void KeyUp(int KeyCode);
	void KeyState(CGame* game);

	void CreateBox(DWORD dt);
	/*bool isCollidable();
	bool isBlocking();*/
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	void CollisionWithGrass(LPCOLLISIONEVENT e);

	int CalculateAngle();
	void AddBullet(BOOLEAN KeyState);
	vector<LPBULLET> ShootSpreadBullet(int angle);
	vector<LPBULLET> ShootMachineBullet(int angle);
	vector<LPBULLET> ShootFlameBullet(int angle);
	vector<LPBULLET> ShootLaserBullet(int angle);
	vector<LPBULLET> ShootNormalBullet(int angle);

	void SetBulletType(int type);
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();
};

