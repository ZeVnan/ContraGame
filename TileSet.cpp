#include "TileSet.h"
#include "Tile.h"

TileSet::TileSet(eID spriteId)
{
	CSprite* sp = CSprites::GetInstance()->Get(spriteId);
	this->_tileImage = sp;
	this->_heighttile = sp->getSpriteHeight();
	this->_widthtile = sp->getSpriteWidth();

}

void TileSet::loadListTiles(pugi::xml_node& node)
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
	RECT srcRECT = { 0,0,0,0 };
	int id = 0;
	for (pugi::xml_node_iterator it : tilelistnode)
	{
		id = it->attribute("Id").as_int();
		srcRECT.top = it->child("Rect").attribute("Y").as_int();
		srcRECT.left = it->child("Rect").attribute("X").as_int();
		srcRECT.bottom = srcRECT.top + it->child("Rect").attribute("Width").as_int() + 1;
		srcRECT.right = srcRECT.left + it->child("Rect").attribute("Height").as_int() + 1;
		this->_listTiles.push_back(new Tile(this->_tileImage, srcRECT, id));
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

CSprite* TileSet::getSprite()
{
	return this->_tileImage;
}