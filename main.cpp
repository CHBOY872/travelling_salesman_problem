#include <stdio.h>

#include "Point/Point/Point.hpp"
#include "Point/PointHandler/PointHandler.hpp"
#include "Matrix/Matrix/Matrix.hpp"
#include "Matrix/MatrixHandler/MatrixHandler.hpp"
#include "List/List.hpp"

int main() 
{
    unsigned int i, j;

    Matrix a1(10,15);
    for (i = 0; i < a1.GetRow(); i++)
    {
        for (j = 0; j < a1.GetCol(); j++)
            a1[i][j] = i + j;
    }
    Matrix a2(15,5);
    for (i = 0; i < a2.GetRow(); i++)
    {
        for (j = 0; j < a2.GetCol(); j++)
            a2[i][j] = i * j;
    }
    Matrix a3(a1 * a2);

    MatrixHandler::MatrixPrint(&a3);
    a3.Transpose();
    printf("\n\n\n\n\n");
    MatrixHandler::MatrixPrint(&a3);

    List<int> a;
    a.Push(36);
    a.Push(644);
    a.Push(664646);
    a.Push(103);

    List<int>::Iterator* it = a.Iterate();
    while(it->More())
        printf("%d\n", (int)it->Next());
    delete it;

    a.Pop();
    it = a.Iterate();
    while(it->More())
        printf("%d\n", (int)it->Next());
    delete it;

    return 0;
}