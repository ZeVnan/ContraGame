#pragma once
#include "Water.h"
class CWaters : public CGameObject
{
private:
	vector<LPWATER> waterList;
public:
	CWaters(float x, float y, float width);
	void PushObjectToList(vector<LPGAMEOBJECT>& a);
	void Render() {};
};
typedef CWaters* LPWATERS;

