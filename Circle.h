#ifndef Circle_h
#define Circle_h
#include "Point.h"

class Circle {
public:
    const float PI = 3.14f;

private:
    Point* _center;
    float _radius;

public:
    Point* Center() { return _center; }
    float Radius() { return _radius; }
    void SetCenter(Point* value) {
        _center->SetX(value->X());
        _center->SetY(value->Y());
    }
    void SetRadius(float value) { _radius = value; }

public:
    float Diameter() { return 2 * _radius; }
    float Perimeter() { return 2 * _radius * PI; }
    float Area() { return _radius * _radius * PI; }

public:
    Circle();
    ~Circle();
};
#endif // Circle_h
