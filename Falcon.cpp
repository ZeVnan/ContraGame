#include "Falcon.h"

CFalcon::CFalcon(float x, float y) :CGameObject(x, y) {
	this->state = 0;
	timeleft = FALCON_CLOSE_TIME;
}
void CFalcon::Update(DWORD dt) {
	this->timeleft -= dt;
	if (this->timeleft < 0) {
		switch (this->state) {
		case FALCON_STATE_CLOSE:
			this->SetState(FALCON_STATE_OPENING);
			break;
		case FALCON_STATE_OPENING:
			this->SetState(FALCON_STATE_OPEN);
			break;
		case FALCON_STATE_OPEN:
			this->SetState(FALCON_STATE_CLOSING);
			break;
		case FALCON_STATE_CLOSING:
			this->SetState(FALCON_STATE_CLOSE);
			break;
		}
	}
	//DebugOutTitle(L"state = %d, timeleft = %d", this->state, this->timeleft);
}
void CFalcon::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	switch (this->state) {
	case FALCON_STATE_CLOSE:
		ani = FALCON_ANI_CLOSED;
		break;
	case FALCON_STATE_OPENING:
		ani = FALCON_ANI_OPENING;
		break;
	case FALCON_STATE_OPEN:
		ani = FALCON_ANI_OPENED;
		break;
	case FALCON_STATE_CLOSING:
		ani = FALCON_ANI_CLOSING;
	}
	animations->Get(ani)->Render(x, y);
}
void CFalcon::SetState(int state) {
	switch (state) {
	case FALCON_STATE_OPEN:
		this->timeleft = FALCON_OPEN_TIME;
		break;
	case FALCON_STATE_OPENING:
		this->timeleft = FALCON_OPENING_TIME;
		break;
	case FALCON_STATE_CLOSE:
		this->timeleft = FALCON_CLOSE_TIME;
		break;
	case FALCON_STATE_CLOSING:
		this->timeleft = FALCON_CLOSING_TIME;
		break;
	}
	CGameObject::SetState(state);
}