#ifndef Rectangle_h
#define Rectangle_h
#include "Point.h"
#include <iostream>
#include <string>

class Rectangle {
public:
  static int InstanceCount;

private:
  Point *_topLeft;
  Point *_bottomRight;

public:
  Rectangle();
  Rectangle(Point *A, Point *B);
  Rectangle(const Rectangle &other);
  ~Rectangle();
  Rectangle &operator=(const Rectangle &other);

  void setTopLeft(Point *);
  void setBottomRight(Point *);
  Point getTopLeft() const { return *_topLeft; }
  Point getBottomRight() const { return *_bottomRight; }

  float Width() const;
  float Height() const;
  float Area() const;
  float Perimeter() const;
  std::string ToString() const;

  friend std::istream &operator>>(std::istream &is, Rectangle &r);
  friend std::ostream &operator<<(std::ostream &os, const Rectangle &r);
  static Rectangle* Parse(std::string);
  
};

#endif