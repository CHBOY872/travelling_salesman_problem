#include <stdio.h>
#include <math.h>

#include "PointHandler.hpp"
#include "../Point/Point.hpp"

float PointHandler::Modulo(const Point *a, const Point *b)
{
    return sqrt(pow(b->GetX() - a->GetX(), 2) + pow(b->GetY() - a->GetY(), 2));
}

void PointHandler::PrintPoint(const Point *a)
{
    printf("{%2.5f, %2.5f} ", a->GetX(), a->GetY());
}