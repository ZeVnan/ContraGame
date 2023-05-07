#include "Bullet.h"

class CBulletS:public CBullet {

public:
	CBulletS(float x, float y, int angle, bool friendly);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
};
typedef CBulletS* LPBULLETS;