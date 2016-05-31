#include <iostream>
#include "player.h"
#include "board.h"
#include "matrix.h"
#include "boardIO.h"
#include <fstream>



using namespace std;

void SaveGame(const Board& board, const Player& player1, const Player& player2)
{
  ofstream f("save.txt",ofstream::out);
  if(f)
  {
    f << board << player1 << player2;
    f.close();
  }

    else
    {
       cerr << "File couldn't be opened" << endl;
       f.setstate(ios::failbit);
       f.close();

     }
}

bool LoadGame(char* name,Board& board, Player& player1, Player& player2)
{
  ifstream f(name,ifstream ::in);
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


int main(int argc, char* argv[])
{

  if(argc > 1)
  {
    Board board;
    GameIO Game;
    Player player1(1),player2(2);
    if(LoadGame(argv[1],board,player1,player2))
    {
      do{
          Game.printBoard(board);
          while(!board.inARow() && board.emptyPositions() != 0)
          {
            Game.insertToken(board);
            SaveGame(board,player1,player2);
          }
          Game.results(board, player1,player2);
          board.resetBoard();

      }while(Game.keepPlaying());

    }

  }
  else
  {
    Board board;
    GameIO Game;
    Player player1(1),player2(2);
    cout << "Introduce the name of a player, press enter and then introduce the name of the second player" << endl;
    Game.setPlayers(player1,player2);
    cout << "Hello "; Game.printPlayerName(player1,cout); cout << " and "; Game.printPlayerName(player2,cout); cout << "!!!" << endl;
    cout << "Introduce the number of rows and columns for the board. Introduce then the number of tokens that you want to align" << endl;
    Game.setBoard(board);
    do{
        Game.printBoard(board);
        while(!board.inARow() && board.emptyPositions() != 0)
        {
          Game.insertToken(board);
          SaveGame(board,player1,player2);
        }
        Game.results(board, player1,player2);
        board.resetBoard();

    }while(Game.keepPlaying());
  }


  cout << "Thanks for playing!" << endl;


  return 0;

}
