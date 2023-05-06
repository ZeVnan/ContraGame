#pragma once

#include "Texture.h"
#include "Game.h"
#include "define.h"

class CSprite
{
	int id;				// Sprite ID in the sprite database

	int left;
	int top;
	int right;
	int bottom;

	LPTEXTURE texture;
	D3DX10_SPRITE sprite;
	D3DXMATRIX matScaling;
	D3DXMATRIX matRotation;
public:

	int getSpriteHeight();
	int getSpriteWidth();

	CSprite(int id, int left, int top, int right, int bottom, LPTEXTURE tex);
	CSprite(int id, CSprite* psprite);
	CSprite(int id, CSprite* psprite, int angle);

	void Draw(float x, float y);	

};

typedef CSprite* LPSPRITE;