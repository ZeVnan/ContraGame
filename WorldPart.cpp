#include "WorldPart.h"

CWorldPart::CWorldPart()
{
	width = 0;
	height = 0;
	x = 0;
	y = 0;
	firstPart = NULL;
	secondPart = NULL;
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


void CWorldPart::HorizontalSplit(LPWORLD world)
{
	
	if (width > CAM_WIDTH && objects.size() > 0)
	{
		this->firstPart = new CWorldPart(this->width / 2, this->height, this->x, this->y);
		this->secondPart = new CWorldPart(this->width / 2, this->height, this->x + this->width / 2, this->y);

		for (int i = 0; i < this->objects.size(); i++)
		{
			if (firstPart->checkObj(this->objects[i]) && secondPart->checkObj(this->objects[i]))
			{
				firstPart->objects.push_back(this->objects[i]);
			}
			else if (firstPart->checkObj(this->objects[i]))
			{
				firstPart->objects.push_back(this->objects[i]);
			}
			else if (secondPart->checkObj(this->objects[i]))
			{
				secondPart->objects.push_back(this->objects[i]);
			}
		}
		this->objects.clear();
		firstPart->HorizontalSplit(world);
		secondPart->HorizontalSplit(world);
	}
	else
	{
		world->getWPList().push_back(this);
	}
}

void CWorldPart::VerticalSplit(LPWORLD world)
{
	if (height > CAM_HEIGHT && this->objects.size() > 0)
	{
		this->firstPart = new CWorldPart(this->width, this->height / 2, this->x, this->y);
		this->secondPart = new CWorldPart(this->width, this->height / 2, this->x, this->y + this->height / 2);

		for (int i = 0; i < this->objects.size(); i++)
		{
			if (firstPart->checkObj(this->objects[i]) && secondPart->checkObj(this->objects[i]))
			{
				firstPart->objects.push_back(this->objects[i]);
			}
			else if (firstPart->checkObj(this->objects[i]))
			{
				firstPart->objects.push_back(this->objects[i]);
			}
			else if (secondPart->checkObj(this->objects[i]))
			{
				secondPart->objects.push_back(this->objects[i]);
			}
		}
		this->objects.clear();
		firstPart->VerticalSplit(world);
		secondPart->VerticalSplit(world);
	}
	else
	{
		world->getWPList().push_back(this);
	}
}

void CWorldPart::Split(LPWORLD world)
{
	if (world->getHeight() < world->getWidth())
	{
		HorizontalSplit(world);
	}
	else
	{
		VerticalSplit(world);
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