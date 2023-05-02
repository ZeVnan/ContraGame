#include "Tile.h"

Tile::Tile(CSprite* refSprite, RECT srcRect, int id)
{
	this->_id = id;
	this->_srcRect = srcRect;
	this->_refSprite = refSprite;

}


const int& Tile::getId() const
{
	return this->_id;
}