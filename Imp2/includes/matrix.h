#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
  int* m;
  int r,c;

  public:

  Matrix():m(0),r(0),c(0){}

  Matrix(int rows,int cols);

  Matrix(const Matrix& matrix);

  void setRows(int r);

  int rows() const;

  void setCols(int c);

  int cols() const;

  int getElement(int i, int j) const;

  void setElement(int i, int j, int value);

  void setToZero();

  int emptyPositions() const;

  Matrix operator =(Matrix matrix);

  ~Matrix();


};

#endif
