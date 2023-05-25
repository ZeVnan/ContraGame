#pragma once
class CWorldPart;
typedef CWorldPart* LPWORLDPART;

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600
#define CAM_WIDTH_1 600
#define CAM_HEIGHT_1 448
#define CAM_WIDTH_3 512
#define CAM_HEIGHT_3 600
class CCamera
{
private:
	float x = 0;
	float y = 0;
	float maxX;
	float maxY;
	float minX;
	float minY;
	float width;
	float height;
	int stage;
public:
	CCamera(float worldWidth, float worldHeight, int stage);
	void Update(float characterX, float charracterY);
	void GetCamPos(float& x, float& y) {
		x = this->x;
		y = this->y;
	}
	void SetCamPos(float x, float y) {
		this->x = x;
		this->y = y;
	}
	float GetCamWidth() { return this->width; }
	float GetCamHeight() { return this->height; }
	void TranslateToCamCoord(float& x, float& y);
	bool CheckWorldPart(LPWORLDPART part);
};

