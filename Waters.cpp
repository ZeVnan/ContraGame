#include "Waters.h"
CWaters::CWaters(float x, float y, float width) {
	int waterCount = width / 64;
	for (int i = 0; i < waterCount; i++) {
		LPWATER water = new CWater(x + 16 + i * 64, y);
		waterList.push_back(water);
	}
}
void CWaters::PushObjectToList(vector<LPGAMEOBJECT>& a) {
	for (int i = 0; i < waterList.size(); i++) {
		a.push_back(waterList[i]);
	}
}