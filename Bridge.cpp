#include "Bridge.h"
CBridge::CBridge(float x, float y, float width) {
	this->x = x;
	this->y = y;
	int BridgePartCount = width / 64;
	for (int i = 0; i < BridgePartCount; i++) {
		LPBRIDGEPART bridgePart = new CBridgePart(x + 16 + i * 64, y, i);
		BridgePartList.push_back(bridgePart);
	}
}
void CBridge::Render() {
		
}
void CBridge::Explode() {
	if (isExploded == false) {
		for (int i = 0; i < BridgePartList.size(); i++) {
			BridgePartList[i]->SetState(BRIDGEPART_STATE_TRIGGER);
		}
		isExploded = true;
	}
	isDeleted = true;
}
void CBridge::PushObjectToList(vector<LPGAMEOBJECT>& a) {
	for (int i = 0; i < BridgePartList.size(); i++) {
		a.push_back(BridgePartList[i]);
	}
}

void CBridge::CreateBox(DWORD dt) {
	bbox.left = x - BRIDGEPART_WIDTH / 4;
	bbox.top = y - BRIDGEPART_HEIGHT / 2;
	bbox.right = x + BRIDGEPART_WIDTH * 0.75 + 3 * BRIDGEPART_WIDTH;
	bbox.bottom = y + BRIDGEPART_HEIGHT / 2;
	bbox.vpf_x = 0;
	bbox.vpf_y = 0;
}