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
	this->tiles = world->getTileList();
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

BOOL CWorldPart::checkTile(LPTILE tile) {
	float x, y;
	x = tile->getX();
	y = tile->getY();
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
	float cw, ch;
	cw = CGame::GetInstance()->GetCamera()->GetCamWidth();
	ch = CGame::GetInstance()->GetCamera()->GetCamHeight();
	if ((width > cw || height > ch) && this->objects.size() > 0)
	{
		this->firstPart = new CWorldPart(this->width / 2, this->height / 2, this->x, this->y);
		this->secondPart = new CWorldPart(this->width / 2, this->height / 2, this->x, this->y + this->height / 2);
		this->thirdPart = new CWorldPart(this->width / 2, this->height / 2, this->x + this->width / 2, this->y + this->height / 2);
		this->fourthPart = new CWorldPart(this->width / 2, this->height / 2, this->x + this->width / 2, this->y);
		//split tile
		for (int i = 0; i < this->tiles.size(); i++)
		{
			float tileX, tileY;
			tileX = tiles[i]->getX();
			tileY = tiles[i]->getY();
			bool isCenterTile = (this->x + this->width / 2 == tileX && this->y + this->height / 2 == tileY);

			if (firstPart->checkTile(this->tiles[i]))
			{
				if (secondPart->checkTile(this->tiles[i]) && !isCenterTile)
				{
					// Object belongs to both firstPart and secondPart
					firstPart->tiles.push_back(this->tiles[i]);
				}
				else if (fourthPart->checkTile(this->tiles[i]) && !isCenterTile)
				{
					// Object belongs to both firstPart and fourthPart
					firstPart->tiles.push_back(this->tiles[i]);
				}
				else
				{
					// Object belongs only to firstPart
					firstPart->tiles.push_back(this->tiles[i]);
				}
			}
			else if (secondPart->checkTile(this->tiles[i]))
			{
				if (thirdPart->checkTile(this->tiles[i]) && !isCenterTile)
				{
					// Object belongs to both secondPart and thirdPart
					secondPart->tiles.push_back(this->tiles[i]);
				}
				else
				{
					// Object belongs only to secondPart
					secondPart->tiles.push_back(this->tiles[i]);
				}
			}
			else if (thirdPart->checkTile(this->tiles[i]))
			{
				if (isCenterTile)
				{
					// Object belongs only to firstPart
					firstPart->tiles.push_back(this->tiles[i]);
				}
				else
				{
					// Object belongs only to thirdPart
					thirdPart->tiles.push_back(this->tiles[i]);
				}
			}
			else if (fourthPart->checkTile(this->tiles[i]))
			{
				if (isCenterTile)
				{
					// Object belongs only to firstPart
					firstPart->tiles.push_back(this->tiles[i]);
				}
				else
				{
					// Object belongs only to fourthPart
					fourthPart->tiles.push_back(this->tiles[i]);
				}
			}
		}
		this->tiles.clear();
		//split object
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
		if (dynamic_cast<LPBILL>(objects[i]))
			continue;				//just make sure bill not be obscured by other objects
		objects[i]->Render();
	}
}
void CWorldPart::DrawTile() {
	CSprites* sprites = CSprites::GetInstance();
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->getY() == 4320) {
			int a = 0;
		}
		sprites->Get(tiles[i]->getId())->DrawTile(tiles[i]->getX(), tiles[i]->getY());
	}
}
void CWorldPart::GetOutOfPartObject(vector<LPGAMEOBJECT>& a) {
	for (int i = 0; i < objects.size(); i++) {
		if (checkObj(objects[i]) == false) {
			a.push_back(objects[i]);
			objects.erase(objects.begin() + i);
		}
	}
}
void CWorldPart::TakeNewObject(LPGAMEOBJECT obj) {
	this->objects.push_back(obj);
}