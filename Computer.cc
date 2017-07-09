<<<<<<< HEAD
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
=======
#include "Computer.h"


Computer::Computer() {
  type_ = 'c';
}

void Computer::rageQuit() {
  return;
}

Computer::Computer(Player &player) Player(player) {}
>>>>>>> 4efe06ff382fe91538c7ae1836433ecb892912f8
