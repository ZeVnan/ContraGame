#include "World.h"
#include "WorldPart.h"
#include "Bill.h"


extern LPBILL bill;
CWorld::CWorld() {
	width = 0;
	height = 0;
	stage = 0;
}

float CWorld::getHeight() { return this->height; }
float CWorld::getWidth() { return this->width; }

CWorld::CWorld(float width, float height, int stage) {
	this->width = width;
	this->height = height;
	this->stage = stage;
}

map<string, string> CWorld::getObjectProperties(xml_node node)
{
	map<string, string> properties;

	// general
	properties["X"] = node.attribute("X").as_string();
	properties["Y"] = node.attribute("Y").as_string();
	properties["Width"] = node.attribute("Width").as_string();
	properties["Height"] = node.attribute("Height").as_string();

	// parameters
	xml_node params = node.child("Params");
	for (auto item : params)
	{
		auto key = item.attribute("Key").as_string();
		auto value = item.attribute("Value").as_string();
		properties[key] = value;
	}
	//the code explain everything all at once
	return properties;
}

LPGAMEOBJECT CWorld::spawnSoldier(xml_node node)
{
	auto properties = getObjectProperties(node);
	/*if (properties.size() == 0)
		return nullptr;*/

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto soldier = new CSoldier(x, y);

	return soldier;
}
LPGAMEOBJECT CWorld::spawnRifleman(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto rifleman = new Rifleman(x, y);

	return rifleman;
}
LPGAMEOBJECT CWorld::spawnCannon(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto cannon = new CCannon(x, y);

	return cannon;
}
LPGAMEOBJECT CWorld::spawnAircraft(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);
	
	auto aircraft = new CAircraft(x, y, this->stage);

	return aircraft;
}
LPGAMEOBJECT CWorld::spawnFalcon(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto falcon = new CFalcon(x, y);

	return falcon;
}
LPGAMEOBJECT CWorld::spawnWallTurret(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto wallTurret = new CWallTurret(x, y);

	return wallTurret;
}
LPGAMEOBJECT CWorld::spawnScubaSoldier(xml_node node) {
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto ScubaSoldier = new CScubaSoldier(x, y);

	return ScubaSoldier;
}
LPGAMEOBJECT CWorld::spawnRockFall(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto RockFall = new CRockFall(x, y);

	return RockFall;
}
LPGAMEOBJECT CWorld::spawnRockFly(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto RockFly = new CRockFly(x, y);

	return RockFly;
}
LPGAMEOBJECT CWorld::spawnFire(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto Fire = new CFire(x, y);

	return Fire;
}
LPGAMEOBJECT CWorld::spawnTriggerBox(xml_node node) {
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;
	int _type;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);
	_type = stoi(properties["type"]);

	LPTRIGGERBOX tb = new TriggerBox(x, y, _type);

	return tb;
}
LPGAMEOBJECT CWorld::spawnLand(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y, _width;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);
	_width = stof(properties["Width"]);

	auto land = new CLand(x, y, _width);

	return land;
}
LPGAMEOBJECT CWorld::spawnWater(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y, _width;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);
	_width = stof(properties["Width"]);

	auto water = new CWaters(x, y, _width);

	return water;
}
LPGAMEOBJECT CWorld::spawnBridge(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y, _width;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);
	_width = stof(properties["Width"]);

	auto bridge = new CBridge(x, y, _width);

	return bridge;
}
LPGAMEOBJECT CWorld::spawnBoss1Shield(xml_node node) {
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto boss1shield = new CBoss1Shield(x, y);

	return boss1shield;
}
LPGAMEOBJECT CWorld::spawnBoss1Gun(xml_node node) {
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto boss1gun = new CBoss1Gun(x, y);

	return boss1gun;
}
LPGAMEOBJECT CWorld::spawnBoss3Mouth(xml_node node) {
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto boss3mouth = new CBoss3Mouth(x, y);

	return boss3mouth;
}
LPGAMEOBJECT CWorld::spawnBoss3Arm(xml_node node) {
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y, angle;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);
	angle = stof(properties["angle"]);

	auto boss3arm = new CBoss3Arm(x, y, angle);

	return boss3arm;
}
LPGAMEOBJECT CWorld::spawnGenerator(xml_node node) {
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;
	int type, stage;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);
	type = stoi(properties["type"]);
	stage = stoi(properties["stage"]);

	auto generator = new CObjectGenerator(x, y, type, stage);

	return generator;
}
LPGAMEOBJECT CWorld::getObjectById(xml_node node, eID id)
{
	switch (id)
	{
	case CannonID:
		return spawnCannon(node);
	case SoldierID:
		return spawnSoldier(node);
	case FalconID:
		return spawnFalcon(node);
	case AircraftID:
		return spawnAircraft(node);
	case RiflemanID:
		return spawnRifleman(node);
	case WallTurretID:
		return spawnWallTurret(node);
	case ScubaSoldierID:
		return spawnScubaSoldier(node);
	case RockFallID:
		return spawnRockFall(node);
	case RockFlyID:
		return spawnRockFly(node);
	case FireID:
		return spawnFire(node);
	case TriggerBoxID:
		return spawnTriggerBox(node);
	case LAND:
		return spawnLand(node);
	case WATER:
		return spawnWater(node);
	case BRIDGE:
		return spawnBridge(node);
	case BOSS1SHIELD:
		return spawnBoss1Shield(node);
	case BOSS1GUN:
		return spawnBoss1Gun(node);
	case BOSS3MOUTH:
		return spawnBoss3Mouth(node);
	case BOSS3ARM:
		return spawnBoss3Arm(node);
	case generator:
		return spawnGenerator(node);
	default:
		return nullptr;
		break;
	}
	return nullptr;
}

