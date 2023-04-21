#include "World.h"
#include "WorldPart.h"
#include "Bill.h"

CWorld::CWorld() {}

float CWorld::getHeight() { return this->height; }
float CWorld::getWidth() { return this->width; }

CWorld::CWorld(float height, float width) {
	this->height = height;
	this->width = width;
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

LPGAMEOBJECT CWorld::getSoldier(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto soldier = new CSoldier(x, y);

	return soldier;
}
LPGAMEOBJECT CWorld::getRifleman(xml_node node)
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
LPGAMEOBJECT CWorld::getCannon(xml_node node)
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
LPGAMEOBJECT CWorld::getAircraft(xml_node node)
{
	auto properties = getObjectProperties(node);
	if (properties.size() == 0)
		return nullptr;

	float x, y;

	//stof: String TO Float
	x = stof(properties["X"]);
	y = stof(properties["Y"]);

	auto aircraft = new CAircraft(x, y, AIRCRAFT_ANI_sAMMO);

	return aircraft;
}
LPGAMEOBJECT CWorld::getFalcon(xml_node node)
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
LPGAMEOBJECT CWorld::getWallTurret(xml_node node)
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


LPGAMEOBJECT CWorld::getObjectById(xml_node node, eID id)
{
	switch (id)
	{
	case CannonID:
		return getCannon(node);
	case SoldierID:
		return getSoldier(node);
	case FalconID:
		return getFalcon(node);
	case AircraftID:
		return getAircraft(node);
	case RiflemanID:
		return getRifleman(node);
	case WallTurretID:
		return getWallTurret(node);
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
	// Chỗ này em ciêm copy code nên cũng ko rõ là có thực sự dùng HÀM LOAD gì hay ko nhưng mà nó có push_back để add nên giữ
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
		if (obj != NULL)
			listobject.push_back(obj);
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
	
	for (int i = 0; i < WPList.size(); i++) {
		if (CGame::GetInstance()->GetCamera()->CheckWorldPart(WPList[i])) {
			vector<LPGAMEOBJECT> tempObjectList;
			WPList[i]->GetObjectToTempList(tempObjectList);
			if (i - 1 >= 0)
				WPList[i - 1]->GetObjectToTempList(tempObjectList);
			if (i - 2 >= 0)
				WPList[i - 2]->GetObjectToTempList(tempObjectList);
			if (i + 1 < tempObjectList.size())
				WPList[i + 1]->GetObjectToTempList(tempObjectList);
			if (i + 2 < tempObjectList.size())
				WPList[i + 2]->GetObjectToTempList(tempObjectList);

			vector<LPGAMEOBJECT> coObjects;
			for (UINT i = 0; i < tempObjectList.size(); i++) {
				coObjects.push_back(tempObjectList[i]);
			}
			for (UINT i = 0; i < tempObjectList.size(); i++) {
				tempObjectList[i]->Update(dt, &coObjects);
			}
			break;
		}
	}
}
void CWorld::Render() {
	for (int i = 0; i < WPList.size(); i++) {
		if (CGame::GetInstance()->GetCamera()->CheckWorldPart(WPList[i])) {
			WPList[i]->Render();
			if (i - 1 >= 0) WPList[i - 1]->Render();
			if (i - 2 >= 0) WPList[i - 2]->Render();
			if (i + 1 < WPList.size()) WPList[i + 1]->Render();
			if (i + 2 < WPList.size()) WPList[i + 2]->Render();
			break;
		}
	}
}
void CWorld::UpdateObjectContainer() {
	int cur = 0;
	for (int i = 0; i < WPList.size(); i++) {
		if (CGame::GetInstance()->GetCamera()->CheckWorldPart(WPList[i])) {
			cur = i;
			break;
		}
	}
	for (int i = cur - 2; i <= cur + 2; i++) {
		if (i < 0 || i >= WPList.size()) continue;
		vector<LPGAMEOBJECT> temp = WPList[i]->GetOutOfPartObject();
		for (int j = 0; j < temp.size(); j++) {
			if (i - 1 >= 0) {
				if (WPList[i - 1]->checkObj(temp[j]))
					WPList[i - 1]->TakeNewObject(temp[j]);
			}
			if (i + 1 < WPList.size()) {
				if (WPList[i + 1]->checkObj(temp[j]))
					WPList[i + 1]->TakeNewObject(temp[j]);
			}
		}
	}
}
CWorld::~CWorld() {
	return;
}