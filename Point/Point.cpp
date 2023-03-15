#ifdef DEBUG
#include <stdio.h>
#endif

#include "Point.hpp"

const Point& Point::operator=(const Point& a)
{
#   ifdef DEBUG
    printf("ASIIGNMENT\n");
#   endif
    if (this == &a)
        return *this;
    
    x = a.x;
    y = a.y;
    return *this;
}

Point operator+(const Point& a, const Point& b)
{
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y);
}