#ifndef POINTHANDLER_HPP_SENTRY
#define POINTHANDLER_HPP_SENTRY

#include "../Point/Point.hpp"

class PointHandler {
public:
    static float Modulo(const Point *a, const Point *b);
    static void PrintPoint(const Point *a);
};

#endif