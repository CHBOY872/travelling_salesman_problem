#include "Matrix.hpp"

Matrix::Matrix() : arr(0), row(0), col(0) {}
Matrix::Matrix(unsigned int _row, unsigned int _col) : row(_row), col(_col)
{
    unsigned int i;
    arr = new float*[row];
    for (i = 0; i < row; i++)
    {
        arr[i] = new float[col];
        unsigned int j;
        for (j = 0; j < col; j++)
            arr[i][j] = 0;
    }
}

Matrix::Matrix(unsigned int length) : row(length), col(length)
{
    unsigned int i;
    arr = new float*[row];
    for (i = 0; i < row; i++)
    {
        arr[i] = new float[col];
        unsigned int j;
        for (j = 0; j < col; j++)
            arr[i][j] = 0;
    }
}

Matrix::Matrix(const Matrix& a) : row(a.row), col(a.col)
{
    unsigned int i;
    arr = new float*[row];
    for (i = 0; i < row; i++)
    {
        arr[i] = new float[col];
        unsigned int j;
        for (j = 0; j < col; j++)
            arr[i][j] = a.arr[i][j];
    }
}

Matrix::~Matrix()
{
    unsigned int i;
    for (i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
}

Matrix operator*(float val, const Matrix& a)
{
    return a * val;
}

const Matrix& Matrix::operator=(const Matrix& a)
{
    if (this == &a)
        return *this;
    
    col = a.col;
    row = a.row;

    unsigned int i;
    for (i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;

    arr = new float*[row];
    for (i = 0; i < row; i++)
    {
        arr[i] = new float[col];
        unsigned int j;
        for (j = 0; j < col; j++)
            arr[i][j] = a.arr[i][j];
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& a) const
{
    if (col != a.col && row != a.row)
        return *((Matrix*)0);

    unsigned int i, j;

    Matrix res(col, row);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            res.arr[i][j] = arr[i][j] + a.arr[i][j];
    }
    return res;
}

Matrix Matrix::operator-(const Matrix& a) const
{
    if (col != a.col && row != a.row)
        return *((Matrix*)0);

    unsigned int i, j;

    Matrix res(col, row);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            res.arr[i][j] = arr[i][j] - a.arr[i][j];
    }
    return res;
}

Matrix Matrix::operator*(const Matrix& a) const
{
    if (col != a.row)
        return *((Matrix*)0);

    Matrix res(row, a.col);
    unsigned int i, j, k;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < a.col; j++)
        {
            for (k = 0; k < col; k++)
                res.arr[i][j] += arr[i][k] * a.arr[k][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(float val) const
{
    unsigned int i, j;

    Matrix res(col, row);
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            res.arr[i][j] = arr[i][j] * val;
    }
    return res;
}