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
	
	float cam_left = x - CAM_WIDTH / 2;
	float cam_top = y + CAM_HEIGHT / 2;
	float cam_right = x + CAM_WIDTH / 2;
	float cam_bottom = y - CAM_HEIGHT / 2;

	bool OK_1 = false;
	bool OK_2 = false;
	if ((cam_left <= part_left && part_left <= cam_right) ||
		(cam_left <= part_right && part_right <= cam_right) ||
		(part_left < cam_left && cam_right < part_right)) OK_1 = true;
	if ((cam_top >= part_top && part_top >= cam_bottom) ||
		(cam_top >= part_bottom && part_bottom >= cam_bottom) ||
		(part_top > cam_top && cam_bottom > part_bottom)) OK_2 = true;
	return OK_1 && OK_2;
}