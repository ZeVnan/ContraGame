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
void CCamera::TranslateToCamCoord2(float& x, float& y) {
	x = x - (this->x - CAM_WIDTH / 2);
	y = y + (this->y - CAM_HEIGHT / 2);
}
bool CCamera::CheckWorldPart(LPWORLDPART part) {
	float part_left = part->getX();
	float part_top = part->getY() + part->getHeight();
	float part_right = part->getX() + part->getWidth();
	float part_bottom = part->getY();

	float cam_left = this->x - CAM_WIDTH / 2;
	float cam_top = this->y + CAM_HEIGHT / 2;
	float cam_right = this->x + CAM_WIDTH / 2;
	float cam_bottom = this->y - CAM_HEIGHT / 2;

	float OK_X = false, OK_Y = false;

	if ((cam_left <= part_left && part_left <= cam_right) || (cam_left <= part_right && part_right <= cam_right)) {
		OK_X = true;
	}
	else {
		if (part_left < cam_left && cam_right < part_right)
			OK_X = true;
	}
	
	if ((cam_bottom <= part_bottom && part_bottom <= cam_top) || (cam_bottom <= part_top && part_top <= cam_top)) {
		OK_Y = true;
	}
	else {
		if (part_bottom < cam_bottom && cam_top < part_top)
			OK_Y = true;
	}
	return OK_X && OK_Y;
}