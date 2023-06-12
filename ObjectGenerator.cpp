#include "ObjectGenerator.h"
#include "WorldPart.h"
#include "RockFall.h"
#include "Soldier.h"

CObjectGenerator::CObjectGenerator(float x, float y, int type) :CGameObject(x, y){
	this->type = type;
	parent = NULL;
}
void CObjectGenerator::AddObject() {
	if (type == 1) {
		LPROCKFALL rockfall = new CRockFall(this->x, this->y);
		parent->TakeNewObject(rockfall);
	}
	if (type == 2) {
		LPSOLDIER soldier = new CSoldier(this->x, this->y);
		parent->TakeNewObject(soldier);
	}
}
bool CObjectGenerator::InScreen() {
	float cx, cy, cw, ch;
	CGame::GetInstance()->GetCamera()->GetCamPos(cx, cy);
	cw = CGame::GetInstance()->GetCamera()->GetCamWidth();
	ch = CGame::GetInstance()->GetCamera()->GetCamHeight();
	if (x >= (cx - cw / 2) && x <= (cx + cw / 2) && y >= (cy - ch / 2) && y <= (cy + ch / 2))
		return true;
	return false;
}
void CObjectGenerator::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (InScreen() == true && type == 2)
		return;
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		timeLeft = WAIT_TIME;
		AddObject();
	}
}

