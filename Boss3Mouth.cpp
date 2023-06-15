#include "Boss3Mouth.h"
extern int score;
CBoss3Mouth::CBoss3Mouth(float x, float y) : CGameObject(x, y) {
	HP = 500;
	timeLeft = BOSS3MOUTH_TIME_CLOSE;
	isDead = false;
	isClosed = true;
	state = BOSS3MOUTH_STATE_CLOSE;
	bulletLeft = 0;
}
void CBoss3Mouth::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (timeLeft > 0) {
		timeLeft -= dt;
	}
	else {
		switch (state) {
		case BOSS3MOUTH_STATE_CLOSE:
			SetState(BOSS3MOUTH_STATE_OPENING);
			break;
		case BOSS3MOUTH_STATE_OPENING:
			SetState(BOSS3MOUTH_STATE_OPEN);
			break;
		case BOSS3MOUTH_STATE_OPEN:
			if (bulletLeft > 0) {
				AddBullet();
				bulletLeft--;
				timeLeft = BOSS3MOUTH_TIME_RELOAD;
			}
			else {
				SetState(BOSS3MOUTH_STATE_CLOSING);
			}
			break;
		case BOSS3MOUTH_STATE_CLOSING:
			SetState(BOSS3MOUTH_STATE_CLOSE);
			break;
		case BOSS3MOUTH_STATE_EXPLODE:
			SetState(BOSS3MOUTH_STATE_DEAD);
			break;
		}
		if (isExploded == false && HP <= 0) {
			SetState(BOSS3MOUTH_STATE_EXPLODE);
		}
	}
	UpdateBullet(dt, coObjects);
	//DebugOutTitle(L"bulletLeft = %d, bullet = %d", bulletLeft, bullets.size());
}
void CBoss3Mouth::Render() {
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	switch (state) {
	case BOSS3MOUTH_STATE_CLOSE:
		ani = BOSS3MOUTH_ANI_CLOSE;
		break;
	case BOSS3MOUTH_STATE_OPENING:
		ani = BOSS3MOUTH_ANI_OPENING;
		break;
	case BOSS3MOUTH_STATE_OPEN:
		ani = BOSS3MOUTH_ANI_OPEN;
		break;
	case BOSS3MOUTH_STATE_CLOSING:
		ani = BOSS3MOUTH_ANI_OPENING;
		break;
	case BOSS3MOUTH_STATE_EXPLODE:
		ani = EXPLOSION_2_ANI;
		break;
	}
	if (isDead == true) {
		ani = BOSS3MOUTH_ANI_MOUDLER;
	}
	animations->Get(ani)->Render(x, y);
	if (isDead == true) {
		animations->Get(ARROW_ANI)->Render(x, y + 50);
	}
	RenderBullet();
	//RenderBox();
}
void CBoss3Mouth::SetState(int state) {
	switch (state) {
	case BOSS3MOUTH_STATE_CLOSE:
		isClosed = true;
		timeLeft = BOSS3MOUTH_TIME_CLOSE;
		break;
	case BOSS3MOUTH_STATE_OPENING:
		timeLeft = BOSS3MOUTH_TIME_OPENING;
		break;
	case BOSS3MOUTH_STATE_OPEN:
		timeLeft = BOSS3MOUTH_TIME_RELOAD;
		bulletLeft = BOSS3MOUTH_BULLET_PER_WAVE;
		isClosed = false;
		break;
	case BOSS3MOUTH_STATE_CLOSING:
		timeLeft = BOSS3MOUTH_TIME_OPENING;
		break;
	case BOSS3MOUTH_STATE_EXPLODE:
		isExploded = true;
		timeLeft = TIME_EXPLODE * 3;
		score += 100;
		break;
	case BOSS3MOUTH_STATE_DEAD:
		isDead = true;
		y -= 192;
		break;
	}
	CGameObject::SetState(state);
}

void CBoss3Mouth::CreateBox(DWORD dt) {
	if (isDead == false) {
		bbox.left = x - BOSS3MOUTH_BOX_NORMAL_WIDTH / 2;
		bbox.top = y - 35 + BOSS3MOUTH_BOX_NORMAL_HEIGHT / 2;
		bbox.right = x + BOSS3MOUTH_BOX_NORMAL_WIDTH / 2;
		bbox.bottom = y - 35 - BOSS3MOUTH_BOX_NORMAL_HEIGHT / 2;
	}
	else {
		bbox.left = x - BOSS3MOUTH_BOX_DEAD_WIDTH / 2;
		bbox.top = y + BOSS3MOUTH_BOX_DEAD_HEIGHT / 2;
		bbox.right = x + BOSS3MOUTH_BOX_DEAD_WIDTH / 2;
		bbox.bottom = y - BOSS3MOUTH_BOX_DEAD_HEIGHT / 2;
	}
	bbox.vpf_x = 0;
	bbox.vpf_y = 0;
}
void CBoss3Mouth::NoCollision(DWORD dt) {

}
void CBoss3Mouth::CollisionWith(LPCOLLISIONEVENT e) {

}

void CBoss3Mouth::AddBullet() {
	int a = rand() % 5 + 7;
	bullets.push_back(new CBulletBoss3(x, y, a * 30, false));
}
void CBoss3Mouth::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i]->outOfScreen() || bullets[i]->IsDeleted()) {
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
		else {
			bullets[i]->Update(dt, coObjects);
		}
	}
}
void CBoss3Mouth::RenderBullet() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
}