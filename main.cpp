#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Point/Point/Point.hpp"
#include "Point/PointHandler/PointHandler.hpp"
#include "Matrix/Matrix/Matrix.hpp"
#include "Matrix/MatrixHandler/MatrixHandler.hpp"
#include "List/List.hpp"
#include "ProblemSolver/ProblemSolver.hpp"
#include "String/String.hpp"

static NamedPoint points[] = { NamedPoint("A", 1, 1), NamedPoint("B", 5, 8), 
                               NamedPoint("C", 7, 12), NamedPoint("D", 2, 9),
                               NamedPoint("E", 7, 2), NamedPoint("F", 1, 12),
                               NamedPoint("G", 4, 2) };

enum {
    arr_len = 7
};

int main() 
{
    srand(time(NULL));

    Genome res(arr_len);
    int i;
    ProblemSolver *pr = ProblemSolver::Init(50, 2, points, arr_len);    
    pr->Solve(&res);
    for (i = 0; i < res.GetArrayLen(); i++)
        PointHandler::PrintNamedPoint(&res[i]);
    printf("%f\n", res.GetLen());

    delete pr;
    return 0;
}