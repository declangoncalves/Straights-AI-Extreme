#include "Computer.h"


Computer::Computer() {
  type_ = 'c';
}

void Computer::rageQuit() {
  return;
}

Computer::Computer(Player &player) {
  hand_ = player.getHand();
  discards_ = player.getDiscards();
  roundscore_ = player.getRoundScore();
  totalscore_ = player.getTotalScore();
  type_ = 'c';
}
