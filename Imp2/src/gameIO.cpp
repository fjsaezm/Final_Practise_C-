
#include "gameIO.h"
#include <iostream>
#include "player.h"
#include "board.h"
#include "matrix.h"
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

void GameIO::setBoard(Board& board)
{
  int r,c;
  cin >> r >> c;
  if( r < 3 || c < 3) smallTable();
  else
  {
    Matrix m(r,c);
    board.setTable(m);

    askToAlign(board);
    askToInsert(board);
  }
}

void GameIO::smallTable(ostream& os)
{
  os << "That board is to small, remember to do it at least 3x3. Try again" << endl;
}

void GameIO::printPlayerName(const Player& player,std::ostream& os)
{
  const char* p = player.getName();
  for(int i = 0; p[i] != 0; i ++) os << p[i];
}

void GameIO::setPlayers(Player& player1, Player& player2)
{
  char name1[100] = {0}, name2[100] = {0};

  cin.getline(name1,100,'\n');

  player1.setName(name1,strlen(name1));

  cin.getline(name2,100,'\n');

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

void GameIO::insertToken(Board& board,const Player& player1, const Player& player2,ostream& os)
{
  int colToPlace;

  if(board.getTurn() == 1)
  {
    printPlayerName(player1); os << " turn (X) " << endl;
    if(player1.isAI()) colToPlace = AIcolumn(board);
    else
    {
      os << "Introduce a column to place your token" << endl;
      cin >> colToPlace;
    }
  }
  else
  {
    printPlayerName(player2); os  << " turn (O) " << endl;
    if(player2.isAI()) colToPlace = AIcolumn(board);
    else
    {
      os << "Introduce a column to place your token" << endl;
      cin >> colToPlace;
    }

  }

  if(board.insertInColumn(colToPlace))
  {
    printBoard(board);
  }
  else
  {
    os << "Wrong column" << endl;
    dialogSaveGame(board,player1,player2);
    insertToken(board,player1,player2);
  }
}

void GameIO::askToAlign(Board& board, ostream& os)
{
  int number;
  os << "Introduce the number of tokens that you would like the players to align in this game."<< endl;
    do {
      cin >> number;
      if( !(number > 1 && number < board.cols()+1)) os << "Wrong election, try again" << endl;
    } while(!(number > 1 && number < board.cols()+1));

  board.setToAlign(number);
}

void GameIO::askToInsert(Board& board, ostream& os)
{
  if(board.getToAlign() < 4) board.setToInsert(1);
  else
  {
    int number;
    os << "Introduce the number of tokens that you want the place to introduce in each turn.(1-" << board.getToAlign()-2 << ")" << endl;
    do {
      cin >> number;
      if(!(number > 1 && number < board.getToAlign()-2)) os << "Not valid!" << endl;
    } while(number < 1 && number > board.getToAlign()-2);
    board.setToInsert(number);
  }
}

int GameIO::AIcolumn(const Board& board)
{
  int n = rand() % board.rows();
  while(board.getPosition(0,n) != 0) n = rand() % board.rows();
  return n;
}

void GameIO::results(Board& board, Player& player1, Player& player2,std::ostream& os)
{
  os << "Game has ended!!!" << endl;

  if(board.emptyPositions() == 0 && !board.inARow())
  {
    os << "Nobody won this time! Draw!" << endl;
  }
  else {
    os << "The winner of this game was:";
    if(board.getTurn()==1)
      printPlayerName(player1);
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
  board.setTurn();
}


bool GameIO::keepPlaying(std::ostream& os)
{
  char c;
  os << "Do you want to keep playing? (Y/N)" << endl;
  cin >> c;
  return c == 'Y' || c == 'y';
}


bool GameIO::saveGame(const char* filename,const Board& board, const Player& player1, const Player& player2)
{
  ofstream f(filename,ofstream::out);
  if(f)
  {
    f << board << player1 << player2;
    f.close();
    return true;
  }

    else
    {
       cerr << "File couldn't be opened" << endl;
       f.setstate(ios::failbit);
       f.close();
       return false;

     }
}

bool GameIO::loadGame(const char* filename,Board& board, Player& player1, Player& player2)
{
  ifstream f(filename,ifstream ::in);
  if(f)
  {
    f >> board >> player1 >> player2;

    f.close();
    return true;
  }
  else
  {
    cerr << "File couldnt be opened" << endl;
    f.setstate(ios::failbit);
    f.close();
    return false;
  }
}

void GameIO::dialogSaveGame(Board& board,const Player& player1, const Player& player2,std::ostream& os)
{
  char aux;
  os << "Do you want to save game?(Y/N)" << endl;
  cin >> aux;
  if(aux == 'Y' || aux == 'y')
  {
      cin.ignore();
      char filename[100];
      cout << "Introduce a name to save the game" << endl;
      cin.getline(filename,100,'\n');
      if(saveGame(filename, board,player1,player2)) cout << "Saved correctly" << endl;
  }
}
