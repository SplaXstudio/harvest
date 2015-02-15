#ifndef COLLISIONOBJ_H
#define COLLISIONOBJ_H

#include <QList>

class QPointF;
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
