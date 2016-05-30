#include "player.h"
#include <iostream>
using namespace std;

void Player::setName(char* p, int n)
{
  name = new char[n+1];
  int i = 0;
  for(; i < n; i++)
    name[i] = p[i];

  name[n] = 0;
}

const char* Player::getName() const
{
  const char* p = &name[0];
  return  p;
}


void Player::setTurn(int turn)
{
  this->turn = turn;
}

void Player::addScore(int score)
{
  this->score += score;
}

int Player::getScore() const
{
  return score;
}

int Player::getTurn() const
{
  return turn;
}

int Player::getWonGames() const
{
  return wonGames;
}

void Player::addWonGame()
{
  wonGames++;
}
