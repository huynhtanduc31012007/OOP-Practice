#include "Rectangle.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include "Tokenizer.h"

int Rectangle::InstanceCount = 0;

Rectangle::Rectangle() {
  _topLeft = new Point();
  _bottomRight = new Point();
  ++InstanceCount;
}
Rectangle::Rectangle(Point *A, Point *B) {
  _topLeft = A;
  _bottomRight = B;
  ++InstanceCount;
}
Rectangle::Rectangle(const Rectangle &other) {
  _topLeft = other._topLeft ? new Point(*(other._topLeft)) : nullptr;
  _bottomRight = other._bottomRight ? new Point(*(other._bottomRight)) : nullptr;
  ++InstanceCount;
}

Rectangle::~Rectangle() {
  --InstanceCount;
  delete _topLeft;
  delete _bottomRight;
  _topLeft = nullptr;
  _bottomRight = nullptr;
}

Rectangle &Rectangle::operator=(const Rectangle &other) {
  if (this != &other) {
    delete _topLeft;
    delete _bottomRight;
    _topLeft = other._topLeft ? new Point(*(other._topLeft)) : nullptr;
    _bottomRight = other._bottomRight ? new Point(*(other._bottomRight)) : nullptr;
  }
  return *this;
}

void Rectangle::setTopLeft(Point *p) {
  if (p != nullptr && _topLeft != p) {
    delete _topLeft;
    _topLeft = p;
  }
}
void Rectangle::setBottomRight(Point *p) {
  if (p != nullptr && _bottomRight != p) {
    delete _bottomRight;
    _bottomRight = p;
  }
}

float Rectangle::Width() const {
  if (!_topLeft || !_bottomRight)
    return 0.0f;
  return std::abs(_bottomRight->X() - _topLeft->X());
}

float Rectangle::Height() const {
  if (!_topLeft || !_bottomRight)
    return 0.0f;
  return std::abs(_topLeft->Y() - _bottomRight->Y());
}

float Rectangle::Area() const {
  return Width() * Height();
}

float Rectangle::Perimeter() const {
  return 2 * (Width() + Height());
}

std::string Rectangle::ToString() const {
  if (!_topLeft || !_bottomRight)
    return "";
  std::string str = "TopLeft: " + _topLeft->ToString() + "\n" +
                    "BottomRight: " + _bottomRight->ToString() + "\n" +
                    "Chu vi: " + std::to_string(Perimeter()) + "\n" +
                    "Dien tich: " + std::to_string(Area());
  return str;
}

std::istream &operator>>(std::istream &is, Rectangle &r) {
  Point p1, p2;
  while (true) {
    while (true) {
      std::cout << "Nhap toa do diem tren-trai TopLeft (x y): ";
      is >> p1;
      if (is.fail()) {
        if (is.eof())
          return is;
        std::cout << "Nhap sai, vui long nhap lai!" << std::endl;
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      break;
    }

    while (true) {
      std::cout << "Nhap toa do diem duoi-phai BottomRight (x y): ";
      is >> p2;
      if (is.fail()) {
        if (is.eof())
          return is;
        std::cout << "Nhap sai, vui long nhap lai!" << std::endl;
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      break;
    }

    if (p1.X() >= p2.X() || p1.Y() <= p2.Y()) {
      if (is.eof())
        return is;
      std::cout << "Toa do khong hop le (yeu cau x_topLeft < x_bottomRight va y_topLeft > y_bottomRight). Vui long nhap lai!\n" << std::endl;
      continue;
    }
    break;
  }

  if (r._topLeft == nullptr)
    r._topLeft = new Point();
  if (r._bottomRight == nullptr)
    r._bottomRight = new Point();
  r._topLeft->SetX(p1.X());
  r._topLeft->SetY(p1.Y());
  r._bottomRight->SetX(p2.X());
  r._bottomRight->SetY(p2.Y());
  return is;
}

std::ostream &operator<<(std::ostream &os, const Rectangle &r) {
  os << r.ToString();
  return os;
}

Rectangle* Rectangle::Parse(std::string line){
    std::vector<std::string> tokens = Tokenizer::Parse(line);
    std::vector<double> numbers;
    for (auto token : tokens)
      numbers.push_back(stof(token));
    if (numbers.size() < 4)
      return nullptr;
    Point* topLeft = new Point(numbers[0], numbers[1]);
    Point* bottomRight = new Point(numbers[2], numbers[3]);
    return new Rectangle(topLeft, bottomRight);
}