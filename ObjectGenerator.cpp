#include "ObjectGenerator.h"
#include "WorldPart.h"
#include "RockFall.h"
#include "Soldier.h"
#include "Bill.h"
extern LPBILL bill;

CObjectGenerator::CObjectGenerator(float x, float y, int type, int stage) :CGameObject(x, y){
	this->type = type;
	this->stage = stage;
	parent = NULL;
	timeLeft = 0;
	isActivated = false;
}
void CObjectGenerator::AddObject() {
	if (type == 1) {
		LPROCKFALL rockfall = new CRockFall(this->x, this->y);
		parent->TakeNewObject(rockfall);
		objects.push_back(rockfall);
	}
	if (type == 2) {
		LPSOLDIER soldier = new CSoldier(this->x, this->y);
		parent->TakeNewObject(soldier);
		objects.push_back(soldier);
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
void CObjectGenerator::watchBill() {
	float x, y;
	bill->GetPosition(x, y);
	float distance = (float)sqrt(pow(x - this->x, 2) + pow(y - this->y, 2));
	if (distance <= OBJ_GENERATOR_ACTIVE_RADIUS) {
		isActivated = true;
	}
	else {
		isActivated = false;
	}
}
void CObjectGenerator::UpdateObjects() {
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] == NULL) {
			objects.erase(objects.begin() + i);
			i--;
		}
		else if (objects[i]->IsDeleted()){
			objects.erase(objects.begin() + i);
			i--;
		}
	}
}
void CObjectGenerator::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	watchBill();
	UpdateObjects();
	if (InScreen() == true && type == 2 && stage == 1)
		return;
	if (objects.size() >= 3 || isActivated == false)
		return;
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		timeLeft = OBJ_GENERATOR_WAIT_TIME;
		AddObject();
	}
}

