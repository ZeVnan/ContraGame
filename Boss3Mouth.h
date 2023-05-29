#pragma once
#include "GameObject.h"
#include "Animations.h"
#include "debug.h"
#include "BulletBoss3.h"

#define BOSS3MOUTH_STATE_CLOSE 0
#define BOSS3MOUTH_STATE_OPENING 1			//also closing
#define BOSS3MOUTH_STATE_OPEN 2
#define BOSS3MOUTH_STATE_CLOSING 3
#define BOSS3MOUTH_STATE_EXPLODE 4
#define BOSS3MOUTH_STATE_DEAD 5

#define BOSS3MOUTH_ANI_CLOSE 42000
#define BOSS3MOUTH_ANI_OPENING 42001		//also closing
#define BOSS3MOUTH_ANI_OPEN 42002
#define BOSS3MOUTH_ANI_MOUDLER 42003

#define BOSS3MOUTH_BOX_NORMAL_WIDTH 60
#define BOSS3MOUTH_BOX_NORMAL_HEIGHT 95
#define BOSS3MOUTH_BOX_DEAD_WIDTH 20
#define BOSS3MOUTH_BOX_DEAD_HEIGHT 20

#define BOSS3MOUTH_TIME_CLOSE 2000
#define BOSS3MOUTH_TIME_OPENING 200			//also closing
#define BOSS3MOUTH_TIME_RELOAD 200

#define BOSS3MOUTH_BULLET_PER_WAVE 30

class CBoss3Mouth : public CGameObject
{
private:
	bool isDead;
	bool isClosed;
	int HP;
	int timeLeft;
	int bulletLeft;

	vector<LPBULLET> bullets;
public:
	CBoss3Mouth(float x, float y);
	void TakeDamage(int damage) {
		this->HP -= damage;
	}

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void Render();
	void SetState(int state);

	void CreateBox(DWORD dt);
	void NoCollision(DWORD dt);
	void CollisionWith(LPCOLLISIONEVENT e);

	bool isCollidable() {
		if (isExploded == false) {
			return true;
		}
		else {
			if (isDead == false) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	bool isBlocking() { return false; }
	bool IsExploded() { return isExploded; }
	bool IsClosed() { return isClosed; }
	bool IsDead() { return isDead; }

	void AddBullet();
	void UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void RenderBullet();
};
typedef CBoss3Mouth* LPBOSS3MOUTH;
