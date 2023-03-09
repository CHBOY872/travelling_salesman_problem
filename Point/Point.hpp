#ifndef POINT_HPP_SENTRY
#define POINT_HPP_SENTRY

class Point {
    float x, y;

public:
    Point() : x(0), y(0) {}
    Point(float _x, float _y) : x(_x), y(_y) {}
    Point(const Point& a) : x(a.x), y(a.y) {}
    ~Point() {}

    float GetX() { return x; }
    float GetY() { return y; }

    void SetX(float _x) { x = _x; }
    void SetY(float _y) { y = _y; }
};

#endif