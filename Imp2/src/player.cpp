#include "player.h"
#include <iostream>
#include <cstring>
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

std::ostream& operator<<(std::ostream& os, const Player& player)
{
  if(os)
  {
    for(int i = 0; player.name[i]!= 0; i++) os << player.name[i];
    os << std::endl;
    os << player.score << " " << player.turn << " " << player.wonGames << std::endl;

  }
  return os;
}

std::istream& operator >>( std::istream& is, Player& player)
{
  if(is)
  {
    while(isspace(is.peek())) is.ignore();
    char aux[100];
    is.getline(aux,100,'\n');
    player.name = new char[strlen(aux)+1];
    for(unsigned int i = 0; i < strlen(aux)+1; i++)
    {
      player.name[i] = aux[i];
    }
    is >> player.score >> player.turn >> player.wonGames;
  }
  return is;
}
