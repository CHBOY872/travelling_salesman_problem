#ifndef GENOME_HPP_SENTRY
#define GENOME_HPP_SENTRY

#include "../Point/NamedPoint/NamedPoint.hpp"

class Genome {
    static const double mutation_rate;

    NamedPoint **points;
    int arr_len;

public:
    Genome(int len) : arr_len(len)
    {
        int i;
        points = new NamedPoint*[len];
        for (i = 0; i < arr_len; i++)
            points[i] = new NamedPoint();
    }
    Genome(const Genome&);
    static Genome* InitGenome(NamedPoint *points, int point_count);

    ~Genome()
    {
        int i;
        for (i = 0; i < arr_len; i++)
            delete points[i];
        delete [] points;
    }

    Genome Crossover(const Genome& a);
    void Mutate();
    inline double GetLen() const { return RouteLength(points, arr_len); }
    inline double GetArrayLen() { return arr_len; }

    bool operator<(const Genome& a) { return GetLen() < a.GetLen(); }
    const Genome& operator=(const Genome&);
    NamedPoint& operator[](int idx) { return *points[idx]; }
    void Shuffle();

private:
    Genome(NamedPoint** arr, int len) : points(arr), arr_len(len) {}

    static float RouteLength(NamedPoint **arr, int len);
};

#endif