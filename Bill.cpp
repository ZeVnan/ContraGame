#include "Bill.h"

#include "Grass.h"
#include "Water.h"
#include "BridgePart.h"
#include "Bridge.h"
#include "RockFly.h"
#include "Aircraft.h"
#include "Falcon.h"
#include "Boss1Shield.h"
#include "Boss3Mouth.h"
#include "Soldier.h"

#include "SampleKeyEventHandler.h"
#include "Game.h"
extern gameScreen gameControl;
CBill::CBill(float x, float y,  int stage) :CGameObject(x, y) {
	isLaying = false;
	isShooting = false;
	isSwimming = false;
	isDiving = false;
	isOnPlatform = false;
	isDropping = false;
	isJumping = true;
	isDying = false;
	disableDrop = false;
	isDead = false;
	isVulnerable = true;
	ny = 0;
	maxVx = 0.0f;
	maxVy = 0.0f;
	gunx = x;
	guny = y;
	this->stage = stage;

	bulletType = BULLET_ANI_NORMAL;
	waveLeft = BILL_WAVE_BULLET_NORMAL;
	bonusWave = 0;

	bulletMtime = 0;
	timeLeft = 0;
	lifeLeft = 4;

	if (stage == 1) {
		minX = 10;
		minY = 50;
		maxX = 6636;
		maxY = 448;
	}
	else{
		minX = 10;
		minY = 100;
		maxX = 480;
		maxY = 4435;
	}
	a = false;
}
void CBill::worldControl() {
	//DebugOutTitle(L"minX = %f, minY = %f, maxX = %f, maxY = %f", minX, minY, maxX, maxY);
	switch (stage) {
	case 1:
		if (x < minX)
			x = minX;
		if (vy < 0 && y < minY)
		{
			if (isDying == true) {
				y = minY;
			}
			else {
				SetState(BILL_STATE_DYING_RIGHT);
			}
		}
		if (vx > 0 && x > maxX) {
			gameControl = waiting3;
		}
		if (vy > 0 && y > maxY)
			y = maxY;
		if (x > 6432 && x < 6464) {
			this->SetState(BILL_STATE_JUMP);
		}
		if (lifeLeft <= 0) {
			gameControl = gameover;
		}
		break;
	case 3:
		if (x < minX)
			x = minX;
		if (vy < 0 && y < minY)
		{
			if (isDying == true) {
				y = minY;
			}
			else {
				SetState(BILL_STATE_DYING_RIGHT);
			}
		}
		if (vx > 0 && x > maxX) {
			x = maxX;
		}
		if (vy > 0 && y > maxY)
			y = maxY;
		if (lifeLeft <= 0) {
			gameControl = gameover;
		}
		if (y >= 3900 || y <= 135) {
			disableDrop = true;
		}
		else {
			disableDrop = false;
		}
		break;
	}
}
void CBill::Die() {
	if (isDying == true && timeLeft < 0 && lifeLeft > 0) {
		lifeLeft--;
		isDying = false;
		isDead = true;
		timeLeft = 1000;
		//set respawn position
		if (stage == 1) {
			x = minX + 10;
			y = maxY - 10;
		}
		else {
			x = (maxX - minX) / 2;
			y = minY + 300;
		}
	}
	if (isDead == true && timeLeft < 0) {
		this->SetState(BILL_STATE_REVIVE);
		isVulnerable = false;
		timeLeft = 2000;
		return;
	}
	if (isVulnerable == false && timeLeft < 0) {
		isVulnerable = true;
	}
}
void CBill::UpdateBorder() {
	if (isDying == true || isDead == true)
		return;
	if (stage == 1) {
		float tempMinX = x - CAM_WIDTH_1 / 2;
		if (tempMinX > minX)
			minX = tempMinX;
	}
	else {
		float tempMinY = y - CAM_HEIGHT_3 / 2;
		if (tempMinY > minY)
			minY = tempMinY;
	}
	CGame::GetInstance()->GetCamera()->Update(x, y);
}
void CBill::Move(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	vx = maxVx;
	if (isOnPlatform == false && isSwimming == false && isDead == false)
		vy += BILL_GRAVITY * dt;
	isOnPlatform = false;
	CCollision::GetInstance()->Process(this, coObjects, dt);
	isDropping = false;
}
void CBill::BulletControl(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (bulletMtime > 0)
		bulletMtime -= dt;
	else
		bulletMtime = 0;
	UpdateBullet(dt, coObjects);
}

