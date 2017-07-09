#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

class Computer : public Player {
public:
  Computer();
  Computer(Player &player);
  void rageQuit() override;
};

#endif
