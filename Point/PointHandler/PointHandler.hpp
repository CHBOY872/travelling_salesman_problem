#ifndef POINTHANDLER_HPP_SENTRY
#define POINTHANDLER_HPP_SENTRY

#include "../Point/Point.hpp"
#include "../NamedPoint/NamedPoint.hpp"

class PointHandler {
public:
    static float Modulo(const Point *a, const Point *b);
    static void PrintPoint(const Point *a);
    static void PrintNamedPoint(const NamedPoint *a);
};

#endif