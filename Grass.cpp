#include "Grass.h"

CGrass::CGrass(float x, float y) :CGameObject(x, y) {

}
void CGrass::Render() {
	//CAnimations* animations = CAnimations::GetInstance();
	//animations->Get(GRASS_ANI)->Render(x, y);
}
void CGrass::CreateBox(DWORD dt) {
	bbox.left = x - GRASS_WIDTH / 2;
	bbox.top = y - GRASS_HEIGHT / 2;
	bbox.right = x + GRASS_WIDTH / 2;
	bbox.bottom = y + GRASS_HEIGHT / 2;
}