void CBill::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects){
	//don't change the order of this function
	if (timeLeft >= 0)
		timeLeft -= dt;
	Die();
	UpdateBorder();
	worldControl();
	BulletControl(dt, coObjects);
	Move(dt, coObjects);
	//DebugOutTitle(L"lifeLeft = %d, x = %f, y = %f", lifeLeft, x, y);
	//DebugOutTitle(L"vy = %f, isOnplatform = %d", vy, isOnPlatform);
}
void CBill::Render(){
	CAnimations* animations = CAnimations::GetInstance();
	int ani = -1;
	//render life
	float cx, cy, cw, ch;
	CGame::GetInstance()->GetCamera()->GetCamPos(cx, cy);
	cw = CGame::GetInstance()->GetCamera()->GetCamWidth();
	ch = CGame::GetInstance()->GetCamera()->GetCamHeight();
	for (int i = 0; i < lifeLeft; i++) {
		animations->Get(LIFE_ANI)->Render(cx - cw / 2 + 20 + i * 30, cy + ch / 2 - 20);
	}
	if (isDead == true)
		return;
	if (isSwimming == false) {
		if (vy != 0) {
			if (nx > 0) {
				ani = BILL_ANI_JUMP_RIGHT;
				gunx = x;
				guny = y;
			}
			else {
				ani = BILL_ANI_JUMP_LEFT;
				gunx = x;
				guny = y;
			}
		}
		else {
			if (isLaying) {
				if (nx > 0) {
					ani = BILL_ANI_LAYDOWN_RIGHT;
					gunx = x + 15.0f;
					guny = y - 10.0f;
				}
				else {
					ani = BILL_ANI_LAYDOWN_LEFT;
					gunx = x - 15.0f;
					guny = y - 10.0f;
				}
			}
			else {
				if (vx == 0) {
					if (ny == 1) {
						if (nx > 0) {
							ani = BILL_ANI_SHOOT_UP_RIGHT;
							gunx = x + 4.0f;
							guny = y + 30.0f;
						}
						else {
							ani = BILL_ANI_SHOOT_UP_LEFT;
							gunx = x - 4.0f;
							guny = y + 30.0f;
						}
					}
					if (ny == 0) {
						if (nx > 0) {
							ani = BILL_ANI_NORMAL_RIGHT;
							gunx = x + 10.0f;
							guny = y + 4.5f;
						}
						else {
							ani = BILL_ANI_NORMAL_LEFT;
							gunx = x - 10.0f;
							guny = y + 4.5f;
						}

					}
				}
				else {
					if (vx > 0) {
						if (ny == 0) {
							if (isShooting == true) {
								ani = BILL_ANI_SHOOT_RIGHT;
								gunx = x + 10.0f;
								guny = y + 4.5f;
							}
							else {
								ani = BILL_ANI_RUN_RIGHT;
								gunx = x + 10.0f;
								guny = y + 4.5f;
							}
						}
						if (ny == 1) {
							ani = BILL_ANI_SHOOT_UPRIGHT;
							gunx = x + 10.0f;
							guny = y + 17.0f;
						}
						if (ny == -1) {
							ani = BILL_ANI_SHOOT_DOWNRIGHT;
							gunx = x + 10.0f;
							guny = y - 5.0f;
						}
					}
					else {
						if (ny == 0) {
							if (isShooting == true) {
								ani = BILL_ANI_SHOOT_LEFT;
								gunx = x - 10.0f;
								guny = y + 4.5f;
							}
							else {
								ani = BILL_ANI_RUN_LEFT;
								gunx = x - 10.0f;
								guny = y + 4.5f;
							}
						}
						if (ny == 1) {
							ani = BILL_ANI_SHOOT_UPLEFT;
							gunx = x - 10.0f;
							guny = y + 17.0f;
						}
						if (ny == -1) {
							ani = BILL_ANI_SHOOT_DOWNLEFT;
							gunx = x - 10.0f;
							guny = y - 5.0f;
						}
					}
				}
			}
		}
	}
	else {
		if (timeLeft >= 0) {
			ani = BILL_ANI_SWIMMING_BEGIN;
			gunx = x;
			guny = y;
		}
		else {
			if (isDiving == true) {
				ani = BILL_ANI_DIVING;
				gunx = x;
				guny = y;
			}
			else {
				if (isShooting == true) {
					if (ny == 1) {
						if (vx == 0) {
							if (nx > 0) {
								ani = BILL_ANI_SWIMMING_SHOOT_UP_RIGHT;
								gunx = x;
								guny = y;
							}
							else {
								ani = BILL_ANI_SWIMMING_SHOOT_UP_LEFT;
								gunx = x;
								guny = y;
							}
						}
						if (vx > 0) {
							ani = BILL_ANI_SWIMMING_SHOOT_UPRIGHT;
							gunx = x;
							guny = y;
						}
						if (vx < 0) {
							ani = BILL_ANI_SWIMMING_SHOOT_UPLEFT;
							gunx = x;
							guny = y;
						}
					}
					else {
						if (nx > 0) {
							ani = BILL_ANI_SWIMMING_SHOOT_RIGHT;
							gunx = x;
							guny = y;
						}
						else {
							ani = BILL_ANI_SWIMMING_SHOOT_LEFT;
							gunx = x;
							guny = y;
						}
					}
				}
				else {
					if (nx > 0) {
						ani = BILL_ANI_SWIMMING_RIGHT;
						gunx = x;
						guny = y;
					}
					else {
						ani = BILL_ANI_SWIMMING_LEFT;
						gunx = x;
						guny = y;
					}
				}
			}
		}
	}
	if (isDying == true) {
		if (state == BILL_STATE_DYING_LEFT) {
			ani = BILL_ANI_DYING_LEFT;
		}
		else {
			ani = BILL_ANI_DYING_RIGHT;
		}
	}
	if (ani == -1) ani = BILL_ANI_NORMAL_RIGHT;

	float d = 0;
	if (ny == 1 && vx == 0 && isSwimming == false)
		d = BILL_UP_HEIGHT_ADJUST;
	if (ani == BILL_ANI_DIVING)
		d = BILL_DIVE_HEIGHT_ADJUST;
	if (isVulnerable == false) {
		if (a == false) {
			a = true;
		}
		else {
			animations->Get(ani)->Render(x, y + d);
			a = false;
		}
	}
	else {
		animations->Get(ani)->Render(x, y + d);
	}
	RenderBullet();
}
void CBill::SetState(int state) {
	switch (state) {
	case BILL_STATE_RUN_RIGHT:
		maxVx = BILL_RUN_SPEED;
		nx = 1;
		if (isSwimming == false && isLaying == true) {
			isLaying = false;
			y -= BILL_LAY_HEIGHT_ADJUST;	//support change bbox
		}
		break;
	case BILL_STATE_RUN_LEFT:
		maxVx = -BILL_RUN_SPEED;
		nx = -1;
		if (isSwimming == false && isLaying == true) {
			isLaying = false;
			y -= BILL_LAY_HEIGHT_ADJUST;	//support change bbox
		}
		break;
	case BILL_STATE_JUMP:
		if (vy != 0)
			break;
		if (isSwimming == false) {
			if (ny == -1 && disableDrop == false) {
				if (vx != 0)
					break;
				isJumping = true;
				isDropping = true;
				isLaying = false;
			}
			else {
				vy = BILL_JUMP_SPEED_Y;
				isJumping = true;		//support change bbox
			}
			isOnPlatform = false;
		}
		break;
	case BILL_STATE_DOWN:
		ny = -1;
		if (vy == 0) {
			if (isSwimming == true) {
				isDiving = true;
			}
			else {
				if (isLaying == false) {
					y += BILL_LAY_HEIGHT_ADJUST;
				}
				isLaying = true;
			}
		}
		break;
	case BILL_STATE_DOWN_RELEASE:
		ny = 0;
		if (isSwimming == true) {
			isDiving = false;
		}
		else {
			if (isLaying == true) {
				y -= BILL_LAY_HEIGHT_ADJUST;
				isLaying = false;
			}
		}
		break;
	case BILL_STATE_UP:
		if (isSwimming == false && isLaying == true)
			break;
		ny = 1;
		break;
	case BILL_STATE_UP_RELEASE:
		ny = 0;
		break;
	case BILL_STATE_SHOOT:
		isShooting = true;
		break;
	case BILL_STATE_SHOOT_RELEASE:
		isShooting = false;
		break;
	case BILL_STATE_NORMAL:
		maxVx = 0;
		break;
	case BILL_STATE_INTO_WATER:
		if (isSwimming == false) {
			timeLeft = BILL_TIME_SWIM_BEGIN;
		}
		isSwimming = true;
		isOnPlatform = false;
		isLaying = false;
		isJumping = false;
		vy = 0;
		break;
	case BILL_STATE_OUT_OF_WATER:
		isSwimming = false;
		isDiving = false;
		break;
	case BILL_STATE_ON_LAND:
		isOnPlatform = true;
		isJumping = false;
		isSwimming = false;
		isDiving = false;
		vy = 0;
		break;
	case BILL_STATE_OFF_LAND:
		isOnPlatform = false;
		break;
	case BILL_STATE_DYING_RIGHT:
		isDying = true;
		timeLeft = BILL_TIME_DYING;
		maxVx = -BILL_RUN_SPEED;
		vy = BILL_JUMP_SPEED_Y;
		break;
	case BILL_STATE_DYING_LEFT:
		isDying = true;
		timeLeft = BILL_TIME_DYING;
		maxVx = BILL_RUN_SPEED;
		vy = BILL_JUMP_SPEED_Y;
		break;
	case BILL_STATE_REVIVE:
		isLaying = false;
		isShooting = false;
		isSwimming = false;
		isDiving = false;
		isOnPlatform = false;
		isDropping = false;
		isJumping = true;
		isDying = false;
		isDead = false;
		ny = 0;
		maxVx = 0.0f;
		maxVy = 0.0f; 
		gunx = x;
		guny = y;
		this->stage = stage;
		bulletType = BULLET_ANI_NORMAL;
		waveLeft = BILL_WAVE_BULLET_NORMAL;
		bonusWave = 0;

		bulletMtime = 0;
		timeLeft = 0;
		break;
	}
	CGameObject::SetState(state);
}

