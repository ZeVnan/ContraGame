#include "Falcon.h"
#include "Grass.h"
#include "Aircraft.h"

CFalcon::CFalcon(float x, float y) :CGameObject(x, y) {
	this->state = FALCON_STATE_CLOSE;
	this->ammo = rand() % 5 + 16002;
	timeleft = FALCON_CLOSE_TIME;
	isExploded = false;
	isCollectible = false;
	ay = 0;
}
void CFalcon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (this->isExploded == false) {
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
	}
	else {
		if (isCollectible == false) {
			this->timeleft -= dt;
			if (this->timeleft < 0) {
				SetState(FALCON_STATE_DROPITEM);
			}	
		}
		else {
			CCollision::GetInstance()->Process(this, coObjects, dt);
		}
	}
	//DebugOutTitle(L"vy = %f, y = %f, ay = %f", vy, y, ay);
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
		break;
	}
	if (isExploded == true) {
		if (isCollectible == false) {
			ani = EXPLOSION_2_ANI;
		}
		else {
			switch (ammo) {
			case FALCON_bAMMO:
				ani = AIRCRAFT_ANI_bAMMO;
				break;
			case FALCON_fAMMO:
				ani = AIRCRAFT_ANI_fAMMO;
				break;
			case FALCON_lAMMO:
				ani = AIRCRAFT_ANI_lAMMO;
				break;
			case FALCON_mAMMO:
				ani = AIRCRAFT_ANI_mAMMO;
				break;
			case FALCON_rAMMO:
				ani = AIRCRAFT_ANI_rAMMO;
				break;
			case FALCON_sAMMO:
				ani = AIRCRAFT_ANI_sAMMO;
				break;
			}
		}
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
	case FALCON_STATE_EXPLODE:
		this->isExploded = true;
		timeleft = TIME_EXPLODE;
		break;
	case FALCON_STATE_DROPITEM:
		isCollectible = true;
		ay = FALCON_GRAVITY;
		vy = FALCON_SPEED_Y;
		break;
	}
	CGameObject::SetState(state);
}

void CFalcon::CreateBox(DWORD dt) {
	if (isCollectible == false) {
		bbox.left = x - FALCON_BOX_WIDTH / 2;
		bbox.top = y - FALCON_BOX_HEIGHT / 2;
		bbox.right = x + FALCON_BOX_WIDTH / 2;
		bbox.bottom = y + FALCON_BOX_HEIGHT / 2;
	}
	else {
		bbox.left = (x - FALCON_ITEM_BOX_WIDTH / 2);
		bbox.top = (y - FALCON_ITEM_BOX_HEIGHT / 2);
		bbox.right = (x + FALCON_ITEM_BOX_WIDTH / 2);
		bbox.bottom = (y + FALCON_ITEM_BOX_HEIGHT / 2);
	}
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}

void CFalcon::NoCollision(DWORD dt) {
	vy += ay * dt;
	x += vx * dt;
	y += vy * dt;
}
void CFalcon::CollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPGRASS>(e->dest_obj)) {
		CollisionWithGrass(e);
	}
}
void CFalcon::CollisionWithGrass(LPCOLLISIONEVENT e) {
	if (e->normal_y < 0) {
		this->y += bbox.vpf_y;
	}
	if (e->normal_y > 0) {
		this->y += e->time * bbox.vpf_y;
	}
}