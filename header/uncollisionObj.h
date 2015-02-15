#ifndef UNCOLLISIONOBJ_H
#define UNCOLLISIONOBJ_H

class QPointF;
class DAnimation;

class uncollisionObj
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

    DAnimation *animation;

    int id;

public:
    uncollisionObj(double, double, double, QPointF);
    virtual ~uncollisionObj();

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

    inline void setID(int);
    inline int ID();

};

#endif // UNCOLLISIONOBJ_H
