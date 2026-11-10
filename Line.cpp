#include "Line.h"
#include <iostream>
#include <limits>
#include <string>

int Line::InstanceCount = 0;

Line::Line() {
  _start = new Point();
  _end = new Point();
  ++InstanceCount;
}

Line::Line(Point *start, Point *end) {
  _start = start;
  _end = end;
  ++InstanceCount;
}

Line::Line(const Line &other) {
  _start = other._start ? new Point(*(other._start)) : nullptr;
  _end = other._end ? new Point(*(other._end)) : nullptr;
  ++InstanceCount;
}

Line::~Line() {
  --InstanceCount;
  delete _start;
  delete _end;
  _start = nullptr;
  _end = nullptr;
}

Line &Line::operator=(const Line &other) {
  if (this != &other) {
    delete _start;
    delete _end;
    _start = other._start ? new Point(*(other._start)) : nullptr;
    _end = other._end ? new Point(*(other._end)) : nullptr;
  }
  return *this;
}

void Line::setStart(Point *p) {
  if (p != nullptr && _start != p) {
    delete _start;
    _start = p;
  }
}

void Line::setEnd(Point *p) {
  if (p != nullptr && _end != p) {
    delete _end;
    _end = p;
  }
}

double Line::Length() const {
  if (!_start || !_end)
    return 0.0;
  return _start->CalcDistanceTo(_end);
}

std::string Line::ToString() const {
  if (!_start || !_end)
    return "";
  std::string str = "Diem dau: " + _start->ToString() + "\n" +
                    "Diem cuoi: " + _end->ToString() + "\n" +
                    "Do dai: " + std::to_string(Length());
  return str;
}

std::istream &operator>>(std::istream &is, Line &L) {
  Point p1, p2;
  while (true) {
    std::cout << "Nhap toa do diem dau (x y): ";
    if (is >> p1)
      break;
    if (is.eof())
      return is;
    std::cout << "Nhap sai, vui long nhap lai!" << std::endl;
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  while (true) {
    std::cout << "Nhap toa do diem cuoi (x y): ";
    if (is >> p2)
      break;
    if (is.eof())
      return is;
    std::cout << "Nhap sai, vui long nhap lai!" << std::endl;
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  if (L._start == nullptr)
    L._start = new Point();
  if (L._end == nullptr)
    L._end = new Point();
  *L._start = p1;
  *L._end = p2;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Line &L) {
  os << L.ToString();
  return os;
}
