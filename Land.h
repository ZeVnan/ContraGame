#pragma once
#include "Grass.h"
class CLand : public CGameObject
{
private:
	vector<LPGRASS>grassList;
public:
	CLand(float x, float y, float width);
	void PushObjectToList(vector<LPGAMEOBJECT>& a);
	void Render() {};
};
typedef CLand* LPLAND;
