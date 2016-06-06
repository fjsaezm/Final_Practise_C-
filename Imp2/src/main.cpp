#include <iostream>
#include "player.h"
#include "board.h"
#include "matrix.h"
#include "gameIO.h"
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{

  if(argc > 1)
  {
    Board board;
    GameIO Game;
    Player player1(1),player2(2);
    if(Game.loadGame(argv[1],board,player1,player2))
    {
      do{
          Game.printBoard(board);
          while(!board.inARow() && board.emptyPositions() != 0)
          {
            Game.insertToken(board,player1,player2);
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
    cout << "Introduce the number of rows and columns for the board. Make it bigger than 3x3." << endl;
    Game.setBoard(board);

    do{
        cout << "This is your empty board! Let's play!!!" << endl;
        Game.printBoard(board);
        while(!board.inARow() && board.emptyPositions() != 0)
        {
          for(int i = 0; i < board.getToInsert() && !board.inARow() && board.emptyPositions() != 0; i++)
          {
            Game.insertToken(board,player1,player2);
          }
          if(!board.inARow() && board.emptyPositions()!= 0)board.setTurn();
        }
        Game.results(board, player1,player2);
        board.resetBoard();

    }while(Game.keepPlaying());
  }


  cout << "Thanks for playing!" << endl;


  return 0;

}
