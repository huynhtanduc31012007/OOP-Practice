#ifndef Rectangle_h
#define Rectangle_h
#include "Point.h"
class Rectangle{
public:
    static int InstanceCount;
private:
    Point *_topLeft;
    Point *_bottomRight;
public:
    Rectangle();
    Rectangle(Point *A, Point *B);
    Rectangle(const Rectangle & other);
    ~Rectangle();
    void setTopLeft(Point*);
    void setBottomRight(Point*);
    Point getTopLeft(){return *_topLeft;}
    Point getBottomRight(){ return *_bottomRight;}
};


#endif