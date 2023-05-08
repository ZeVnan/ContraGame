#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Collision.h"
#include "Textures.h"
#include "LoadResource.h"

CGameObject::CGameObject()
{
	x = y = 0;
	vx = vy = 0;
	nx = 1;	
	state = -1;
	isDeleted = false;
	isExploded = false;
}
void CGameObject::RenderBox() {
	RECT* rect = new RECT();
	LPTEXTURE texBox = CTextures::GetInstance()->Get(ID_TEX_BOX);

	rect->left = 0;
	rect->top = 0;
	rect->right = bbox.right - bbox.left;
	rect->bottom = bbox.bottom - bbox.top;

	float cx = x, cy = y;
	CGame::GetInstance()->GetCamera()->TranslateToCamCoord(cx, cy);
	CGame::GetInstance()->Draw(cx, cy, texBox, rect);
}