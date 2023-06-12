#pragma once
#include "Soldier.h"
#include "Falcon.h"
#include "WallTurret.h"
#include "Aircraft.h"
#include "Cannon.h"
#include "Rifleman.h"
#include "ScubaSoldier.h"
#include "RockFall.h"
#include "RockFly.h"
#include "Land.h"
#include "Waters.h"
#include "Bridge.h"
#include "Boss1Shield.h"
#include "Boss1Gun.h"
#include "Boss3Mouth.h"
#include "Boss3Arm.h"
#include "ObjectGenerator.h"

#include "define.h"
#include "Tile.h"
class CWorldPart;

class CWorld
{
private:
	float width;
	float height;
	int stage;
	vector<LPGAMEOBJECT> objectList;
	vector<LPTILE> tileList;
	vector<CWorldPart*> WPList;
	LPGAMEOBJECT spawnRifleman(xml_node node);
	LPGAMEOBJECT spawnSoldier(xml_node node);
	LPGAMEOBJECT spawnCannon(xml_node node);
	LPGAMEOBJECT spawnWallTurret(xml_node node);
	LPGAMEOBJECT spawnAircraft(xml_node node);
	LPGAMEOBJECT spawnFalcon(xml_node node);
	LPGAMEOBJECT spawnScubaSoldier(xml_node node);
	LPGAMEOBJECT spawnRockFall(xml_node node);
	LPGAMEOBJECT spawnRockFly(xml_node node);
	LPGAMEOBJECT spawnLand(xml_node node);
	LPGAMEOBJECT spawnWater(xml_node node);
	LPGAMEOBJECT spawnBridge(xml_node node);
	LPGAMEOBJECT spawnBoss1Shield(xml_node node);
	LPGAMEOBJECT spawnBoss1Gun(xml_node node);
	LPGAMEOBJECT spawnBoss3Mouth(xml_node node);
	LPGAMEOBJECT spawnBoss3Arm(xml_node node);
	LPGAMEOBJECT spawnGenerator(xml_node node);

	map<string, string> getObjectProperties(xml_node node);
	
public:
	CWorld();
	CWorld(float width, float height, int stage);

	float getWidth();
	float getHeight();
	
	vector<LPGAMEOBJECT>& getObjectList() { return this->objectList; }
	void setObjectList(vector<LPGAMEOBJECT> a) { this->objectList = a; }

	vector<LPTILE>& getTileList() { return this->tileList; }
	void setTileList(vector<LPTILE> a) { this->tileList = a; }
	
	vector<CWorldPart*>& getWPList() { return this->WPList; }
	void setWPList(vector<CWorldPart*> wp) { this->WPList = wp; }

	LPGAMEOBJECT getObjectById(xml_node node, eID enumID);
	void getObjectsListFromFile(const string path);

	void ClearWorld();
	void ClearDeletedObjects();
	void Update(DWORD dt);
	void Render();
	void UpdateObjectContainer();

	void DrawTile();
	~CWorld();
};
typedef CWorld* LPWORLD;