void CBill::KeyDown(int KeyCode) {
	if (isDying == true)
		return;
	switch (KeyCode) {
	case DIK_X:
		this->SetState(BILL_STATE_JUMP);
		break;
	case DIK_Z:
		this->SetState(BILL_STATE_SHOOT);
		this->AddBullet(false);
		break;
	case DIK_1:
		this->SetBulletType(BULLET_ANI_NORMAL);
		break;
	case DIK_2:
		this->SetBulletType(BULLET_ANI_FLAME);
		break;
	case DIK_3:
		this->SetBulletType(BULLET_ANI_LASER);
		break;
	case DIK_4:
		this->SetBulletType(BULLET_ANI_SPREAD);
		break;
	case DIK_5:
		this->SetBulletType(BULLET_ANI_MACHINE);
		break;
	case DIK_6:
		bonusWave++;
		waveLeft++;
		break;
	case DIK_R:
		if (isVulnerable == true) {
			isVulnerable = false;
			timeLeft = 100000;
		}
		else {
			isVulnerable = true;
			timeLeft = 0;
		}
		break;
	}
}
void CBill::KeyUp(int KeyCode) {
	if (isDying == true)
		return;
	switch (KeyCode) {
	case DIK_Z:
		this->SetState(BILL_STATE_SHOOT_RELEASE);
		break;
	case DIK_DOWN:
		this->SetState(BILL_STATE_DOWN_RELEASE);
		break;
	case DIK_UP:
		this->SetState(BILL_STATE_UP_RELEASE);
		break;
	case DIK_RIGHT:
		this->SetState(BILL_STATE_NORMAL);
		break;
	case DIK_LEFT:
		this->SetState(BILL_STATE_NORMAL);
		break;
	}
}
void CBill::KeyState(CGame* game) {
	if (isDying == true)
		return;
	BOOLEAN normal = true;
	if (game->IsKeyDown(DIK_Z)) {
		AddBullet(true);
	}
	if (game->IsKeyDown(DIK_DOWN))
	{
		this->SetState(BILL_STATE_DOWN);
		normal = false;
	}
	if (game->IsKeyDown(DIK_UP)) {
		this->SetState(BILL_STATE_UP);
		normal = false;
	}
	if (game->IsKeyDown(DIK_LEFT)){
		this->SetState(BILL_STATE_RUN_LEFT);
		normal = false;
	}
	if (game->IsKeyDown(DIK_RIGHT)){
		this->SetState(BILL_STATE_RUN_RIGHT);
		normal = false;
	}
	if (normal == true)
		this->SetState(BILL_STATE_NORMAL);
}

