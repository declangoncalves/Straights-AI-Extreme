#include "Computer.h"

Computer::Computer() {
  type_ = 'c';
}

Computer::Computer(Player &player): Player(player) {}

Command Computer::makeMove(std::vector<Card> legalPlays) {
  Command my_command;
  if (legalPlays.size() > 0) {
    my_command = Command("play", legalPlays[0]);
  }
  else {
    my_command = Command("discard", hand_[0]);
  }
  return my_command;
}
