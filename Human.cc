#include "Human.h"

Human::Human() {
  type_ = 'h';
}

Command Human::makeMove() {
  Command c;
  c.type = Command::Type::NOTHING;
  return c;
}
