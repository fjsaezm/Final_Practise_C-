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
    void insertToken(Board& board,const Player& player1, const Player& player2,std::ostream& os = std::cout);
    void askToAlign(Board& board,std::ostream& os = std::cout);
    void askToInsert(Board& board, std::ostream&os = std::cout);
    void smallTable(std:: ostream& os = std::cout);
    int  AIcolumn(const Board& board);
    void results( Board& board, Player& player1, Player& player2,std::ostream& os = std::cout);
    bool keepPlaying(std::ostream& os = std::cout);
    bool saveGame(const char* filename,const Board& board, const Player& player1, const Player& player2);
    bool loadGame(const char* filename,Board& board, Player& player1, Player& player2);
    void dialogSaveGame(Board& board,const Player& player1, const Player& player2,std::ostream& os = std::cout);

};


#endif
