#pragma once
#include "Soldier.h"
#include "Falcon.h"
#include "WallTurret.h"
#include "Aircraft.h"
#include "Cannon.h"
#include "Rifleman.h"

#include "define.h"
class CWorldPart;

class CWorld
{
private:
	float width;
	float height;
	vector<LPGAMEOBJECT> objectList;
	vector<CWorldPart*> WPList;
	LPGAMEOBJECT getRifleman(xml_node node);
	LPGAMEOBJECT getSoldier(xml_node node);
	LPGAMEOBJECT getCannon(xml_node node);
	LPGAMEOBJECT getWallTurret(xml_node node);
	LPGAMEOBJECT getAircraft(xml_node node);
	LPGAMEOBJECT getFalcon(xml_node node);

	map<string, string> getObjectProperties(xml_node node);
	
public:
	CWorld();
	CWorld(float height, float width);

	float getWidth();
	float getHeight();
	
	vector<LPGAMEOBJECT>& getObjectList() { return this->objectList; }
	void setObjectList(vector<LPGAMEOBJECT> a) { this->objectList = a; }
	
	vector<CWorldPart*>& getWPList() { return this->WPList; }
	void setWPList(vector<CWorldPart*> wp) { this->WPList = wp; }

	LPGAMEOBJECT getObjectById(xml_node node, eID enumID);
	void getObjectsListFromFile(const string path);

	void ClearWorld();
	void ClearDeletedObjects();
	void Update(DWORD dt);
	void Render();
	void UpdateObjectContainer();

	~CWorld();
};
typedef CWorld* LPWORLD;

