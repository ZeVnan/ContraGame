#pragma once
#include "Bullet.h"

class CBulletN :public CBullet {
public:
	CBulletN(float x, float y, int angle, bool friendly);
	void Update(DWORD dt);
};
typedef CBulletN* LPBULLETN;