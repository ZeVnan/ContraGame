#pragma once
#include "GameObject.h"
#include "debug.h"

#define TRIGGERBOX_BOX_WIDTH	16
#define TRIGGERBOX_BOX_HEIGHT	16

class TriggerBox : public CGameObject
{
private:
	int type;// 1-jump 2-drop 3-shoot


public:
	TriggerBox(float x, float y, int type);

	bool isBlocking() { return false; }
	int getType() { return type; }

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void CreateBox(DWORD dt);
};


typedef TriggerBox* LPTRIGGERBOX;

