#pragma once
#include "Bullet.h"

class CBulletN :public CBullet {
public:
	CBulletN(float x, float y, int angle);
	void Update(DWORD dt);
};
typedef CBulletN* LPBULLETN;