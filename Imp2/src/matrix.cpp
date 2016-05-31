#include "matrix.h"

Matrix::Matrix(int rows,int cols)
{
  r = rows;
  c = cols;
  m = new int[rows*cols];
  for(int i = 0; i < rows*cols; i++) m[i] = 0;
}

Matrix::Matrix(const Matrix& matrix):r(matrix.r),c(matrix.c)
{
    m = new int[matrix.r*matrix.c];
    for(int i = 0; i < r*c; i++)
      m[i] = matrix.m[i];
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

Matrix& Matrix::operator =(const Matrix& matrix)
{
  //Easier calling the copy constructor
  if(this!= &matrix)
  {
    delete []m;
    r = matrix.r;
    c = matrix.c;
    m = new int[r*c];
    for(int i = 0; i < r*c; i++) m[i] = matrix.m[i];
  }

  return *this;
}

Matrix:: ~Matrix()
{
  delete []m;
  r = 0;
  c = 0;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
  os << matrix.r << " " << matrix.c << std::endl;
  for(int i = 0; i < matrix.r; i++)
  {
    for(int j = 0; j < matrix.c; j++)
    {
      os << matrix.getElement(i,j) <<" ";
    }
    os << std::endl;
  }

  return os;
}


std::istream& operator>>( std::istream& is, Matrix& matrix)
{
  is >> matrix.r >> matrix.c;

  matrix.m = new int[matrix.r*matrix.c];
  for(int i = 0; i < matrix.r; i++)
  {
    for(int j = 0; j < matrix.c; j++)
    {
      int k;
      is >> k;
      matrix.setElement(i,j,k);
    }
  }

  return is;
}
