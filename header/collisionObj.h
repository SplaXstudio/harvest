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
    double X;
    double Y;
    double Z;
    }coor;
    double width;
    double height;

private:
    int speed_x;
    int speed_y;
    int speed_z;

    DAnimation *animation;

    int ID;
	int sceneID;
	int tpTo;

    QList<collisionObj*> * collisionList;
	
public:
    collisionObj(double, double, double, QPointF);
    virtual ~collisionObj();
	inline int tp(){return tpTo;};

    inline double x() const;
	inline double y() const;
	inline double z() const;

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
	inline int id() const;
	inline int sceneid();

    inline void setCollisionList(QList<collisionObj*>*);
	
};

inline double collisionObj::x() const
{
	return coor.X;
}
inline double collisionObj::y() const
{
	return coor.Y;
}
inline double collisionObj::z() const
{
	return coor.Z;
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
	coor.X = shit;
}
inline void collisionObj::setY(double shit)
{
	coor.Y = shit;
}
inline void collisionObj::setZ(double shit)
{
	coor.Z = shit;
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
	qDebug() << "x: " << this->x()		//unittest
		<< " y: " << this->y()			//unittest
		<< " has been triggered!\n";	//unittest
	return;
}

inline void collisionObj::collisionTrigger(int collisionID)
{
	return;
}

inline void collisionObj::setID(int _id)
{
	ID = _id;
}

inline int collisionObj::id() const
{
	return ID;
}

inline int collisionObj::sceneid()
{
	return sceneID;
}

inline void collisionObj::setCollisionList(QList<collisionObj*> *colist)
{

}

#endif // COLLISIONOBJ_H