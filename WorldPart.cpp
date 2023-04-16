﻿#include "WorldPart.h"

WorldPart::WorldPart() :CWorld()
{

}

WorldPart::WorldPart(CWorld world)
{
    this->height = world->height;
    this->width = world->width;
    x = 0;
    y = 0
}

void WorldPart::HorizontalSplit(CWorld& world)
{
    if (height > CAM_HEIGHT && width > CAM_WIDTH) //Cần 1 hàm check điều kiện có obj nào trong subpart đó không?
    {
        float subHeight = height;
        float subWidth = width / 2;

        subParts.push_back(WorldPart{ subHeight, subWidth, x, y });
        subParts.push_back(WorldPart{ subHeight, subWidth, x + subWidth, y });

        for (WorldPart& part : subParts) {
            part.HorizontalSplit(world);
        }
    }
}

void WorldPart::VerticalSplit(CWorld& world)
{
    if (height > CAM_HEIGHT && width > CAM_WIDTH) //Cần 1 hàm check điều kiện có obj nào trong subpart đó không?
    {
        float subHeight = height / 2;
        float subWidth = width;

        subParts.push_back(WorldPart{ subHeight, subWidth, x, y });
        subParts.push_back(WorldPart{ subHeight, subWidth, x, y + subHeight});

        for (WorldPart& part : subParts) {
            part.VerticalSplit(world);
        }
    }
}

void WorldPart::CheckSplit(CWorld& world)
{
    if (world->height >= world->width)
    {
        VerticalSplit(world);
    }
    else
    {
        HorizontalSplit(world);
    }
}