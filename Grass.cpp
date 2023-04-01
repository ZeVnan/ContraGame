#include "Grass.h"

CGrass::CGrass(float x, float y) :CGameObject(x, y) {

}
void CGrass::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(GRASS_ANI)->Render(x, y);
}