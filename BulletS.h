#include "Bullet.h"

class CBulletS:public CBullet {

public:
	CBulletS(float x, float y, int angle, bool friendly);
	void Update(DWORD dt);
};
typedef CBulletS* LPBULLETS;