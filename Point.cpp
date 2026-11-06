#include "Point.h"
#include <cmath>

int Point::InstanceCount = 0;
Point::Point() {
    _x = 0;
    _y = 0;
    ++InstanceCount;
}
Point::Point(const Point & other){
    this->_x = other._x;
    this->_y = other._y;
    ++InstanceCount;
}
Point::Point(float x, float y) {
    _x = x;
    _y = y;
    ++InstanceCount;
}

Point::~Point() {
    InstanceCount--;
}

float Point::CalcDistanceTo(const Point* other) {
    if (other == nullptr || this == nullptr) return 0.0f;
    float dx = _x - other->_x;
    float dy = _y - other->_y;
    return std::sqrt(dx * dx + dy * dy);
}
