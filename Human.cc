#include "Human.h"

Human::Human() {
  type_ = 'h';
}

Command Human::makeMove(std::vector<Card> legalPlays) {
  Command c;
  c.type = Command::Type::CLICK;
  return c;
}
