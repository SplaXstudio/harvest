#include "collisionObj.h"




collisionObj::collisionObj(double _x = 0, double _y = 0,
                 double _z = 0, QPointF size = QPointF(0, 0)) : width(size.x()), height(size.y())
{
    coor.X = _x;
    coor.Y = _y;
    coor.Z = _z;
}

collisionObj::~collisionObj()
{
	delete this;
    return;
}

