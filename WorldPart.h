#pragma once

#include "GameObject.h"
#include "World.h"
#include "Camera.h"
#include <vector>


class CWorldPart
{
private:
    float height;
    float width;
    float x;
    float y;
    CWorldPart* firstPart;  //left, bottom
    CWorldPart* secondPart;     //right, top
    vector<LPGAMEOBJECT> objects;
public:
    CWorldPart();
    CWorldPart(LPWORLD world);
    CWorldPart(float width, float height, float x, float y);

    void Split(LPWORLD world);
    void HorizontalSplit(LPWORLD world);
    void VerticalSplit(LPWORLD world);
    BOOL checkObj(LPGAMEOBJECT Obj);
};
typedef CWorldPart* LPWORLDPART;