#ifndef BOARD_H
#define BOARD_H

#include "matrix.h"
#include <iostream>

class Board
{
  Matrix m;
  int toAlign;
  int turn;
  int toInsert;

public:

  Board():toAlign(0),turn(1),toInsert(0){};

  Board(int positions,int number):toAlign(positions),turn(1),toInsert(number){};

  int rows() const;

  int cols() const;

  void setToAlign(int number);

  int getToAlign() const;

  int getPosition(int i, int j) const;

  int emptyPositions() const;

  void resetBoard();

  int getTurn() const;

  int getToInsert() const;

  void setToInsert(int number);

  int leftToInsert() const;

  void setTurn();

  bool insertInColumn(int col);

  void setTable(const Matrix& matrix);

  bool inARow() const;

  bool searchInDirection(int i, int j, int dirI, int dirJ) const;

  int calculateScore() const;

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

  friend std::istream& operator>>( std::istream& is, Board& board);
};

#endif
