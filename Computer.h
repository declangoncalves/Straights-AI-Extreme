#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include "Command.h"

class Computer : public Player {
public:
  Computer();
  Computer(Player &player);
  Command makeMove(std::vector<Card> legalPlays);
};

#endif
