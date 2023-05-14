#pragma once
#include "BridgePart.h"
class CBridge : public CGameObject
{
private:
	vector<LPBRIDGEPART>BridgePartList;
public:
	CBridge(float x, float y, float width);
	void PushObjectToList(vector<LPGAMEOBJECT>& a);
	
	void Explode();
	
	void Render();

	void CreateBox(DWORD dt);
	bool isBlocking() { return false; }
};
typedef CBridge* LPBRIDGE;

