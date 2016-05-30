#ifndef _MATRIX_H
#define _MATRIX_H

class Matrix
{
  int m[20][20];
  int r,c;

  public:

  Matrix():r(0),c(0){}

  Matrix(int fils,int cols);

  void setRows(int r);

  int rows() const;

  void setCols(int c);

  int cols() const;

  int getElement(int i, int j) const;

  void setElement(int i, int j, int value);

  void setToZero();

  int emptyPositions() const;

};

#endif
