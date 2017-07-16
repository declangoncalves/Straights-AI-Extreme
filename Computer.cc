#include "Computer.h"

Computer::Computer() {
  type_ = 'c';
}

Computer::Computer(Player &player): Player(player) {}

Command Computer::makeMove() {
  Command my_command;
  my_command.type = Command::Type::COMPUTER;
  return my_command;
}
