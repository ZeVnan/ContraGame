#include "Camera.h"
CCamera::CCamera(float worldWidth, float worldHeight) {
	maxX = worldWidth - CAM_WIDTH;
	minY = -(worldHeight - CAM_HEIGHT);
}
void CCamera::Update(float characterX, float characterY) {
	this->x = characterX - CAM_WIDTH / 2;
	this->y = characterY - CAM_HEIGHT / 2;
	if (x < 0) x = 0;
	if (x > maxX) x = maxX;
	if (y > 0) y = 0;
	if (y < minY) y = minY;
}
void CCamera::TranslateToCamCoord(float& y) {
	y = -y + CAM_HEIGHT;
}