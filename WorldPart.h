#pragma once

#include "GameObject.h"
#include "World.h"
#include "Camera.h"
#include <vector>
#include "Tile.h"
#include "ObjectGenerator.h"

class CWorldPart
{
private:
    float height;
    float width;
    float x;
    float y;
    CWorldPart* firstPart;
    CWorldPart* secondPart;
    CWorldPart* thirdPart;
    CWorldPart* fourthPart;
    vector<LPGAMEOBJECT> objects;
    vector<LPTILE> tiles;
public:
    CWorldPart();
    CWorldPart(LPWORLD world);
    CWorldPart(float width, float height, float x, float y);

    void Split(LPWORLD world);
    BOOL checkObj(LPGAMEOBJECT Obj);
    BOOL checkTile(LPTILE Tile);

    float getWidth() { return this->width; }
    float getHeight() { return this->height; }
    float getX() { return this->x; }
    float getY() { return this->y; }

    void ClearWorldPart();
    void ClearDeletedObjects();
    void GetObjectToTempList(vector<LPGAMEOBJECT>& a);
    void Render();
    void DrawTile();

    void GetOutOfPartObject(vector<LPGAMEOBJECT>& a);
    void TakeNewObject(LPGAMEOBJECT obj);
};
typedef CWorldPart* LPWORLDPART;