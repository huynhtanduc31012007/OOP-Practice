#include "Circle.h"

Circle::Circle() {
    _center = new Point();
    _radius = 0;
}

Circle::~Circle() {
    delete _center;
    _radius = 0;
}
