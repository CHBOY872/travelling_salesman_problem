#include <stdio.h>
#include <stdlib.h>

#include "Genome.hpp"
#include "../Point/NamedPoint/NamedPoint.hpp"
#include "../Point/PointHandler/PointHandler.hpp"

enum {
    population_length = 100
};

const double Genome::mutation_rate = 0.05;

Genome::Genome(const Genome& a) 
    : arr_len(a.arr_len)
{
    int i;

    points = new NamedPoint*[a.arr_len];
    for (i = 0; i < a.arr_len; i++)
        points[i] = new NamedPoint(*a.points[i]);
}

float Genome::RouteLength(NamedPoint **arr, int len)
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
    NamedPoint *buff;
    for (i = 1; i < arr_len; i++)
    {
        buff = points[i];
        new_idx = i + rand() % (arr_len - i);
        points[i] = points[new_idx];
        points[new_idx] = buff;  
    }
}

Genome* Genome::InitGenome(NamedPoint *points, int point_count) 
{
    NamedPoint **pnts = new NamedPoint*[point_count];
    unsigned int i;
    for (i = 0; i < point_count; i++)
        pnts[i] = new NamedPoint(points[i]);

    return new Genome(pnts, point_count);
}

Genome Genome::Crossover(const Genome& a)
{
    int pivot = 1 + rand() % (arr_len - 1);
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
        int index1 = 1 + rand() % (arr_len - 1);
        int index2 = 1 + rand() % (arr_len - 1);

        NamedPoint *buf = points[index1];
        points[index1] = points[index2];
        points[index2] = buf;
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
    points = new NamedPoint*[arr_len];
    for (i = 0; i < arr_len; i++)
        points[i] = new NamedPoint(*a.points[i]);

    return *this;
}