#include "Water.h"
CWater::CWater(float x, float y) :CGameObject(x, y) {

}
void CWater::Render() {
	
}
void CWater::CreateBox(DWORD dt) {
	bbox.left = x - WATER_BOX_WIDTH / 2;
	bbox.top = y - WATER_BOX_HEIGHT / 2;
	bbox.right = x + WATER_BOX_WIDTH / 2;
	bbox.bottom = y + WATER_BOX_HEIGHT / 2;
}