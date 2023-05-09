#include "TileSet.h"
#include "Tile.h"

TileSet::TileSet(LPTEXTURE tex)
{
	this->tex = tex;
}

void TileSet::loadListTiles(pugi::xml_node& node, CSprites*& sprites)
{
	/*	
		tilelistnode chứa tất cả các element <Tile> trong file xml.
		Cấu trúc dạng:
		<Tiles>
			<Tile>
		<Tiles>
	*/
	auto tilelistnode = node.child("Tiles").children();
	Tile* tile = nullptr;
	int id = 0;
	float left = 0, top = 0, right = 0, bottom = 0;
	for (pugi::xml_node_iterator it : tilelistnode)
	{
		id = it->attribute("Id").as_int();
		left = it->child("Rect").attribute("X").as_int();
		top = it->child("Rect").attribute("Y").as_int();
		right = left + it->child("Rect").attribute("Height").as_int() + 1;
		bottom = top + it->child("Rect").attribute("Width").as_int() + 1;
		sprites->Add(id, left, top, right, bottom, this->tex);
	}
}

int TileSet::getWidthtile() const
{
	return _widthtile;
}

void TileSet::setWidthtile(const int& value)
{
	this->_widthtile = value;
}

int TileSet::getHeighttile() const
{
	return this->_heighttile;
}

void TileSet::setHeighttile(const int& value)
{
	this->_heighttile = value;
}
