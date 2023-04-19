#include "WorldPart.h"

CWorldPart::CWorldPart()
{
	width = 0;
	height = 0;
	x = 0;
	y = 0;
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
	if (x <= this->x && x >= this->x + this->width) {
		return false;
	}
	if (y <= this->y && y >= this->y + this->height) {
		return false;
	}
	return true;
}


void CWorldPart::VerticalSplit(LPWORLD world)
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
		firstPart->VerticalSplit(world);
		secondPart->VerticalSplit(world);
	}
	else
	{
		world->getWPList().push_back(this);
	}
}

void CWorldPart::HorizontalSplit(LPWORLD world)
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
		VerticalSplit(world);
	}
	else
	{
		HorizontalSplit(world);
	}
}