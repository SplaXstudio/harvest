#ifndef COLLISIONOBJ_H
#define COLLISIONOBJ_H

#include <QList>
#include <QPointF>

#include <qdebug.h>	//unittest

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
	int tpTo;

    QList<collisionObj*> * collisionList;
	
public:
    collisionObj(double, double, double, QPointF);
    virtual ~collisionObj();
	inline int tp(){return tpTo;};

    inline double X() const;
	inline double Y() const;
	inline double Z() const;

	inline double Width() const;
	inline double Height() const;

    inline void setX(double);
    inline void setY(double);
    inline void setZ(double);

    inline void setWidth(double);
    inline void setHeight(double);

	inline QPointF size() const;

    inline virtual void trigger();
    inline virtual void collisionTrigger(int);

    inline void setID(int);
	inline int ID() const;
	inline int sceneID();

    inline void setCollisionList(QList<collisionObj*>*);
	
};

inline double collisionObj::X() const
{
	return coor.x;
}
inline double collisionObj::Y() const
{
	return coor.y;
}
inline double collisionObj::Z() const
{
	return coor.z;
}
inline double collisionObj::Width() const
{
	return width;
}
inline double collisionObj::Height() const
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

inline QPointF collisionObj::size() const
{
	return QPointF(width, height);
}

inline void collisionObj::trigger()
{
	qDebug() << "x: " << this->X()		//unittest
		<< " y: " << this->Y()			//unittest
		<< " has been triggered!\n";	//unittest
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

inline int collisionObj::ID() const
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

#endif // COLLISIONOBJ_H