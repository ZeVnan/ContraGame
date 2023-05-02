#pragma once

#include <string>
#include <vector>
#include <stdexcept>

#include "config.h"
#include "Tile.h"

class TileSet
{
private:
	CSprite* _tileImage;
	int _widthtile;  // kích thước tile
	int _heighttile; // kích thước tile
	std::string _filename;
	int _columns;
	int _rows;
	std::vector<Tile*> _listTiles;

public:
	TileSet(eID spriteId);

	int getWidthtile() const;
	void setWidthtile(const int& value);
	int getHeighttile() const;
	void setHeighttile(const int& value);

	void loadListTiles(pugi::xml_node& node);
	CSprite* getSprite();
};
