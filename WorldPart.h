#pragma once

#include "GameObject.h"
#include "World.h"
#include "Camera.h"
#include <vector>


class WorldPart
{
private:
    float height;
    float width;
    float x;
    float y;
    vector<WorldPart> subParts;
    vector<LPGAMEOBJECT> gameObj;
public:
    WorldPart();
    WorldPart(float h, float w, float x, float y);

    void CheckSplit(CWorld& world);
    void HorizontalSplit(CWorld& world);
    void VerticalSplit(CWorld& world);
    BOOL checkObj(LPGAMEOBJECT Obj);
};