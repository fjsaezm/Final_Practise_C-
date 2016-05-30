#include "matrix.h"

Matrix::Matrix(int rows,int cols):r(rows),c(cols)
{
  m = new int[rows*cols];
}

Matrix::Matrix(const Matrix& matrix)
{
  this-> r = matrix.rows();
  this-> c = matrix.cols();

  m = new int[r*c];
  for(int i = 0; i < r*c; i++)
    m[i] = matrix.getElement(i/c,i%c);
}

void Matrix::setRows(int r)
{
  this-> r = r;
}

int Matrix::rows() const
{
  return r;
}

void Matrix::setCols(int c)
{
  this-> c = c;
}

int Matrix::cols() const
{
  return c;
}

int Matrix::getElement(int i, int j) const
{
  return m[i*c + j];
}

void Matrix::setElement(int i, int j, int value)
{
  m[i*c + j] = value;
}

void Matrix::setToZero()
{
  for(int i = 0; i < r * c; i++)
    m[i] = 0;
}

int Matrix::emptyPositions() const
{
  int empty = 0;
  for(int i = 0; i < r*c; i++)
  {
      if( m[i] == 0) empty++;
  }

  return empty;
}

Matrix Matrix::operator =(Matrix matrix)
{
  //Easier calling the copy constructor
  Matrix m(matrix);
  return m;
}

Matrix:: ~Matrix()
{
  delete []m;
  r = 0;
  c = 0;
}
