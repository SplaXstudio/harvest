#include "uncollisionObj.h"

#include <QPointF>
#include <QList>

uncollisionObj::uncollisionObj(double _x = 0, double _y = 0,
                 double _z = 0, QPointF size = QPointF(0, 0)) : width(size.x()), height(size.y())
{
    coor.x = _x;
    coor.y = _y;
    coor.z = _z;
}

uncollisionObj::~uncollisionObj()
{
    return;
}

inline double uncollisionObj::X()
{
    return coor.x;
}
inline double uncollisionObj::Y()
{
    return coor.y;
}
inline double uncollisionObj::Z()
{
    return coor.z;
}
inline double uncollisionObj::Width()
{
    return width;
}
inline double uncollisionObj::Height()
{
    return height;
}

inline void uncollisionObj::setX(double shit)
{
    coor.x = shit;
}
inline void uncollisionObj::setY(double shit)
{
    coor.y = shit;
}
inline void uncollisionObj::setZ(double shit)
{
    coor.z = shit;
}
inline void uncollisionObj::setWidth(double shit)
{
    width = shit;
}
inline void uncollisionObj::setHeight(double shit)
{
    height = shit;
}

inline QPointF uncollisionObj::size()
{
    return QPointF(width, height);
}

inline void uncollisionObj::trigger()
{
    return;
}

inline void uncollisionObj::setID(int _id)
{
    id = _id;
}

inline int uncollisionObj::ID()
{
    return id;
}

