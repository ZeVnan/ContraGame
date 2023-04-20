#include "Camera.h"
#include "WorldPart.h"
CCamera::CCamera(float worldWidth, float worldHeight) {
	maxX = worldWidth - CAM_WIDTH / 2;
	maxY = worldHeight - CAM_HEIGHT / 2;
	minX = CAM_WIDTH / 2;
	minY = CAM_HEIGHT / 2;
}
void CCamera::Update(float characterX, float characterY) {
	this->x = characterX;
	this->y = characterY;
	if (x < minX) x = minX;
	if (x > maxX) x = maxX;
	if (y < minY) y = minY;
	if (y > maxY) y = maxY;
}
void CCamera::TranslateToCamCoord(float& x, float& y) {
	x = x - (this->x - CAM_WIDTH / 2);
	y = -y + (this->y + CAM_HEIGHT / 2);
}
bool CCamera::CheckWorldPart(LPWORLDPART part) {
	float part_left = part->getX();
	float part_top = part->getY() + part->getHeight();
	float part_right = part->getX() + part->getWidth();
	float part_bottom = part->getY();
	
	if (part_left <= this->x && this->x <= part_right &&
		part_bottom <= this->y && this->y <= part_top)
		return true;
	return false;
}