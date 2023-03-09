#include <math.h>

#include "PointHandler.hpp"
#include "../Point/Point.hpp"

float PointHandler::Modulo(Point *a, Point *b)
{
    return sqrt(pow(b->GetX() - a->GetX(), 2) + pow(b->GetY() - a->GetY(), 2));
}