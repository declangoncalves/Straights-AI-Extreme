#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include "Deck.h"
#include "player.h"

class Model : public Subject {
  public:
  Model(int seed, std::vector<char> players);
  void initializeRound();
  void endRound();

  void incrementPlayerTurn();
  void playCard(Card);
  void discardCard(Card);
  void printDeck();
  void rageQuit();
  const Player getCurrentPlayer();
  const int getCurrentPlayerIndex();
  const std::vector<std::vector<int> > getCardTable();
  const std::vector<std::vector<int> > getIntTable();
  const std::vector<Card> getPlayerHand();
  const std::vector<Card> getLegalPlays();


  void nextRound();
  ~Model();

  private:
	Deck deck_;
  std::vector<Player> players_;
  std::vector<std::vector<int> > intstable_;
  std::vector<std::vector<Card> > cardstable_;
  int playerturn_;
  int seed_;

}; // Model


#endif
