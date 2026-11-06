#ifndef Point_h
#define Point_h
class Point {
public:
    static int InstanceCount;
private:
    float _x;
    float _y;

public:
    float X() { return _x; }
    float Y() { return _y; }
    void SetX(float value) { _x = value; }
    void SetY(float value) { _y = value; }

public:
    Point();
    Point(const Point &);
    Point(float, float);
    ~Point();

public:
    float CalcDistanceTo(const Point* other);
};

#endif // Point_h
