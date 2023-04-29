#include "WorldPart.h"

CWorldPart::CWorldPart()
{
	width = 0;
	height = 0;
	x = 0;
	y = 0;
	firstPart = NULL;
	secondPart = NULL;
	thirdPart = NULL;
	fourthPart = NULL;
}
CWorldPart::CWorldPart(LPWORLD world) {
	this->width = world->getWidth();
	this->height = world->getHeight();
	x = 0;
	y = 0;
	this->objects = world->getObjectList();
}

CWorldPart::CWorldPart(float width, float height, float x, float y)
{
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	firstPart = NULL;
	secondPart = NULL;
	thirdPart = NULL;
	fourthPart = NULL;
}


BOOL CWorldPart::checkObj(LPGAMEOBJECT Obj)
{
	float x, y;
	Obj->GetPosition(x, y);
	if (x < this->x || x > this->x + this->width) {
		return false;
	}
	if (y < this->y || y > this->y + this->height) {
		return false;
	}
	return true;
}


void CWorldPart::Split(LPWORLD world)
{
	
	if (width > CAM_WIDTH && objects.size() > 0 || height > CAM_HEIGHT && this->objects.size() > 0)
	{
		this->firstPart = new CWorldPart(this->width / 2, this->height / 2, this->x, this->y);
		this->secondPart = new CWorldPart(this->width / 2, this->height / 2, this->x, this->y + this->height / 2);
		this->thirdPart = new CWorldPart(this->width / 2, this->height / 2, this->x + this->width / 2, this->y + this->height / 2);
		this->fourthPart = new CWorldPart(this->width / 2, this->height / 2, this->x + this->width / 2, this->y);
		for (int i = 0; i < this->objects.size(); i++)
		{
			float objX, objY;
			objects[i]->GetPosition(objX, objY);
			bool isCenterObject = (this->x + this->width / 2 == objX && this->y + this->height / 2 == objY);

			if (firstPart->checkObj(this->objects[i]))
			{
				if (secondPart->checkObj(this->objects[i]) && !isCenterObject)
				{
					// Object belongs to both firstPart and secondPart
					firstPart->objects.push_back(this->objects[i]);
				}
				else if (fourthPart->checkObj(this->objects[i]) && !isCenterObject)
				{
					// Object belongs to both firstPart and fourthPart
					firstPart->objects.push_back(this->objects[i]);
				}
				else
				{
					// Object belongs only to firstPart
					firstPart->objects.push_back(this->objects[i]);
				}
			}
			else if (secondPart->checkObj(this->objects[i]))
			{
				if (thirdPart->checkObj(this->objects[i]) && !isCenterObject)
				{
					// Object belongs to both secondPart and thirdPart
					secondPart->objects.push_back(this->objects[i]);
				}
				else
				{
					// Object belongs only to secondPart
					secondPart->objects.push_back(this->objects[i]);
				}
			}
			else if (thirdPart->checkObj(this->objects[i]))
			{
				if (isCenterObject)
				{
					// Object belongs only to firstPart
					firstPart->objects.push_back(this->objects[i]);
				}
				else
				{
					// Object belongs only to thirdPart
					thirdPart->objects.push_back(this->objects[i]);
				}
			}
			else if (fourthPart->checkObj(this->objects[i]))
			{
				if (isCenterObject)
				{
					// Object belongs only to firstPart
					firstPart->objects.push_back(this->objects[i]);
				}
				else
				{
					// Object belongs only to fourthPart
					fourthPart->objects.push_back(this->objects[i]);
				}
			}
		}
		this->objects.clear();
		firstPart->Split(world);
		secondPart->Split(world);
		thirdPart->Split(world);
		fourthPart->Split(world);
	}
	else
	{
		world->getWPList().push_back(this);
	}
}

void CWorldPart::ClearWorldPart() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
	objects.clear();
}
void CWorldPart::ClearDeletedObjects() {
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i]->IsDeleted()) {
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}
}
void CWorldPart::GetObjectToTempList(vector<LPGAMEOBJECT>& a) {
	for (int i = 0; i < objects.size(); i++) {
		a.push_back(objects[i]);
	}
}
void CWorldPart::Render() {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Render();
	}
}
vector<LPGAMEOBJECT> CWorldPart::GetOutOfPartObject() {
	vector<LPGAMEOBJECT> temp;
	for (int i = 0; i < objects.size(); i++) {
		if (checkObj(objects[i]) == false) {
			temp.push_back(objects[i]);
			objects.erase(objects.begin() + i);
		}
	}
	return temp;
}
void CWorldPart::TakeNewObject(LPGAMEOBJECT obj) {
	this->objects.push_back(obj);
}