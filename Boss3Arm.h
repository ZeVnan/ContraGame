#pragma once
#include "GameObject.h"
#include "Animations.h"
#include "BulletBoss3.h"
#include "debug.h"
#define BOSS3ARM_RADIUS_BASE 30
#define BOSS3ARM_TIME_SWITCH 1000
#define BOSS3ARM_SPEED_R 0.07f

#define BOSS3ARM_STATE_TURN_LEFT 0
#define BOSS3ARM_STATE_TURN_RIGHT 1

#define BOSS3ARM_ANI_ARM 43000
#define BOSS3ARM_ANI_HAND 43001

#define BOSS3ARM_BOX_WIDTH 30
#define BOSS3ARM_BOX_HEIGHT 30
struct Boss3ArmPart {
	float x;
	float y;
	float angle;
	int number;
	bool type;		//false-arm, true-hand
};
class CBoss3Arm : public CGameObject
{
private:
	vector<Boss3ArmPart> parts;
	int HP;
	int timeLeft;
	int countToShoot;
	float vr;
	vector<LPBULLET> bullets;
public:
	CBoss3Arm(float x, float y, float startAngle);
	void TakeDamage(int damage) {
		this->HP -= damage;
	}
	void CalculatePosition(float& x, float& y, float angle, int number);

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);

	bool isCollidable() { return !isExploded; }
	bool isBlocking() { return false; }

	void AddBullet();
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();
};

typedef CBoss3Arm* LPBOSS3ARM;