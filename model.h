#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#incude "Deck.h"

class Model : public Subject {
  public:
  Model();
  ~Model();

  private:
	Deck deck_;
  Command command_;
  std::vector<Player> players_;
  std::vector<std::vector<> table_;

}; // Model


#endif
