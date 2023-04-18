#pragma once
#define SCREEN_WIDTH 360
#define SCREEN_HEIGHT 270
#define CAM_WIDTH 320
#define CAM_HEIGHT 240
class CCamera
{
private:
	float x = 0;
	float y = 0;
	float maxX;
	float maxY;
	float minX;
	float minY;
public:
	CCamera(float worldWidth, float worldHeight);
	void Update(float characterX, float charracterY);
	void GetCamPos(float& x, float& y) {
		x = this->x;
		y = this->y;
	}
	void TranslateToCamCoord(float& x, float& y);
};

