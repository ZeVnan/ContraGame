#pragma once

#include <Windows.h>
#include <d3dx10.h>
#include <vector>

#include "Game.h"
#include "Camera.h"
#include "Collision.h"

using namespace std;

#define EXPLOSION_1_ANI 20002
#define EXPLOSION_2_ANI 20003

#define TIME_EXPLODE	600
class CGameObject
{
protected:
	float x; 
	float y;

	float vx;
	float vy;

	int nx;	 

	int state;
	box bbox;

	bool isDeleted;
	bool isExploded;
public: 
	void SetPosition(float x, float y) {
		this->x = x;
		this->y = y;
	}
	void GetPosition(float& x, float& y) {
		x = this->x;
		y = this->y;
	}

	void SetSpeed(float vx, float vy) {
		this->vx = vx;
		this->vy = vy;
	}
	void GetSpeed(float& vx, float& vy) {
		vx = this->vx;
		vy = this->vy;
	}

	void SetState(int state) { 
		this->state = state; 
	}
	int GetState() { 
		return this->state; 
	}

	virtual void Delete() {
		isDeleted = true;
	}
	bool IsDeleted() {
		return isDeleted;
	}

	virtual void CreateBox(DWORD dt) {};
	box GetBox() { return this->bbox; }
	void RenderBox();

	CGameObject();
	CGameObject(float x, float y):CGameObject() { this->x = x; this->y = y; }

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL) {};
	virtual void Render() { RenderBox(); };

	virtual bool isCollidable() {
		return true;
	}
	virtual bool isBlocking() {
		return true;
	}
	virtual void NoCollision(DWORD dt) {};
	virtual void CollisionWith(LPCOLLISIONEVENT e) {};

	~CGameObject() {};
};

typedef CGameObject* LPGAMEOBJECT;