void CBill::CreateBox(DWORD dt) {
	if (isDying == true) {
		bbox.left = x - BILL_BOX_DIE_WIDTH / 2;
		bbox.top = y + BILL_BOX_DIE_HEIGHT / 2;
		bbox.right = x + BILL_BOX_DIE_WIDTH / 2;
		bbox.bottom = y - BILL_BOX_DIE_HEIGHT / 2;
	}
	else
	if (isSwimming == true) {
		bbox.left = x - BILL_BOX_SWIM_WIDTH / 2;
		bbox.top = y + BILL_BOX_SWIM_HEIGHT / 2;
		bbox.right = x + BILL_BOX_SWIM_WIDTH / 2;
		bbox.bottom = y - BILL_BOX_SWIM_HEIGHT / 2;
	}
	else
	if (isLaying == true) {
		bbox.left = x - BILL_BOX_LAY_WIDTH / 2;
		bbox.top = y + BILL_BOX_LAY_HEIGHT / 2;
		bbox.right = x + BILL_BOX_LAY_WIDTH / 2;
		bbox.bottom = y - BILL_BOX_LAY_HEIGHT / 2;
	}
	else
	if (isJumping == true) {
		bbox.left = x - BILL_BOX_JUMP_WIDTH / 2;
		bbox.top = y + BILL_BOX_JUMP_HEIGHT / 2;
		bbox.right = x + BILL_BOX_JUMP_WIDTH / 2;
		bbox.bottom = y - BILL_BOX_JUMP_HEIGHT / 2;
	}
	else
	{
		bbox.left = x - BILL_BOX_NORMAL_WIDTH / 2;
		bbox.top = y + BILL_BOX_NORMAL_HEIGHT / 2;
		bbox.right = x + BILL_BOX_NORMAL_WIDTH / 2;
		bbox.bottom = y - BILL_BOX_NORMAL_HEIGHT / 2;
	}
	bbox.vpf_x = vx * dt;
	bbox.vpf_y = vy * dt;
}
void CBill::NoCollision(DWORD dt) {
	x += vx * dt;
	y += vy * dt; 
}
void CBill::CollisionWith(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPGRASS>(e->dest_obj)) {
		CollisionWithGrass(e);
	}
	else if (dynamic_cast<LPWATER>(e->dest_obj)) {
		CollisionWithWater(e);
	}
	else if (dynamic_cast<LPBRIDGEPART>(e->dest_obj)) {
		CollisionWithBridgePart(e);
	}
	else if (dynamic_cast<LPBRIDGE>(e->dest_obj)) {
		CollisionWithBridge(e);
	}
	else if (dynamic_cast<LPAIRCRAFT>(e->dest_obj)) {
		CollisionWithAircraft(e);
	}
	else if (dynamic_cast<LPFALCON>(e->dest_obj)) {
		CollisionWithFalcon(e);
	}
	else if (dynamic_cast<LPBOSS1SHIELD>(e->dest_obj)) {
		CollisionWithBoss1Shield(e);
	}
	else if (dynamic_cast<LPBOSS3MOUTH>(e->dest_obj)) {
		CollisionWithBoss3Mouth(e);
	}
	if (dynamic_cast<LPROCKFLY>(e->dest_obj)) {
		CollisionWithRockFly(e);
	}
}
	else if (dynamic_cast<LPSOLDIER>(e->dest_obj)) {
		CollisionWithSoldier(e);
	}
}
//collision with terrain object
void CBill::CollisionWithGrass(LPCOLLISIONEVENT e) {
	if (e->normal_x != 0) {
		if (isSwimming == true) {
			float a = BILL_WATER_TO_LAND_POSITION_ADJUST;
			if (e->dest_obj->GetBox().bottom - this->bbox.top <= a) {
				y += BILL_WATER_TO_LAND_POSITION_ADJUST;
				SetState(BILL_STATE_ON_LAND);
				y += BILL_SWIM_NORMAL_POSITION_ADJUST;
			}	
		}
		this->x += bbox.vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			if (isDropping == false) {
				//support change bbox
				if (isJumping == true) {
					isJumping = false;
					y += BILL_JUMP_NORMAL_POSITION_ADJUST;
				}
				this->y += e->time * bbox.vpf_y;
				SetState(BILL_STATE_ON_LAND);
			}
			else {
				this->y += bbox.vpf_y;
			}
		}
		else {
			this->y += bbox.vpf_y;
		}
	}
}
void CBill::CollisionWithWater(LPCOLLISIONEVENT e) {
	if (e->normal_x != 0) {
		this->x += bbox.vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			if (isJumping == true) {
				y -= BILL_JUMP_SWIM_POSITION_ADJUST;
			}
			else {
				y -= BILL_NORMAL_SWIM_POSITION_ADJUST;
			}
			SetState(BILL_STATE_INTO_WATER);
			this->y += e->time * bbox.vpf_y;
		}
		else {
			this->y += bbox.vpf_y;
		}
	}
}
void CBill::CollisionWithBridgePart(LPCOLLISIONEVENT e) {
	if (e->normal_x != 0) {
		this->x += bbox.vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			if (e->dest_obj->IsExploded() == true) {
				this->y += bbox.vpf_y;
				return;
			}
			if (isDropping == false) {
				//support change bbox
				if (isJumping == true) {
					isJumping = false;
					y += BILL_JUMP_NORMAL_POSITION_ADJUST;
				}
				this->y += e->time * bbox.vpf_y;
				SetState(BILL_STATE_ON_LAND);
			}
			else {
				this->y += bbox.vpf_y;
			}
		}
		else {
			this->y += bbox.vpf_y;
		}
	}
}
void CBill::CollisionWithBridge(LPCOLLISIONEVENT e) {
	if (e->normal_y != 0) {
		((LPBRIDGE)e->dest_obj)->Explode();
	}
}
void CBill::CollisionWithRockFly(LPCOLLISIONEVENT e) {
	if (e->normal_x != 0) {
		this->x += bbox.vpf_x;
	}
	else if (e->normal_y != 0) {
		if (e->normal_y > 0) {
			if (isDropping == false) {
				//support change bbox
				if (isJumping == true) {
					isJumping = false;
					y += BILL_JUMP_NORMAL_POSITION_ADJUST;
				}
				this->y += e->time * bbox.vpf_y;
				SetState(BILL_STATE_ON_LAND);
			}
			else {
				this->y += bbox.vpf_y;
			}
		}
		else {
			this->y += bbox.vpf_y;
		}
	}
}
void CBill::CollisionWithBoss1Shield(LPCOLLISIONEVENT e) {
	if (e->normal_x != 0) {
		this->x += e->time * bbox.vpf_x;
	}
	else if (e->normal_y != 0) {
		this->y += e->time * bbox.vpf_y;
	}
}
void CBill::CollisionWithBoss3Mouth(LPCOLLISIONEVENT e) {
	if ((LPBOSS3MOUTH(e->dest_obj))->IsDead() == true) {
		gameControl = credit;
	}
}
//collision with enemy object
void CBill::CollisionWithAircraft(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPAIRCRAFT>(e->dest_obj)->IsCollectible() == false)
		return;
	switch (dynamic_cast<LPAIRCRAFT>(e->dest_obj)->getAmmoType()) {
	case AIRCRAFT_ANI_fAMMO:
		this->SetBulletType(BULLET_ANI_FLAME);
		break;
	case AIRCRAFT_ANI_lAMMO:
		this->SetBulletType(BULLET_ANI_LASER);
		break;
	case AIRCRAFT_ANI_mAMMO:
		this->SetBulletType(BULLET_ANI_MACHINE);
		break;
	case AIRCRAFT_ANI_sAMMO:
		this->SetBulletType(BULLET_ANI_SPREAD);
		break;
	case AIRCRAFT_ANI_rAMMO:
		bonusWave++;
		waveLeft++;
		break;
	case AIRCRAFT_ANI_bAMMO:
		isVulnerable = false;
		timeLeft = 15000;
	}
	e->dest_obj->Delete();
}
void CBill::CollisionWithFalcon(LPCOLLISIONEVENT e) {
	if (dynamic_cast<LPFALCON>(e->dest_obj)->IsCollectible() == false)
		return;
	switch (dynamic_cast<LPFALCON>(e->dest_obj)->getAmmoType()) {
	case FALCON_fAMMO:
		this->SetBulletType(BULLET_ANI_FLAME);
		break;
	case FALCON_lAMMO:
		this->SetBulletType(BULLET_ANI_LASER);
		break;
	case FALCON_mAMMO:
		this->SetBulletType(BULLET_ANI_MACHINE);
		break;
	case FALCON_sAMMO:
		this->SetBulletType(BULLET_ANI_SPREAD);
		break;
	case FALCON_rAMMO:
		bonusWave++;
		waveLeft++;
		break;
	}
	e->dest_obj->Delete();
}
void CBill::CollisionWithSoldier(LPCOLLISIONEVENT e) {
	if (isDying == false && timeLeft < 0 && lifeLeft > 0) {
		lifeLeft--;
		isDying = true;
		isDead = true;
		//timeLeft = 1000;
		//set respawn position
		if (stage == 1) {
			x = minX + 10;
			y = maxY - 10;
		}
		else {
			x = (maxX - minX) / 2;
			y = minY + 300;
		}
	}
	LPSOLDIER(e->dest_obj)->SetState(SOLDIER_STATE_EXPLODE);
}

