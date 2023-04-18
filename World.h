#pragma once
#include "Soldier.h"
#include "Falcon.h"
#include "WallTurret.h"
#include "Aircraft.h"
#include "Cannon.h"
#include "Rifleman.h"

#include "define.h"
#include "WorldPart.h"

class CWorld
{
private:
	float width;
	float height;
	vector<LPGAMEOBJECT> objectList;
	vector<WorldPart*> WPList;
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
	//vector<WorldPart*> WPlist;
	
	vector<WorldPart*> getWPList() { return this->WPList; }
	void setWPList(vector<WorldPart*> wp) { this->WPList = wp; }

	LPGAMEOBJECT getObjectById(xml_node node, eID enumID);
	vector<LPGAMEOBJECT>* getObjectsListFromFile(const string path);

	~CWorld();
};

