#ifndef Point_h
#define Point_h
#include <iostream>
#include <string>

class Point {
public:
  static int InstanceCount;

private:
  float _x;
  float _y;

public:
  float X() const { return _x; }
  float Y() const { return _y; }
  void SetX(float value) { _x = value; }
  void SetY(float value) { _y = value; }

public:
  Point();
  Point(const Point &);
  Point(float, float);
  ~Point();
  Point &operator=(const Point &other);

public:
  float CalcDistanceTo(const Point &other) const;
  float CalcDistanceTo(const Point *other) const;
  std::string ToString() const;

  friend std::istream &operator>>(std::istream &is, Point &p);
  friend std::ostream &operator<<(std::ostream &os, const Point &p);
};

#endif // Point_h
