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

#define BILL_RUN_SPEED 0.15f
#define BILL_JUMP_SPEED_Y 0.4f

#define BILL_GRAVITY -0.00075f

#define BILL_TIME_SWIM_BEGIN 200

#define BILL_TIME_DYING 800

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

#define BILL_STATE_INTO_WATER 60
#define BILL_STATE_OUT_OF_WATER 61
#define BILL_STATE_ON_LAND 62
#define BILL_STATE_OFF_LAND 63

#define BILL_STATE_DYING_RIGHT 70
#define BILL_STATE_DYING_LEFT 71

#define BILL_STATE_REVIVE 80

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

#define BILL_ANI_SWIMMING_BEGIN 10050
#define BILL_ANI_DIVING 10051
#define BILL_ANI_SWIMMING_RIGHT 10052
#define BILL_ANI_SWIMMING_LEFT 10053

#define BILL_ANI_SWIMMING_SHOOT_RIGHT 10060
#define BILL_ANI_SWIMMING_SHOOT_LEFT 10061
#define BILL_ANI_SWIMMING_SHOOT_UP_RIGHT 10062
#define BILL_ANI_SWIMMING_SHOOT_UP_LEFT 10063
#define BILL_ANI_SWIMMING_SHOOT_UPRIGHT 10064
#define BILL_ANI_SWIMMING_SHOOT_UPLEFT 10065

#define BILL_ANI_DYING_RIGHT 10070
#define BILL_ANI_DYING_LEFT 10071

#define LIFE_ANI 10080

#define BILL_LAY_HEIGHT_ADJUST -18.0f
#define BILL_UP_HEIGHT_ADJUST 12.0f
#define BILL_DIVE_HEIGHT_ADJUST -7.0f
#define BILL_JUMP_NORMAL_POSITION_ADJUST 15.0f
#define BILL_SWIM_NORMAL_POSITION_ADJUST 17.0f
#define BILL_JUMP_SWIM_POSITION_ADJUST 2.0f
#define BILL_NORMAL_SWIM_POSITION_ADJUST 17.0f
#define BILL_WATER_TO_LAND_POSITION_ADJUST 7.0f;

#define BILL_WAVE_BULLET_NORMAL 4
#define BILL_WAVE_BULLET_LASER 1
#define BILL_WAVE_BULLET_FLAME 4
#define BILL_WAVE_BULLET_SPREAD 3
#define BILL_WAVE_BULLET_MACHINE 6

#define BILL_BOX_NORMAL_WIDTH 48
#define BILL_BOX_NORMAL_HEIGHT 70

#define BILL_BOX_JUMP_WIDTH 42
#define BILL_BOX_JUMP_HEIGHT 40

#define BILL_BOX_LAY_WIDTH 66
#define BILL_BOX_LAY_HEIGHT 34

#define BILL_BOX_SWIM_WIDTH 36
#define BILL_BOX_SWIM_HEIGHT 36

#define BILL_BOX_DIE_WIDTH 66
#define BILL_BOX_DIE_HEIGHT 22
class CBill :public CGameObject
{
	bool isLaying;
	bool isShooting;
	bool isSwimming;
	bool isDiving;
	bool isOnPlatform;	//support collision
	bool isDropping;		//support collision
	bool isJumping;		//support change bbox
	bool isDying;
	bool disableDrop;
	bool isDead;
	bool isVulnerable;
	bool a;					//support render when invulnerable

	int ny;					//normal:0, up:1, down:-1
	float maxVx;
	float maxVy;
	float maxX;
	float maxY;
	float minX;
	float minY;
	float gunx;		
	float guny;
	int stage;

	vector<vector<LPBULLET>> waveContainer;		//support bullet control
	int bulletType;
	int waveLeft;		//support bullet control
	int bonusWave;		//support bullet control

	int bulletMtime;	//support bullet type M control
	int timeLeft;		
	int invulnerableTime;

	int lifeLeft;
	void worldControl();
	void Die();
	void UpdateBorder();
	void Move(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void BulletControl(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	
public:
	CBill(float x, float y, int stage);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void KeyDown(int KeyCode);
	void KeyUp(int KeyCode);
	void KeyState(CGame* game);

	void CreateBox(DWORD dt);
	bool isBlocking() { return false; }
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);
	//collision with terrain object
	void CollisionWithGrass(LPCOLLISIONEVENT e);
	void CollisionWithWater(LPCOLLISIONEVENT e);
	void CollisionWithBridgePart(LPCOLLISIONEVENT e);
	void CollisionWithBridge(LPCOLLISIONEVENT e);
	void CollisionWithRockFly(LPCOLLISIONEVENT e);
	void CollisionWithBoss1Shield(LPCOLLISIONEVENT e);
	void CollisionWithBoss3Mouth(LPCOLLISIONEVENT e);
	//collision with enemy object
	void CollisionWithAircraft(LPCOLLISIONEVENT e);
	void CollisionWithFalcon(LPCOLLISIONEVENT e);
	void CollisionWithSoldier(LPCOLLISIONEVENT e);
	void CollisionWithRockFall(LPCOLLISIONEVENT e);
	void CollisionWithRifleman(LPCOLLISIONEVENT e);
	void CollisionWithScubaSoldier(LPCOLLISIONEVENT e);
	void CollisionWithFire(LPCOLLISIONEVENT e);

	float CalculateAngle();
	void AddBullet(bool KeyState);
	vector<LPBULLET> ShootSpreadBullet(float angle);
	vector<LPBULLET> ShootMachineBullet(float angle);
	vector<LPBULLET> ShootFlameBullet(float angle);
	vector<LPBULLET> ShootLaserBullet(float angle);
	vector<LPBULLET> ShootNormalBullet(float angle);

	void SetBulletType(int type);
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();

	bool IsDiving() { return isDiving; }
	bool IsVulnerable() { return isVulnerable; }
	bool IsDead() { return isDead; }
	bool IsDying() { return isDying; }
};

typedef CBill* LPBILL;