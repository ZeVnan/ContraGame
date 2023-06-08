﻿#pragma once
#include "GameObject.h"
#include "debug.h"

#define TRIGGERBOX_BOX_WIDTH	16
#define TRIGGERBOX_BOX_HEIGHT	16

class TriggerBox : public CGameObject
{
private:
	int type;// 1-nhảy 2-bắn 3-nằm


public:
	TriggerBox(float x, float y, int type);

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL);
	void CreateBox(DWORD dt);
};


typedef TriggerBox* LPTRIGGERBOX;

