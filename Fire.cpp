#include "Fire.h"
CFire::CFire(float x, float y) :CGameObject(x, y) {

}
void CFire::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(FIRE_ANI)->Render(x, y);
}
void CFire::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

}

void CFire::CreateBox(DWORD dt) {
	bbox.left = x - FIRE_BOX_WIDTH / 2;
	bbox.top = y - FIRE_BOX_HEIGHT / 2;
	bbox.right = x + FIRE_BOX_WIDTH / 2;
	bbox.bottom = y + FIRE_BOX_HEIGHT / 2;
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = 0;
}
void CFire::NoCollision(DWORD dt) {
	x += vx * dt;
	y += 0;
}
void CFire::CollisionWith(LPCOLLISIONEVENT e) {

	//kill Bill

}