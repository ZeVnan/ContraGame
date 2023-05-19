#pragma once
class CWorldPart;
typedef CWorldPart* LPWORLDPART;

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 450
#define CAM_WIDTH 600
#define CAM_HEIGHT 450
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
	void SetCamPos(float x, float y) {
		this->x = x;
		this->y = y;
	}
	void TranslateToCamCoord(float& x, float& y);
	void TranslateToCamCoord2(float& x, float& y);
	bool CheckWorldPart(LPWORLDPART part);
};