int CBill::CalculateAngle() {
	if (vx > 0) {
		if (ny == 1)
			return 45;
		if (ny == -1)
			return 315;
		if (ny == 0)
			return 0;
	}
	if (vx < 0) {
		if (ny == 1)
			return 135;
		if (ny == -1)
			return 225;
		if (ny == 0)
			return 180;
	}
	if (vx == 0) {
		if (ny == 1)
			return 90;
		if (ny == 0) {
			if (nx == 1)
				return 0;
			else
				return 180;
		}
		if (ny == -1) {
			if (vy != 0) {
				return 270;
			}
			else {
				if (nx == 1)
					return 0;
				else
					return 180;
			}
		}
	}
}
void CBill::AddBullet(BOOLEAN KeyState) {
	if (isDiving == true)
		return;
	if (KeyState == true) {
		if (waveLeft > 0 && bulletType == BULLET_ANI_MACHINE && bulletMtime == 0) {
			waveContainer.push_back(ShootMachineBullet(CalculateAngle()));
			waveLeft--;
			bulletMtime = BULLET_M_TIME;
		}
	}
	else {
		if (waveLeft > 0) {
			int fired = false;
			switch (bulletType) {
			case BULLET_ANI_SPREAD:
				waveContainer.push_back(ShootSpreadBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_LASER:
				waveContainer.push_back(ShootLaserBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_FLAME:
				waveContainer.push_back(ShootFlameBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_NORMAL:
				waveContainer.push_back(ShootNormalBullet(CalculateAngle()));
				fired = true;
				break;
			case BULLET_ANI_MACHINE:
				if (bulletMtime == 0) {
					waveContainer.push_back(ShootMachineBullet(CalculateAngle()));
					fired = true;
					bulletMtime = BULLET_M_TIME;
				}
				break;
			}
			if (fired == true)
				waveLeft--;
		}
		else {
			if (bulletType == BULLET_ANI_LASER) {
				waveContainer.clear();
				waveContainer.push_back(ShootLaserBullet(CalculateAngle()));
			}
		}
	}
}

vector<LPBULLET> CBill::ShootSpreadBullet(int angle) {
	LPBULLETS bulletS;
	vector<LPBULLET> temp;
	bulletS = new CBulletS(gunx, guny, angle, true);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle - 15, true);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle + 15, true);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle - 30, true);
	temp.push_back(bulletS);
	bulletS = new CBulletS(gunx, guny, angle + 30, true);
	temp.push_back(bulletS);
	return temp;
}
vector<LPBULLET> CBill::ShootLaserBullet(int angle) {
	LPBULLETL bulletL;
	vector<LPBULLET> temp;
	bulletL = new CBulletL(gunx, guny, angle, 1, true);
	temp.push_back(bulletL);
	bulletL = new CBulletL(gunx, guny, angle, 2, true);
	temp.push_back(bulletL);
	bulletL = new CBulletL(gunx, guny, angle, 3, true);
	temp.push_back(bulletL);
	bulletL = new CBulletL(gunx, guny, angle, 4, true);
	temp.push_back(bulletL);
	return temp;
}
vector<LPBULLET> CBill::ShootFlameBullet(int angle) {
	LPBULLETF bulletF;
	vector<LPBULLET> temp;
	bulletF = new CBulletF(gunx, guny, angle, true);
	temp.push_back(bulletF);
	return temp;
}
vector<LPBULLET> CBill::ShootNormalBullet(int angle) {
	LPBULLETN bulletN = new CBulletN(gunx, guny, angle, true);
	vector<LPBULLET> temp;
	temp.push_back(bulletN);
	return temp;
}
vector<LPBULLET> CBill::ShootMachineBullet(int angle) {
	LPBULLETM bulletM = new CBulletM(gunx, guny, angle, true);
	vector <LPBULLET> temp;
	temp.push_back(bulletM);
	return temp;
}

