#pragma once

#include "GameObject.h"
#include "CWorld.h"
#include "Camera.h"
#include <vector>


class WorldPart : public CWorld
{
private:
    float height;
    float width;
    float x;
    float y;
    vector<WorldPart> subParts;
public:
    WorldPart();
    WorldPart(Cworld world);
    WorldPart(float h, float w, float x, float y);
    void CheckSplit(CWorld& world);
    void HorizontalSplit(CWorld& world);
    void VerticalSplit(CWorld& world);
};