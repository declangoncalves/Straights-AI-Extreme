#include "Computer.h"

Computer::Computer() {
  type_ = 'c';
}

Computer::Computer(Player &player): Player(player) {}

Command Computer::makeMove(std::vector<Card> legalPlays) {
  Command my_command;
  command.type = Command::Type::COMPUTER
  return my_command;
}
