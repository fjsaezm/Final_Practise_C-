
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

void printPlayerName(const Player& player)
{
  const char* p = player.getName();
  for(int i = 0; p[i] != 0; i ++) cout << p[i];
}

void GameIO::setPlayers(Player& player1, Player& player2)
{
  char name1[50] = {0}, name2[50] = {0};

  cin.getline(name1,50,'\n');

  player1.setName(name1,strlen(name1));

  cin.getline(name2,50,'\n');

  player2.setName(name2,strlen(name2));
}

void GameIO::printBoard(Board board) const
{
  for(int i = 0; i < board.cols(); i++)
    cout << i << "  ";
  cout << endl;

  for(int i = 0; i < board.rows(); i++)
  {

    for(int j = 0; j < board.cols(); j++)
    {
      cout << "|";
      if(board.getPosition(i,j) == 0) cout << " ";
      else if(board.getPosition(i,j) == 1) cout << "X";
      else cout << "O";
    }
    cout << "|"  << endl;
  }

}

void GameIO::insertToken(Board& board)
{
  int colToPlace;
  if(board.getTurn() == 1)
  {
    cout << "Player " << board.getTurn() << " turn (X) " << endl;
  }
  else   cout << "Player " << board.getTurn() << " turn (O) " << endl;

  cout << "Introduce a column to place your token" << endl;
  cin >> colToPlace;

  if(board.insertInColumn(colToPlace))
  {
    printBoard(board);
    if(!board.inARow())board.setTurn();
  }
  else cout << "Wrong column" << endl;
}

void GameIO::results(const Board& board, Player& player1, Player& player2)
{
  cout << "Game has ended!!!" << endl;

  if(board.emptyPositions() == 0)
  {
    cout << "Nobody won this time! Draw!" << endl;
  }
  else {
    cout << "The winner of this game was:";
    if(board.getTurn()==1) printPlayerName(player1);
    else printPlayerName(player2);
    cout << endl;
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

  cout << "Player 1 score is:" << player1.getScore() << " and has won: " << player1.getWonGames() << " games" << endl;
  cout << "Player 2 score is:" << player2.getScore() << " and has won: " << player2.getWonGames() << " games" << endl;

}


bool GameIO::keepPlaying()
{
  char c;
  cout << "Do you want to keep playing? (Y/N)" << endl;
  cin >> c;
  return c == 'Y' || c == 'y';
}
