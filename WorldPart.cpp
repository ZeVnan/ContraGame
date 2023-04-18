#include "WorldPart.h"

WorldPart::WorldPart()
{

}

WorldPart::WorldPart(float h, float w, float x, float y)
{
	this->height = h;
	this->width = w;
	this->x = x;
	this->y = y;
}


BOOL WorldPart::checkObj(LPGAMEOBJECT Obj)
{
	float x, y;
	Obj->GetPosition(x, y);
	if (x <= this->x && x >= this->x + this->width) {
		return false;
	}
	if (y <= this->y && y >= this->y + this->height) {
		return false;
	}
	return true;
}


void WorldPart::VerticalSplit(CWorld& world)
{
	
	if (width > CAM_WIDTH && gameObj.size() > 0)
	{
		float subHeight = height;
		float subWidth = width / 2;

		WorldPart leftSubPart{ subHeight, subWidth, x, y };
		WorldPart rightSubPart{ subHeight, subWidth, x + subWidth, y };

		for (int i = 0; i < this->gameObj.size(); i++)
		{
			if (leftSubPart.checkObj(gameObj[i]) && rightSubPart.checkObj(gameObj[i]))
			{
				leftSubPart.gameObj.push_back(gameObj[i]);
			}
			else if (leftSubPart.checkObj(gameObj[i]))
			{
				leftSubPart.gameObj.push_back(gameObj[i]);
			}
			else if (rightSubPart.checkObj(gameObj[i]))
			{
				rightSubPart.gameObj.push_back(gameObj[i]);
			}
		}

		// Add the new sub-parts to the end of the subParts vector
		subParts.push_back(leftSubPart);
		subParts.push_back(rightSubPart);

		// Remove the old part from the beginning of the vector
		subParts.erase(subParts.begin());

		leftSubPart.VerticalSplit(world);
		rightSubPart.VerticalSplit(world);

	}
	else
	{
		world.getWPList().push_back(this);
		//world.WPlist.push_back(this);
	}
}

void WorldPart::HorizontalSplit(CWorld& world)
{
	if (height > CAM_HEIGHT && gameObj.size() > 0)
	{
		float subHeight = height / 2;
		float subWidth = width;

		WorldPart downSubPart{ subHeight, subWidth, x, y };
		WorldPart upSubPart{ subHeight, subWidth, x, y + subHeight };

		for (int i = 0; i < this->gameObj.size(); i++)
		{
			if (downSubPart.checkObj(gameObj[i]) && upSubPart.checkObj(gameObj[i]))
			{
				downSubPart.gameObj.push_back(gameObj[i]);
			}
			else if (downSubPart.checkObj(gameObj[i]))
			{
				downSubPart.gameObj.push_back(gameObj[i]);
			}
			else if (upSubPart.checkObj(gameObj[i]))
			{
				upSubPart.gameObj.push_back(gameObj[i]);
			}
		}

		// Add the new sub-parts to the end of the subParts vector
		subParts.push_back(downSubPart);
		subParts.push_back(upSubPart);

		// Remove the old part from the beginning of the vector
		subParts.erase(subParts.begin());

		downSubPart.VerticalSplit(world);
		upSubPart.VerticalSplit(world);
	}
	else
	{
		world.getWPList().push_back(this);
		//world.WPlist.push_back(this);
	}
}

void WorldPart::CheckSplit(CWorld& world)
{
	if (world.getHeight() < world.getWidth())
	{
		VerticalSplit(world);
	}
	else
	{
		HorizontalSplit(world);
	}
}