#include "Line.h"

int Line::InstanceCount = 0;

Line::Line(){
    _start = new Point();
    _end = new Point();
    Lenght = 0;
    ++InstanceCount;
}
Line::Line(Point *start, Point *end){
    _start = start;
    _end = end;
    Lenght = (*start).CalcDistanceTo(_end);
    ++InstanceCount;
}
Line::Line(const Line& other){
    _start = new Point(*(other._start));
    _end = new Point(*(other._end)); 
    Lenght = (*_start).CalcDistanceTo(_end);
    ++InstanceCount;
}
Line::~Line(){
    *_start = {0, 0};
    *_end = {0, 0};
    Lenght = 0;
    --InstanceCount;
    delete _start;
    delete _end;
}
