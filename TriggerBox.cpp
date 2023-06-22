#include "TriggerBox.h"


TriggerBox::TriggerBox(float x, float y, int type) :CGameObject(x, y) {
	this->type = type;
}

void TriggerBox::Render() {
	//RenderBox();
}

void TriggerBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

}

void TriggerBox::CreateBox(DWORD dt){
	bbox.left = x - TRIGGERBOX_BOX_WIDTH / 2;
	bbox.top = y + TRIGGERBOX_BOX_HEIGHT / 2;
	bbox.right = x + TRIGGERBOX_BOX_WIDTH / 2;
	bbox.bottom = y - TRIGGERBOX_BOX_HEIGHT / 2;
}