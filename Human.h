#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include "Command.h"
#include <iostream>

class Human : public Player {
public:
  Human();
  Command makeMove();
};

#endif
