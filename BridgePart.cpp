#include "BridgePart.h"
#include "Animations.h"
#include "debug.h"
CBridgePart::CBridgePart(float x, float y, int number) :CGameObject(x, y) {
	this->number = number;
	isTriggered = false;
	isExploded = false;
	this->state = BRIDGEPART_STATE_NORMAL;
	this->timeLeft = 0;
}
void CBridgePart::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (isTriggered == false)
		return;
	else {
		timeLeft -= dt;
		if (timeLeft < 0) {
			if (isExploded == false) {
				SetState(BRIDGEPART_STATE_EXPLODE);
			}
			else {
				isDeleted = true;
			}
		}
	}
}
void CBridgePart::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	if (isExploded == true) {
		animations->Get(EXPLOSION_2_ANI)->Render(x, y);
	}
	else {
		float d = 12;
		switch (number) {
		case 0:
			animations->Get(BRIDGEPART_ANI_DOWNBEGIN)->Render(x - BRIDGEPART_WIDTH / 4, y - BRIDGEPART_HEIGHT / 4 + d);
			animations->Get(BRIDGEPART_ANI_DOWN)->Render(x + BRIDGEPART_WIDTH / 4, y - BRIDGEPART_HEIGHT / 4 + d);
			break;
		case 3:
			animations->Get(BRIDGEPART_ANI_DOWN)->Render(x - BRIDGEPART_WIDTH / 4, y - BRIDGEPART_HEIGHT / 4 + d);
			animations->Get(BRIDGEPART_ANI_DOWNEND)->Render(x + BRIDGEPART_WIDTH / 4, y - BRIDGEPART_HEIGHT / 4 + d);
			break;
		default:
			animations->Get(BRIDGEPART_ANI_DOWN)->Render(x - BRIDGEPART_WIDTH / 4, y - BRIDGEPART_HEIGHT / 4 + d);
			animations->Get(BRIDGEPART_ANI_DOWN)->Render(x + BRIDGEPART_WIDTH / 4, y - BRIDGEPART_HEIGHT / 4 + d);
		}
		animations->Get(BRIDGEPART_ANI_UPLEFT)->Render(x - BRIDGEPART_WIDTH / 4, y + BRIDGEPART_HEIGHT / 4 + d);
		animations->Get(BRIDGEPART_ANI_UPRIGHT)->Render(x + BRIDGEPART_WIDTH / 4, y + BRIDGEPART_HEIGHT / 4 + d);
	}
	
	//RenderBox();
}
void CBridgePart::SetState(int state) {
	switch (state) {
	case BRIDGEPART_STATE_EXPLODE:
		isExploded = true;
		timeLeft = TIME_EXPLODE;
		break;
	case BRIDGEPART_STATE_TRIGGER:
		isTriggered = true;
		timeLeft = TIME_TO_EXPLODE * number;
		break;
	}
	CGameObject::SetState(state);
}
void CBridgePart::CreateBox(DWORD dt) {
	bbox.left = x - BRIDGEPART_WIDTH / 2;
	bbox.top = y + BRIDGEPART_HEIGHT / 2;
	bbox.right = x + BRIDGEPART_WIDTH / 2;
	bbox.bottom = y - BRIDGEPART_HEIGHT / 2;
	bbox.vpf_x = 0;
	bbox.vpf_y = 0;
}