#include "Fire.h"
CFire::CFire(float x, float y) :CGameObject(x, y) {

}
void CFire::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(FIRE_ANI)->Render(x, y);
}
void CFire::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

}