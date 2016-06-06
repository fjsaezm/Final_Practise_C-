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

int Board::getToInsert() const
{
  return toInsert;
}

void Board::setToInsert(int number)
{
  this->toInsert = number;
}

int Board::leftToInsert() const
{
  return (rows()*cols() - this->emptyPositions())%toInsert;
}

void Board::setTurn()
{
  turn = turn == 1 ? 2 : 1;
}

bool Board::insertInColumn(int j)
{
  int i = 0;
  //Separate if, because i have an assert on get position and this avoids that assert
  if(j < 0 || j >= cols())
    return false;

  if(getPosition(i,j) != 0)
    return false;

  while(getPosition(i,j) == 0 && i != cols()) i++;

  if(turn == 1)
    m.setElement(i-1,j,1);

  else
    m.setElement(i-1,j,2);

  return true;
}


void Board::setTable(const Matrix& matrix)
{
  this->m = matrix;
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
        for(int k = -1; k <= 1 && !inARow; k++)
        {
          for(int t = -1; t <= 1 && !inARow; t++)
          {
            if(!(k == 0 && t == 0))
            {
              inARow = searchInDirection(i,j,k,t);
            }
          }
        }
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

      if(aligned && valid)areAligned++;
    }

    return areAligned == toAlign && aligned;
  }


  int Board::calculateScore() const
  {
    return emptyPositions() + rows()*cols() + toAlign*5;
  }



  std::ostream& operator<<(std::ostream& os, const Board& board)
  {

    if(os)
      os << board.toAlign << " " << board.turn << " " <<board.toInsert <<std::endl << board.m;

    return os;
  }


  std::istream& operator>>(std::istream& is, Board& board)
  {
    if(is)
    {
      is >> board.toAlign >> board.turn >> board.toInsert;
      is >> board.m;
    }

    return is;
  }
