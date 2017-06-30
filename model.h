#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#incude "Deck.h"

class Model : public Subject {
  public:
  Model(int seed);
  void setupPlayers();
  void getCommand();
  void performCommand();
  void nextRound();
  ~Model();

  private:
	Deck deck_;
  Command command_;
  std::vector<Player> players_;
  std::vector<std::vector<int> > table_;
  int seed_;

}; // Model


#endif
