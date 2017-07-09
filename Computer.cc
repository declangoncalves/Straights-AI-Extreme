#include "Computer.h"


Computer::Computer() {
  type_ = 'c';
}

Computer::Computer(Player &player): Player(player) {};
