#ifndef COLLISIONOBJ_H
#define COLLISIONOBJ_H

#include <QList>
#include <QPointF>

class DAnimation;

class collisionObj
{
private:
    struct coordinate
    {
    double x;
    double y;
    double z;
    }coor;
    double width;
    double height;

private:
    int speed_x;
    int speed_y;
    int speed_z;

    DAnimation *animation;

    int id;
	int sceneid;

    QList<collisionObj*> * collisionList;

public:
    collisionObj(double, double, double, QPointF);
    virtual ~collisionObj();

    inline double X();
    inline double Y();
    inline double Z();

    inline double Width();
    inline double Height();

    inline void setX(double);
    inline void setY(double);
    inline void setZ(double);

    inline void setWidth(double);
    inline void setHeight(double);

    inline QPointF size();

    inline virtual void trigger();
    inline virtual void collisionTrigger(int);

    inline void setID(int);
    inline int ID();
	inline int sceneID();

    inline void setCollisionList(QList<collisionObj*>*);
	
};
#endif // COLLISIONOBJ_H
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

