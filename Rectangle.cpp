#include "Rectangle.h"

int Rectangle::InstanceCount = 0;

Rectangle::Rectangle(){
    _topLeft = new Point();
    _bottomRight = new Point();
    ++InstanceCount;
}
Rectangle::Rectangle(Point *A, Point *B){
    _topLeft = A;
    _bottomRight = B;
    ++InstanceCount;
}
Rectangle::Rectangle(const Rectangle & other){
    _topLeft = new Point(*(other._topLeft));
    _bottomRight = new Point(*(other._bottomRight));
    ++InstanceCount;
}

Rectangle::~Rectangle(){
    *_topLeft = {0, 0};
    *_bottomRight = {0, 0};
    --InstanceCount;
    delete _topLeft;
    delete _bottomRight;
}