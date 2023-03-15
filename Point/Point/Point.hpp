#ifndef POINT_HPP_SENTRY
#define POINT_HPP_SENTRY

#ifdef DEBUG
#include <stdio.h>
#endif

class Point {
    float x, y;

public:
    Point() : x(0), y(0) 
    {
#       ifdef DEBUG
        printf("DEFAULT CONSTRUCTOR\n");
#       endif
    }
    Point(float _x, float _y) : x(_x), y(_y)
    {
#       ifdef DEBUG
        printf("NON DEFAULT CONSTRUCTOR\n");
#       endif
    }
    Point(const Point& a) : x(a.x), y(a.y)
    {
#       ifdef DEBUG
        printf("COPY CONSTRUCTOR\n");
#       endif
    }
    ~Point()
    {
#       ifdef DEBUG
        printf("DESTRUCTOR\n");
#       endif
    }

    float GetX() { return x; }
    float GetY() { return y; }

    void SetX(float _x) { x = _x; }
    void SetY(float _y) { y = _y; }

    friend Point operator+(const Point& a, const Point& b);
    friend Point operator-(const Point& a, const Point& b);

    const Point& operator=(const Point& a);
};

Point operator+(const Point& a, const Point& b);
Point operator-(const Point& a, const Point& b);

#endif