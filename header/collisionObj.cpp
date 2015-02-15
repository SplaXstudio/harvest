#include "collisionObj.h"

#include <QPointF>


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

inline double collisionObj::X()
{
    return coor.x;
}
inline double collisionObj::Y()
{
    return coor.y;
}
inline double collisionObj::Z()
{
    return coor.z;
}
inline double collisionObj::Width()
{
    return width;
}
inline double collisionObj::Height()
{
    return height;
}

inline void collisionObj::setX(double shit)
{
    coor.x = shit;
}
inline void collisionObj::setY(double shit)
{
    coor.y = shit;
}
inline void collisionObj::setZ(double shit)
{
    coor.z = shit;
}
inline void collisionObj::setWidth(double shit)
{
    width = shit;
}
inline void collisionObj::setHeight(double shit)
{
    height = shit;
}

inline QPointF collisionObj::size()
{
    return QPointF(width, height);
}

inline void collisionObj::trigger()
{
    return;
}

inline void collisionObj::collisionTrigger(int collisionID)
{
    return;
}

inline void collisionObj::setID(int _id)
{
    sceneid = _id;
}

inline int collisionObj::ID()
{
    return id;
}

inline int collisionObj::sceneID()
{
	return sceneid;
}

inline void collisionObj::setCollisionList(QList<collisionObj*> *colist)
{

}
