#include <stdio.h>

#include "Point/Point.hpp"
#include "PointHandler/PointHandler.hpp"

int main() 
{
    Point a(53,15);
    Point b(11,53);
    Point c = a + b;
    Point d(c + b);
    Point e = a;
    Point f(d);
    c = c + a;
    return 0;
}