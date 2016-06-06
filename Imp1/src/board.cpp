#include "board.h"


#include <iostream>
using namespace std;

int Board::rows() const
{
  return m.rows();
}

int Board::cols() const
{
  return m.cols();
}

void Board::setToAlign(int number)
{
  this->toAlign = number;
}


int Board::getToAlign() const
{
  return toAlign;
}

int Board::getPosition(int i, int j) const
{
  return m.getElement(i,j);
}

int Board::emptyPositions() const
{
  return m.emptyPositions();
}

void Board::resetBoard()
{
  m.setToZero();
}

int Board::getTurn() const
{
  return turn;
}

void Board::setTurn()
{
  turn = turn == 1 ? 2 : 1;
}

bool Board::insertInColumn(int j)
{

  int i = 0;
  if(getPosition(i,j) != 0) return false;
  while(getPosition(i,j) == 0 && i != cols()) i++;

  if(turn == 1) m.setElement(i-1,j,1);
  else m.setElement(i-1,j,2);

  return true;
}


void Board::setTable(Matrix m)
{
  this->m.setCols(m.cols());
  this->m.setRows(m.rows());

  for(int i = 0; i < m.rows(); i++)
  {
    for(int j = 0; j < m.cols(); j++)
    {
      this->m.setElement(i,j,m.getElement(i,j));
    }
  }
}

bool Board::inARow() const
{
  bool inARow = false;
  for(int i = 0; i < rows() && !inARow; i++)
  {
    for(int j = 0; j < cols()  && !inARow; j++)
    {
      if(getPosition(i,j)!= 0)
      {
        if(i == 0)
        {
          if(j == 0) inARow = searchInDirection(i,j,0,1) || searchInDirection(i,j,1,0) || searchInDirection(i,j,1,1);
          else if( j == cols() - 1)  inARow = searchInDirection(i,j,1,0) || searchInDirection(i,j,0,-1) || searchInDirection(i,j,1,-1);
          else inARow = searchInDirection(i,j,0,1) || searchInDirection(i,j,1,0) || searchInDirection(i,j,1,1) || searchInDirection(i,j,1,-1) || searchInDirection(i,j,0,-1);

        }

        else if(j == 0)
        {
          if( i == rows()- 1) inARow = searchInDirection(i,j,0,1) || searchInDirection(i,j,-1,0) || searchInDirection(i,j,-1,1);
          else inARow = searchInDirection(i,j,0,1) || searchInDirection(i,j,1,0) || searchInDirection(i,j,-1,0) || searchInDirection(i,j,-1,1) || searchInDirection(i,j,1,1);
        }

        else if(j == cols() - 1)
        {
          if( i == rows()- 1) inARow = searchInDirection(i,j,0,-1) || searchInDirection(i,j,-1,0) || searchInDirection(i,j,-1,-1);
          else inARow = searchInDirection(i,j,0,-1) || searchInDirection(i,j,-1,0) || searchInDirection(i,j,1,0) || searchInDirection(i,j,-1,-1) || searchInDirection(i,j,1,-1);
        }
        else if( i == rows() -1)
        {
          inARow = searchInDirection(i,j,0,1) || searchInDirection(i,j,0,-1) || searchInDirection(i,j,-1,-1) || searchInDirection(i,j,-1,1) || searchInDirection(i,j,-1,0);
        }

        else inARow = searchInDirection(i,j,-1,-1) || searchInDirection(i,j,0,-1) || searchInDirection(i,j,-1,1) || searchInDirection(i,j,1,0) || searchInDirection(i,j,0,1) || searchInDirection(i,j,1,-1) || searchInDirection(i,j,-1,0) || searchInDirection(i,j,1,1);

      }
    }
  }

  return inARow;
}


  bool Board::searchInDirection(int i, int j, int dirI, int dirJ) const
  {
    int areAligned = 1; //There is always 1 aligned (to itself)
    int diri = dirI, dirj = dirJ;
    bool aligned = true;
    bool valid = true;

    while(valid && aligned && areAligned < toAlign)
    {
      aligned = (getPosition(i,j) == getPosition(i + diri,j + dirj));
      valid = (j+dirj) >= 0 && (dirj + j) < cols() && (diri + i) >= 0 && (i + diri) < rows();
      diri += dirI;
      dirj += dirJ;
      areAligned++;
    }

    return areAligned == toAlign && aligned && valid;
  }


  int Board::calculateScore() const
  {
    return emptyPositions() + rows()*cols() + toAlign*5;
  }
