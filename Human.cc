#include "Human.h"

Human::Human() {
  type_ = 'h';
}

Command Human::makeMove(std::vector<Card> legalPlays) {
  Command c;
  std::cin >> c;
  return c;
}
