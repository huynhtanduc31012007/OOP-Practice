#include "Point.h"
#include <cmath>
#include <iostream>
#include <string>

int Point::InstanceCount = 0;
Point::Point() {
  _x = 0;
  _y = 0;
  ++InstanceCount;
}
Point::Point(const Point &other) {
  this->_x = other._x;
  this->_y = other._y;
  ++InstanceCount;
}
Point::Point(float x, float y) {
  _x = x;
  _y = y;
  ++InstanceCount;
}

Point::~Point() { InstanceCount--; }

Point &Point::operator=(const Point &other) {
  if (this != &other) {
    _x = other._x;
    _y = other._y;
  }
  return *this;
}

float Point::CalcDistanceTo(const Point &other) const {
  float dx = _x - other._x;
  float dy = _y - other._y;
  return std::sqrt(dx * dx + dy * dy);
}

float Point::CalcDistanceTo(const Point *other) const {
  if (!other)
    return 0.0f;
  return CalcDistanceTo(*other);
}

std::string Point::ToString() const {
  return "(" + std::to_string(_x) + "," + std::to_string(_y) + ")";
}

std::istream &operator>>(std::istream &is, Point &p) {
  is >> p._x >> p._y;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << p.ToString();
  return os;
}
