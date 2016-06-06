#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
  char* name;
  int score;
  int turn;
  int wonGames;

  public:

  Player(int number):score(0),turn(number),wonGames(0){};

  void setName(char* p, int n);

  const char* getName() const;

  void setTurn(int turn);

  void addScore(int score);

  int getScore() const;

  int getTurn() const;

  int getWonGames() const;

  void addWonGame();

  bool isAI() const;

  friend std::ostream& operator<<(std::ostream& os, const Player& player);

  friend std::istream& operator >>( std::istream& is, Player& player);

};


#endif
