#include "Land.h"

CLand::CLand(float x, float y, float width) {
	int grassCount = width / 64;
	for (int i = 0; i < grassCount; i++) {
		LPGRASS grass = new CGrass(x + 16 + i * 64, y);
		grassList.push_back(grass);
	}
}
void CLand::PushObjectToList(vector<LPGAMEOBJECT>& a) {
	for (int i = 0; i < grassList.size(); i++) {
		a.push_back(grassList[i]);
	}
}