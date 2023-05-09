#pragma once

#include<string>
#include"config.h"

class Tile
{
private:

	int _id;
	float x;
	float y;

public:
	Tile(int id, float x, float y);

	int getId() { return this->_id; }
	float getX() { return this->x; }
	float getY() { return this->y; }
};
typedef Tile* LPTILE;

