#include <stdio.h>
#include <math.h>

#include "PointHandler.hpp"
#include "../Point/Point.hpp"
#include "../../String/String.hpp"

float PointHandler::Modulo(const Point *a, const Point *b)
{
    return sqrt(pow(b->GetX() - a->GetX(), 2) + pow(b->GetY() - a->GetY(), 2));
}

void PointHandler::PrintPoint(const Point *a)
{
    printf("{%2.5f, %2.5f} ", a->GetX(), a->GetY());
}

void PointHandler::PrintNamedPoint(const NamedPoint *a)
{
    printf("%s: ", (const char*)a->GetHeader());
    PrintPoint(a);
    printf("\n");
}