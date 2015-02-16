#include "collisionObj.h"




collisionObj::collisionObj(double _x = 0, double _y = 0,
                 double _z = 0, QPointF size = QPointF(0, 0)) : width(size.x()), height(size.y())
{
    coor.X = _x;
    coor.Y = _y;
    coor.Z = _z;
}

collisionObj::collisionObj(collisionObj* that)
{
	coor.X = that->coor.X;
	coor.Y = that->coor.Y;
	coor.Z = that->coor.Z;
	width = that->width;
	height = that->height;

	speed_x = that->speed_x;
	speed_y = that->speed_y;
	speed_z = that->speed_z;

	animation = that->animation;

	ID = that->ID;
	sceneID = that->sceneID;

	tpTo = that->tpTo;

	collisionList = that->collisionList;
}

collisionObj::~collisionObj()
{
	delete this;
    return;
}


bool collisionObj::operator==(collisionObj* obj)
{
	if (sceneID == obj->sceneID)		//´ý¶¨
	{
		return 1;
	}
	return 0;
}

