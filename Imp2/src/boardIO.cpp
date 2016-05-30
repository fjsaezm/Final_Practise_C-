
#include "boardIO.h"
#include <iostream>
#include "player.h"
#include "board.h"
#include "matrix.h"
#include <cstring>

using namespace std;

void GameIO::setBoard(Board& board)
{
  int r,c,to_align;
  cin >> r >> c >> to_align;
  Matrix m(r,c);

  board.setTable(m);
  board.setToAlign(to_align);
}

void GameIO::printPlayerName(const Player& player,std::ostream& os)
{
  const char* p = player.getName();
  for(int i = 0; p[i] != 0; i ++) os << p[i];
}

void GameIO::setPlayers(Player& player1, Player& player2)
{
  char name1[50] = {0}, name2[50] = {0};

  cin.getline(name1,50,'\n');

  player1.setName(name1,strlen(name1));

  cin.getline(name2,50,'\n');

  player2.setName(name2,strlen(name2));
}

void GameIO::printBoard(Board board, ostream& os)
{
  for(int i = 0; i < board.cols(); i++)
    os << i << "  ";
  os << endl;

  for(int i = 0; i < board.rows(); i++)
  {

    for(int j = 0; j < board.cols(); j++)
    {
      os << "|";
      if(board.getPosition(i,j) == 0) os << " ";
      else if(board.getPosition(i,j) == 1) os << "X";
      else os << "O";
    }
    os << "|"  << endl;
  }

}

void GameIO::insertToken(Board& board,ostream& os)
{
  int colToPlace;
  if(board.getTurn() == 1)
  {
    os << "Player " << board.getTurn() << " turn (X) " << endl;
  }
  else   os << "Player " << board.getTurn() << " turn (O) " << endl;

  os << "Introduce a column to place your token" << endl;
  cin >> colToPlace;

  if(board.insertInColumn(colToPlace))
  {
    printBoard(board);
    if(!board.inARow())board.setTurn();
  }
  else os << "Wrong column" << endl;
}

void GameIO::results(const Board& board, Player& player1, Player& player2,std::ostream& os)
{
  os << "Game has ended!!!" << endl;

  if(board.emptyPositions() == 0)
  {
    os << "Nobody won this time! Draw!" << endl;
  }
  else {
    os << "The winner of this game was:";
    if(board.getTurn()==1) printPlayerName(player1);
    else printPlayerName(player2);
    os << endl;
    if(player1.getTurn() == board.getTurn())
    {
      player1.addScore(board.calculateScore());
      player1.addWonGame();
    }
    else
    {
      player2.addScore(board.calculateScore());
      player2.addWonGame();
    }
  }

  printPlayerName(player1,os); os << " score is:" << player1.getScore() << " and has won: " << player1.getWonGames() << " games" << endl;
  printPlayerName(player2,os); os << " score is:" << player2.getScore() << " and has won: " << player2.getWonGames() << " games" << endl;

}


bool GameIO::keepPlaying(std::ostream& os)
{
  char c;
  os << "Do you want to keep playing? (Y/N)" << endl;
  cin >> c;
  return c == 'Y' || c == 'y';
}
