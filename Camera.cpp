#include "Camera.h"
#include "WorldPart.h"
CCamera::CCamera(float worldWidth, float worldHeight, int stage) {
	this->stage = stage;
	if (stage == 1) {
		width = CAM_WIDTH_1;
		height = CAM_HEIGHT_1;
	}
	else if (stage == 3) {
		width = CAM_WIDTH_3;
		height = CAM_HEIGHT_3;
	}
	else {
		width = 500;
		height = 450;
	}
	maxX = worldWidth - width / 2;
	maxY = worldHeight - height / 2;
	minX = width / 2;
	minY = height / 2;
}
void CCamera::Update(float characterX, float characterY) {
	this->x = characterX;
	this->y = characterY;
	if (characterX > this->minX)
		this->minX = characterX;
	if (characterY > this->minY)
		this->minY = characterY;
	if (stage == 3 && y > 3900) {
		minY = 3900 + height / 2;
	}
	if (x < minX) x = minX;
	if (x > maxX) x = maxX;
	if (y < minY) y = minY;
	if (y > maxY) y = maxY;
	//DebugOutTitle(L"y = %f, minY = %f, stage = %d", y, minY, stage);
}
void CCamera::TranslateToCamCoord(float& x, float& y) {
	x = x - (this->x - width / 2);
	y = -y + (this->y + height / 2);
}
bool CCamera::CheckWorldPart(LPWORLDPART part) {
	float part_left = part->getX();
	float part_top = part->getY() + part->getHeight();
	float part_right = part->getX() + part->getWidth();
	float part_bottom = part->getY();

	float cam_left = this->x - width / 2;
	float cam_top = this->y + height / 2;
	float cam_right = this->x + width / 2;
	float cam_bottom = this->y - height / 2;

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