﻿#include "Sprite.h"

int CSprite::getSpriteWidth() {
	return (this->right - this->left + 1);
}
int CSprite::getSpriteHeight() {
	return (this->bottom - this->top + 1);
}

CSprite::CSprite(int id, int left, int top, int right, int bottom, LPTEXTURE tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;

	// Set the sprite’s shader resource view
	sprite.pTexture = tex->getShaderResourceView();

	int spriteWidth = (this->right - this->left + 1);
	int spriteHeight = (this->bottom - this->top + 1);

	sprite.TexCoord.x = this->left / (float)tex->getWidth();
	sprite.TexCoord.y = this->top / (float)tex->getHeight();

	sprite.TexSize.x = spriteWidth / (float)tex->getWidth();
	sprite.TexSize.y = spriteHeight / (float)tex->getHeight();

	sprite.ColorModulate = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	sprite.TextureIndex = 0;

	//D3DXMatrixScaling(&this->matScaling, (FLOAT)spriteWidth, (FLOAT)spriteHeight, 1.0f);
	D3DXMatrixRotationZ(&this->matRotation, D3DXToRadian(0));
}
CSprite::CSprite(int id, CSprite* psprite) {
	this->id = id;
	this->left = psprite->left;
	this->right = psprite->right;
	this->top = psprite->top;
	this->bottom = psprite->bottom;
	this->texture = psprite->texture;

	int spriteWidth = getSpriteHeight();
	int spriteHeight = getSpriteWidth();

	this->sprite.pTexture = psprite->sprite.pTexture;

	this->sprite.TexCoord.x = psprite->sprite.TexCoord.x + psprite->sprite.TexSize.x;
	this->sprite.TexCoord.y = psprite->sprite.TexCoord.y;

	this->sprite.TexSize.x = -psprite->sprite.TexSize.x;
	this->sprite.TexSize.y = psprite->sprite.TexSize.y;

	this->sprite.ColorModulate = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	this->sprite.TextureIndex = 0;
	//D3DXMatrixScaling(&this->matScaling, (FLOAT)spriteWidth, (FLOAT)spriteHeight, 1.0f);
	D3DXMatrixRotationZ(&this->matRotation, D3DXToRadian(0));
}
CSprite::CSprite(int id, CSprite* psprite, int angle) {
	this->id = id;
	this->left = psprite->left;
	this->right = psprite->right;
	this->top = psprite->top;
	this->bottom = psprite->bottom;
	this->texture = psprite->texture;
	this->sprite = psprite->sprite;

	int spriteWidth = (this->right - this->left + 1);
	int spriteHeight = (this->bottom - this->top + 1);
	
	D3DXMatrixRotationZ(&this->matRotation, D3DXToRadian(angle));
	//D3DXMatrixScaling(&this->matScaling, (FLOAT)spriteWidth, (FLOAT)spriteHeight, 1.0f);
}



void CSprite::Draw(float x, float y)
{
	CGame* g = CGame::GetInstance();

	float cx, cy, cw, ch;
	cx = x;
	cy = y;
	g->GetCamera()->TranslateToCamCoord(cx, cy);
	cw = g->GetCamera()->GetCamWidth();
	ch = g->GetCamera()->GetCamHeight();
	D3DXMatrixScaling(&this->matScaling, (FLOAT)getSpriteWidth() * 2, (FLOAT)getSpriteHeight() * 2, 2.0f);
	D3DXMATRIX matTranslation;
	D3DXMatrixTranslation(
		&matTranslation,
		cx + (SCREEN_WIDTH - cw) / 2,
		g->GetBackBufferHeight() - cy - (SCREEN_HEIGHT - ch) / 2,
		0.1f);

	this->sprite.matWorld = (this->matScaling *this->matRotation* matTranslation);
	g->GetSpriteHandler()->DrawSpritesImmediate(&sprite, 1, 0, 0);
}
void CSprite::DrawTile(float x, float y) {
	CGame* g = CGame::GetInstance();

	float cx, cy, cw, ch;
	cx = x;
	cy = y;
	g->GetCamera()->TranslateToCamCoord(cx, cy);
	cw = g->GetCamera()->GetCamWidth();
	ch = g->GetCamera()->GetCamHeight();
	D3DXMatrixScaling(&this->matScaling, (FLOAT)getSpriteWidth(), (FLOAT)getSpriteHeight(), 1.0f);
	D3DXMATRIX matTranslation;
	D3DXMatrixTranslation
	(&matTranslation,
		cx + (SCREEN_WIDTH - cw) / 2,
		g->GetBackBufferHeight() - cy - (SCREEN_HEIGHT - ch) / 2,
		0.1f);

	this->sprite.matWorld = (this->matScaling * this->matRotation * matTranslation);
	g->GetSpriteHandler()->DrawSpritesImmediate(&sprite, 1, 0, 0);
}