void CWorld::getObjectsListFromFile(const string path)
{
	pugi::xml_document doc;
	//vector<LPGAMEOBJECT>* listobject = new vector<LPGAMEOBJECT>();
	vector<LPGAMEOBJECT> listobject;
	// Mở file và đọc
	xml_parse_result result = doc.load_file(path.data(), pugi::parse_default | pugi::parse_pi);
	if (result == false)
	{
		this->objectList = listobject;
	}

	xml_node tilemap = doc.child("Tilesmap");
	if (tilemap == NULL)
		this->objectList = listobject;

	xml_node objects = tilemap.child("Objects");
	auto list = objects.children();

	// Lấy id từ file xml. so sánh với eID, tuỳ theo eID nào mà gọi đến ĐÚNG HÀM LOAD cho riêng object đó.
	for (auto item : list)
	{
		int id = item.attribute("Id").as_int();
		eID enumID;
		try {
			enumID = (eID)id;
		}
		catch (exception e) {
			continue;
		}
		LPGAMEOBJECT obj = getObjectById(item, enumID);
		if (obj != NULL) {
			if (dynamic_cast<LPLAND>(obj)) {
				(LPLAND(obj))->PushObjectToList(listobject);
			}
			else if (dynamic_cast<LPWATERS>(obj)) {
				(LPWATERS(obj))->PushObjectToList(listobject);
			}
			else if (dynamic_cast<LPBRIDGE>(obj)) {
				(LPBRIDGE(obj))->PushObjectToList(listobject);
				listobject.push_back(obj);
			}
			else {
				listobject.push_back(obj);
			}
		}
	}
	this->objectList = listobject;
}
void CWorld::ClearWorld() {
	for (int i = 0; i < this->WPList.size(); i++) {
		WPList[i]->ClearWorldPart();
		delete WPList[i];
	}
	WPList.clear();
}
void CWorld::ClearDeletedObjects() {
	for (int i = 0; i < this->WPList.size(); i++) {
		WPList[i]->ClearDeletedObjects();
	}
}
void CWorld::Update(DWORD dt) {
	UpdateObjectContainer();

	vector<LPGAMEOBJECT> tempObjectList;
	for (int i = 0; i < WPList.size(); i++) {
		if (CGame::GetInstance()->GetCamera()->CheckWorldPart(WPList[i])) {
			WPList[i]->GetObjectToTempList(tempObjectList);
		}
	}
	vector<LPGAMEOBJECT> coObjects;
	for (UINT i = 0; i < tempObjectList.size(); i++) {
		coObjects.push_back(tempObjectList[i]);
	}
	for (UINT i = 0; i < tempObjectList.size(); i++) {
		tempObjectList[i]->Update(dt, &coObjects);
	}
}
void CWorld::Render() {
	for (int i = 0; i < WPList.size(); i++) {
		if (CGame::GetInstance()->GetCamera()->CheckWorldPart(WPList[i])) {
			WPList[i]->Render();
		}
	}
	bill->Render();		//just make sure bill will not be obscured by other objects
}
void CWorld::UpdateObjectContainer() {
	vector<LPGAMEOBJECT> temp;
	for (int i = 0; i < WPList.size(); i++) {
		if (CGame::GetInstance()->GetCamera()->CheckWorldPart(WPList[i])) {
			WPList[i]->GetOutOfPartObject(temp);
		}
	}
	for (int j = 0; j < WPList.size(); j++) {
		for (int k = 0; k < temp.size(); k++) {
			if (WPList[j]->checkObj(temp[k])) {
				WPList[j]->TakeNewObject(temp[k]);
				temp.erase(temp.begin() + k);
			}
		}
	}
}
void CWorld::DrawTile() {
	CSprites* sprites = CSprites::GetInstance();
	for (int i = 0; i < WPList.size(); i++) {
		WPList[i]->DrawTile();
	}
}
CWorld::~CWorld() {
	return;
}