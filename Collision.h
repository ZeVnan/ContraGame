#pragma once
#include <Windows.h>
#include <vector>
#include <algorithm>

using namespace std;

struct box {
	float left = 0;
	float top = 0;
	float right = 0;
	float bottom = 0;
	float vpf_x = 0;
	float vpf_y = 0;
};
class CGameObject;
typedef CGameObject* LPGAMEOBJECT;

struct CollisionEvent;
typedef CollisionEvent* LPCOLLISIONEVENT;

struct CollisionEvent {
	LPGAMEOBJECT src_obj;
	LPGAMEOBJECT dest_obj;

	float time;
	float normal_x;
	float normal_y;

	float vpf_x;
	float vpf_y;
	bool isDeleted;

	CollisionEvent(float time, float normal_x, float normal_y, float vpf_x = 0, float vpf_y = 0,
		LPGAMEOBJECT src_obj = NULL, LPGAMEOBJECT dest_obj = NULL) {
		this->time = time;
		this->normal_x = normal_x;
		this->normal_y = normal_y;
		this->vpf_x = vpf_x;
		this->vpf_y = vpf_y;
		this->src_obj = src_obj;
		this->dest_obj = dest_obj;
		this->isDeleted = false;
	}
	bool happened() {
		return time >= 0.0f && time <= 1.0f;
	}
	static bool compare(const LPCOLLISIONEVENT& a, LPCOLLISIONEVENT& b) {
		return a->time < b->time;
	}
};
class CCollision
{
	static CCollision* __instance;
public:
	static CCollision* GetInstance();
	LPCOLLISIONEVENT SweptAABB(LPGAMEOBJECT src_obj, LPGAMEOBJECT dest_obj, DWORD dt);
	vector<LPCOLLISIONEVENT> Scan(LPGAMEOBJECT src_obj, vector<LPGAMEOBJECT>* dest_obj, DWORD dt);
	void Filter(
		LPGAMEOBJECT objSrc,
		vector<LPCOLLISIONEVENT>& coEvents,
		LPCOLLISIONEVENT& colX,
		LPCOLLISIONEVENT& colY,
		int filterBlock,
		int filterX,
		int filterY);
	void Process(LPGAMEOBJECT src_obj, vector<LPGAMEOBJECT>* coObjects, DWORD dt);
};

