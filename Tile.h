#pragma once

#include<string>
#include"config.h"

class Tile
{
private:

	int _id;
	RECT _srcRect;
	CSprite* _refSprite; // ảnh gồm nhiều tile. khi vẽ cắt bằng srcRect như Sprite

public:

	const int& getId() const;

	Tile(CSprite* refSprite, RECT srcRect, int id);
};

