#include <stdio.h>

#include "../Matrix/Matrix.hpp"
#include "MatrixHandler.hpp"

void MatrixHandler::MatrixPrint(Matrix *m)
{
    if (!m)
        return;

    unsigned int i, j;
    for (i = 0; i < m->GetRow(); i++)
    {
        for (j = 0; j < m->GetCol(); j++)
            printf("%f ", (*m)[i][j]);
        printf("\n");
    }
}