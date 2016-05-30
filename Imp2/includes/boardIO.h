#ifndef GAMEIO_H
#define GAMEIO_H

#include "board.h"
#include "player.h"

class GameIO
{
  public:

    void setBoard(Board& board);
    void setPlayers(Player& player1, Player& player2);
    void printPlayerName(const Player& player,std::ostream& os = std::cout);
    void printBoard( Board board,std::ostream& os = std::cout);
    void insertToken(Board& board,std::ostream& os = std::cout);
    void results(const Board& board, Player& player1, Player& player2,std::ostream& os = std::cout);
    bool keepPlaying(std::ostream& os = std::cout);

};


#endif