void CBill::SetBulletType(int type) {
	switch (type) {
	case BULLET_ANI_NORMAL:
		waveLeft = BILL_WAVE_BULLET_NORMAL;
		break;
	case BULLET_ANI_LASER:
		waveLeft = BILL_WAVE_BULLET_LASER;
		break;
	case BULLET_ANI_FLAME:
		waveLeft = BILL_WAVE_BULLET_FLAME;
		break;
	case BULLET_ANI_SPREAD:
		waveLeft = BILL_WAVE_BULLET_SPREAD;
		break;
	case BULLET_ANI_MACHINE:
		waveLeft = BILL_WAVE_BULLET_MACHINE;
		break;
	}
	waveLeft += bonusWave;
	waveLeft -= waveContainer.size();
	this->bulletType = type;
}
void CBill::UpdateBullet(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	for (int i = 0; i < waveContainer.size(); i++) {
		if (waveContainer[i].size() > 0) {
			for (int j = 0; j < waveContainer[i].size(); j++) {
				if (waveContainer[i][j]->outOfScreen() || waveContainer[i][j]->IsDeleted()) {
					delete waveContainer[i][j];
					waveContainer[i].erase(waveContainer[i].begin() + j);
				}
				else
					waveContainer[i][j]->Update(dt, coObjects);
			}
		}
		if (waveContainer[i].size() == 0) {
			waveContainer.erase(waveContainer.begin() + i);
			waveLeft++;
		}
	}
}
void CBill::RenderBullet() {
	for (int i = 0; i < waveContainer.size(); i++) {
		for (int j = 0; j < waveContainer[i].size(); j++) {
			waveContainer[i][j]->Render();
		}
	}
}
