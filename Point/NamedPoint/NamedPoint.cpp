#include "NamedPoint.hpp"

const NamedPoint& NamedPoint::operator=(const NamedPoint& a)
{
    *(Point*)this = (Point)a;
    header = a.header;
    return *this;
}

NamedPoint operator+(const NamedPoint& a, const NamedPoint& b)
{
    return (Point)a + (Point)b;
}

NamedPoint operator-(const NamedPoint& a, const NamedPoint& b)
{
    return (Point)a - (Point)b;
}
