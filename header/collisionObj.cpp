#include "collisionObj.h"




collisionObj::collisionObj(double _x = 0, double _y = 0,
                 double _z = 0, QPointF size = QPointF(0, 0)) : width(size.x()), height(size.y())
{
    coor.x = _x;
    coor.y = _y;
    coor.z = _z;
}

collisionObj::~collisionObj()
{
    return;
}

