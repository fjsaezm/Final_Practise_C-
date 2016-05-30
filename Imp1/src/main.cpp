#include <iostream>
#include "player.h"
#include "board.h"
#include "matrix.h"
#include "boardIO.h"

using namespace std;

int main()
{
  Board board;
  GameIO Game;
  Player player1(1),player2(2);
  cout << "Introduce the name of a player, press enter and then introduce the name of the second player" << endl;
  Game.setPlayers(player1,player2);
  cout << "Introduce the number of rows and columns for the board. Introduce then the number of tokens that you want to align" << endl;
  Game.setBoard(board);
  do{
      Game.printBoard(board);
      while(!board.inARow() && board.emptyPositions() != 0)
      {
        Game.insertToken(board);
      }
      Game.results(board, player1,player2);
      board.resetBoard();

  }while(Game.keepPlaying());

  std::cout << "Thanks for playing!" << std::endl;


  return 0;

}
