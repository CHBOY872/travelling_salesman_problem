#include <stdlib.h>

#include "Genome.hpp"
#include "../Point/Point/Point.hpp"
#include "../Point/PointHandler/PointHandler.hpp"

enum {
    population_length = 100
};

const double Genome::mutation_rate = 0.05;

Genome::Genome(const Genome& a) 
    : arr_len(a.arr_len)
{
    int i;

    points = new Point*[a.arr_len];
    for (i = 0; i < a.arr_len; i++)
        points[i] = new Point(*a.points[i]);
}

float Genome::RouteLength(Point **arr, int len)
{
    int i;
    float res = 0;
    for (i = 0; i < len - 1; i++)
        res += PointHandler::Modulo(arr[i], arr[i+1]);

    res += PointHandler::Modulo(arr[i], arr[0]);
    return res;
}

void Genome::Shuffle()
{
    int i, new_idx;
    Point buff;
    for (i = 0; i < arr_len; i++)
    {
        buff = *points[i];
        new_idx = i + rand() % (arr_len - i);
        *points[i] = *points[new_idx];
        *points[new_idx] = buff;  
    }
}

Genome* Genome::InitGenome(Point *points, int point_count) 
{
    Point **pnts = new Point*[point_count];
    unsigned int i;
    for (i = 0; i < point_count; i++)
            pnts[i] = new Point(points[i]);

    return new Genome(pnts, point_count);
}

Genome Genome::Crossover(const Genome& a)
{
    int pivot = rand() % arr_len;
    Genome res(arr_len);
    
    int i;
    for (i = 0; i < pivot; i++)
        res[i] = *points[i];
    for (i = pivot; i < arr_len; i++)
        res[i] = *a.points[i];

    return res;
}

void Genome::Mutate()
{
    if (rand() < mutation_rate * RAND_MAX)
    {
        int index1 = rand() % arr_len;
        int index2 = rand() % arr_len;

        Point buf = *points[index1];
        points[index1] = points[index2];
        *points[index2] = buf;
    }
}

const Genome& Genome::operator=(const Genome& a)
{
    if (this == &a)
        return *this;

    int i;
    for (i = 0; i < arr_len; i++)
        delete points[i];
    delete[] points;
    
    arr_len = a.arr_len;
    points = new Point*[arr_len];
    for (i = 0; i < arr_len; i++)
        points[i] = new Point(*a.points[i]);

    return *this;
}