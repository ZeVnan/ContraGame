#include "RockFly.h"

CRockFly::CRockFly(float x, float y) : CGameObject(x, y){
	timeLeft = ROCKFLY_FLY_TIME / 2;
	vx = ROCKFLY_FLY_SPEED;
	turn = false;
}

void CRockFly::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (timeLeft > 0) {
		timeLeft -= dt;
		if (turn) {
			this->x += vx * dt;
		}
		else {
			this->x -= vx * dt;
		}
		
	}
	else {
		turn = ~turn;
		timeLeft = ROCKFLY_FLY_TIME;
	}
}

void CRockFly::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ROCKFLY_ANI)->Render(x, y);
}

void CRockFly::CreateBox(DWORD dt) {
	bbox.left = (x - ROCKFLY_BOX_WIDTH / 2);
	bbox.top = (y - ROCKFLY_BOX_HEIGHT / 2);
	bbox.right = (x + ROCKFLY_BOX_WIDTH / 2);
	bbox.bottom = (y + ROCKFLY_BOX_HEIGHT / 2);
	if (turn) {
		bbox.vpf_x = vx * dt;
	}
	else {
		bbox.vpf_x = -vx * dt;
	}
	bbox.vpf_x = 0;
	bbox.vpf_y = 0;
}

