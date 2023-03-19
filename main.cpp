#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Point/NamedPoint/NamedPoint.hpp"
#include "Point/PointHandler/PointHandler.hpp"
#include "ProblemSolver/ProblemSolver.hpp"

static NamedPoint *points = 0;

// ./main <point_file> <populations_num> <generations_num> <candidates_num>
int main(int argc, const char **argv) 
{
    srand(time(NULL));
    Genome res;
    int i, count = 0;
    char name[10];
    int x, y;

    if (argc != 5)
    {
        fprintf(stderr, "Usage: ./main <point_file> "
        "<populations_num> <generations_num> <candidates_num>\n");
        return 1;
    }

    String point_file = argv[1];
    int populations_num = atoi(argv[2]);
    int generations_num = atoi(argv[3]);
    int candidates_num = atoi(argv[4]);

    FILE *f = fopen(point_file.GetStr(), "r");
    if (!f)
    {
        fprintf(stderr, "Error while opening file: no such file "
            "or permissions denied\n");
        return 2;
    }
    while (fscanf(f, "%s %d %d", name, &x, &y) != EOF) {
        count++;
    }
    fclose(f);

    points = new NamedPoint[count];

    f = fopen(point_file.GetStr(), "r");
    if (!f)
    {
        fprintf(stderr, "Error while opening file: no such file "
            "or permissions denied\n");
        return 2;
    }
    i = 0;
    while (fscanf(f, "%s %d %d", name, &x, &y) != EOF) {
        points[i] = NamedPoint(name, x, y);
        i++;
    }
    fclose(f);

    ProblemSolver *pr = ProblemSolver::Init(populations_num, generations_num,
        points, i, candidates_num);    
    pr->Solve(&res);
    for (i = 0; i < res.GetArrayLen(); i++)
        PointHandler::PrintNamedPoint(&res[i]);
    PointHandler::PrintNamedPoint(&res[0]);
    printf("%f\n", res.GetLen());

    delete pr;
    delete[] points;
    points = 0;
    return 0;
}