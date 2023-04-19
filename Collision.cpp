#include "Collision.h"
#include "GameObject.h"

#include "debug.h"

CCollision* CCollision::__instance = NULL;

CCollision* CCollision::GetInstance()
{
	if (__instance == NULL) __instance = new CCollision();
	return __instance;
}
LPCOLLISIONEVENT CCollision::SweptAABB(LPGAMEOBJECT src_obj, LPGAMEOBJECT dest_obj, DWORD dt) {
	src_obj->CreateBox(dt);
	dest_obj->CreateBox(dt);
	box src_box = src_obj->GetBox();
	box dest_box = dest_obj->GetBox();
	float vpf_x = src_box.vpf_x - dest_box.vpf_x;
	float vpf_y = src_box.vpf_y - dest_box.vpf_y;

	float dx_entry, dx_exit, tx_entry, tx_exit;
	float dy_entry, dy_exit, ty_entry, ty_exit;

	float t_entry;
	float t_exit;

	float time = -1.0f;
	float normal_x = 0.0f;
	float normal_y = 0.0f;
	//broad phasing
	float bl = vpf_x > 0 ? src_box.left : src_box.left + vpf_x;
	float bt = vpf_y > 0 ? src_box.top : src_box.top + vpf_y;
	float br = vpf_x > 0 ? src_box.right + vpf_x : src_box.right;
	float bb = vpf_y > 0 ? src_box.bottom + vpf_y : src_box.bottom;

	if (br < dest_box.left || bl > dest_box.right || bb < dest_box.top || bt > dest_box.bottom) return NULL;
	//end broad phasing 
	if (vpf_x == 0 && vpf_y == 0) return NULL;

	if (vpf_x > 0) {
		dx_entry = dest_box.left - src_box.right;
		dx_exit = dest_box.right - src_box.left;
	}
	if (vpf_x < 0) {
		dx_entry = dest_box.right - src_box.left;
		dx_exit = dest_box.left - src_box.right;
	}

	if (vpf_y > 0) {
		dy_entry = dest_box.top - src_box.bottom;
		dy_exit = dest_box.bottom - src_box.top;
	}
	if (vpf_y < 0) {
		dy_entry = dest_box.bottom - src_box.top;
		dy_exit = dest_box.top - src_box.bottom;
	}

	if (vpf_x == 0) {
		tx_entry = -std::numeric_limits<float>::infinity();
		tx_exit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tx_entry = dx_entry / vpf_x;
		tx_exit = dx_exit / vpf_x;
	}

	if (vpf_y == 0) {
		ty_entry = -std::numeric_limits<float>::infinity();
		ty_exit = std::numeric_limits<float>::infinity();
	}
	else
	{
		ty_entry = dy_entry / vpf_y;
		ty_exit = dy_exit / vpf_y;
	}

	if ((tx_entry < 0.0f && ty_entry < 0.0f) || tx_entry > 1.0f || ty_entry > 1.0f) return NULL;

	t_entry = max(tx_entry, ty_entry);
	t_exit = min(tx_exit, ty_exit);

	if (t_entry > t_exit) return NULL;

	time = t_entry;


	if (tx_entry > ty_entry)
	{
		normal_y = 0.0f;
		vpf_x > 0 ? normal_x = -1.0f : normal_x = 1.0f;
	}
	else
	{
		normal_x = 0.0f;
		vpf_y > 0 ? normal_y = -1.0f : normal_y = 1.0f;
	}

	return new CollisionEvent(time, normal_x, normal_y, vpf_x, vpf_x, src_obj, dest_obj);
}
vector<LPCOLLISIONEVENT> CCollision::Scan(LPGAMEOBJECT src_obj, vector<LPGAMEOBJECT>* dest_obj, DWORD dt) {
	vector <LPCOLLISIONEVENT> temp;
	for (UINT i = 0; i < dest_obj->size(); i++) {
		LPCOLLISIONEVENT e = SweptAABB(src_obj, dest_obj->at(i), dt);
		if (e == NULL) {
			delete(e);
			continue;
		}
		else 
			temp.push_back(e);
	}
	return temp;
}
void CCollision::Filter(LPGAMEOBJECT objSrc,
	vector<LPCOLLISIONEVENT>& coEvents,
	LPCOLLISIONEVENT& colX,
	LPCOLLISIONEVENT& colY,
	int filterBlock = 1,		
	int filterX = 1,			
	int filterY = 1)
{
	float min_tx = 1.0f;
	float min_ty = 1.0f;
	int min_ix = -1;
	int min_iy = -1;
	for (UINT i = 0; i < coEvents.size(); i++) {
		if (coEvents[i]->isDeleted) continue;
		if (coEvents[i]->dest_obj->IsDeleted()) continue;
		if (coEvents[i]->dest_obj->isBlocking() == false) continue;

		if (coEvents[i]->time < min_tx && coEvents[i]->normal_x != 0) {
			min_tx = coEvents[i]->time;
			min_ix = i;
		}
		if (coEvents[i]->time < min_ty && coEvents[i]->normal_y != 0) {
			min_ty = coEvents[i]->time;
			min_iy = i;
		}
	}
	if (min_ix >= 0) colX = coEvents[min_ix];
	if (min_iy >= 0) colY = coEvents[min_iy];
}
void CCollision::Process(LPGAMEOBJECT src_obj, vector<LPGAMEOBJECT>* coObjects, DWORD dt) {
	vector<LPCOLLISIONEVENT> coEvents;
	LPCOLLISIONEVENT colX = NULL;
	LPCOLLISIONEVENT colY = NULL;

	coEvents.clear();
	if (src_obj->isCollidable())
		coEvents = Scan(src_obj, coObjects, dt);
	if (coEvents.size() == 0) {
		src_obj->NoCollision(dt);
	}
	else {
		Filter(src_obj, coEvents, colX, colY);
		float x, y;
		src_obj->GetPosition(x, y);
		if (colX != NULL) {
			x += colX->time * src_obj->GetBox().vpf_x;
			src_obj->CollisionWith(colX);
		}
		else {
			x += src_obj->GetBox().vpf_x;
		}
		if (colY != NULL) {
			y += colY->time * src_obj->GetBox().vpf_y;
			src_obj->CollisionWith(colY);
		}
		else {
			y += src_obj->GetBox().vpf_y;
		}
		src_obj->SetPosition(x, y);
	}
	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT e = coEvents[i];
		if (e->isDeleted) continue;
		if (e->dest_obj->isBlocking()) continue;

		src_obj->CollisionWith(e);
	}


	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}