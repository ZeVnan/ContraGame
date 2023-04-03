#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#include "Bullet.h"
#include "BulletS.h"
#define BILL_RUN_SPEED 0.1f

#define BILL_JUMP_SPEED_Y 0.2f

#define BILL_GRAVITY 0.0004f

#define BILL_STATE_NORMAL 0

#define BILL_STATE_RUN_RIGHT 10
#define BILL_STATE_RUN_LEFT 11

#define BILL_STATE_JUMP 20

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
#define BILL_ANI_NORMAL_RIGHT 10
#define BILL_ANI_NORMAL_LEFT 11

#define BILL_ANI_RUN_RIGHT 20
#define BILL_ANI_RUN_LEFT 21

#define BILL_ANI_JUMP_RIGHT 30
#define BILL_ANI_JUMP_LEFT 31

#define BILL_ANI_LAYDOWN_RIGHT 40
#define BILL_ANI_LAYDOWN_LEFT 41

#define BILL_ANI_SHOOT_UPRIGHT 50
#define BILL_ANI_SHOOT_UPLEFT 51
#define BILL_ANI_SHOOT_DOWNRIGHT 52
#define BILL_ANI_SHOOT_DOWNLEFT 53
#define BILL_ANI_SHOOT_UP_RIGHT 54
#define BILL_ANI_SHOOT_UP_LEFT 55
#define BILL_ANI_SHOOT_RIGHT 56
#define BILL_ANI_SHOOT_LEFT 57

#define BILL_LAY_HEIGHT_ADJUST 10.0f
#define BILL_UP_HEIGHT_ADJUST -6.0f

#define BILL_START_X 160.0f
#define BILL_START_Y 10.0f
class CBill :public CGameObject
{
	BOOLEAN isLaying;
	BOOLEAN isShooting;
	int ny;    //normal:0, up:1, down:-1
	float maxVx;
	float maxVy;
	float gunx;
	float guny;
	vector<LPBULLET>bullets;
	int bulletType = BULLET_ANI_SPREAD;
public:
	CBill();
	CBill(float x, float y);
	void Update(DWORD dt);
	void Render();
	void SetState(int state);

	void KeyDown(int KeyCode);
	void KeyUp(int KeyCode);
	void KeyState(CGame* game);

	int CalculateAngle();

	void AddBullet();
	void DelBullet(int i);

	void ShootSpreadBullet(int angle);
	void ShootMachineBullet(int angle);
	void ShootFlameBullet(int angle);
	void ShootLaserBullet(int angle);
	void ShootNormalBullet(int angle);
};

