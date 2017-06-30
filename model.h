#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#incude "Deck.h"

class Model : public Subject {
  public:
  Model(int seed);
  void setupPlayers();
  void initializeRound();
  void endRound();
  void incrementPlayerTurn();
  void playCard(string card);
  void discardCard(string card);
  void printDeck();
  void rageQuit();
  std::vector<Cards> getPlayerHand();
  std::vector<Cards> getLegalPlays();


  void nextRound();
  ~Model();

  private:
	Deck deck_;
  Command command_;
  std::vector<Player> players_;
  std::vector<std::vector<int> > table_;
  int playerturn_;
  int seed_;

}; // Model


#endif
