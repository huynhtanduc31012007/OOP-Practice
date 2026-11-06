#ifndef Line_h
#define Line_h 
#include "Point.h"

class Line{
public:
    static int InstanceCount;
private:
    Point* _start;
    Point* _end;
    double Lenght;
public:
    Line();
    Line(Point*, Point*);
    Line(const Line&);
    ~Line();
};

#endif