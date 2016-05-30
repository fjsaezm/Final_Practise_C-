#ifndef GAMEIO_H
#define GAMEIO_H

#include "board.h"
#include "player.h"

class GameIO
{
  public:

    void setBoard(Board& board);
    void setPlayers(Player& player1, Player& player2);
    void printBoard( Board board) const;
    void insertToken(Board& board);
    void results(const Board& board, Player& player1, Player& player2);
    bool keepPlaying();

};


#endif
