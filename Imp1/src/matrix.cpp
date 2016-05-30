#include "matrix.h"

Matrix::Matrix(int fils,int cols):r(fils),c(cols)
{
  for(int i = 0; i < fils; i++)
  {
    for(int j = 0; j < cols; j++)

      m[i][j] = 0;
  }
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
  return m[i][j];
}

void Matrix::setElement(int i, int j, int value)
{
  m[i][j] = value;
}

void Matrix::setToZero()
{
  for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 20; j++)

      m[i][j] = 0;
  }
}

int Matrix::emptyPositions() const
{
  int empty = 0;
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)

      if( m[i][j] == 0) empty++;
  }

  return empty;
}
