#ifndef MATRIX_HPP_SENTRY
#define MATRIX_HPP_SENTRY

class MatrixCursor;
class Matrix {
    friend class MatrixCursor;
    float **arr;
    unsigned int row, col;

public:
    Matrix();
    Matrix(unsigned int _col, unsigned int _row);
    Matrix(unsigned int length);
    Matrix(const Matrix&);
    ~Matrix();

    inline unsigned int GetCol() { return col; }
    inline unsigned int GetRow() { return row; }

    inline MatrixCursor operator[](unsigned int idx);
    const Matrix& operator=(const Matrix&);

    void Transpose();
    Matrix operator+(const Matrix& a) const;
    Matrix operator-(const Matrix& a) const;
    Matrix operator*(const Matrix& a) const;
    Matrix operator*(float val) const;
    friend Matrix operator*(float val, const Matrix& a);
private:
};

class MatrixCursor {
    friend class Matrix;
    Matrix *the_master;
    float *arr;
    int idx;

public:
    MatrixCursor(Matrix *_the_master, unsigned int idx) 
        : the_master(_the_master), arr(_the_master->arr[idx]), idx(idx) {}
    float& operator[](unsigned int _idx) { return arr[_idx]; }
};

MatrixCursor Matrix::operator[](unsigned int idx)
{
    return MatrixCursor(this, idx);
}   

#endif