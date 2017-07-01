#ifndef MVC_MODEL_H
#define MVC_MODEL_H

#include "subject.h"
#include "Deck.h"
#include "player.h"

class Model : public Subject {
  public:
  Model(int seed = 0, std::vector<char> players = {'c', 'c', 'c', 'c'});
  void initializeRound();
  void playCard(Card);
  void discardCard(Card);
  void rageQuit();
  const Player getCurrentPlayer();
  const int getCurrentPlayerIndex();
  const int getConsecutiveDiscards();
  const int checkScore();
  const std::vector<std::vector<int> > getCardTable();
  const std::vector<std::vector<int> > getIntTable();
  const std::vector<Card> getPlayerHand();
  const std::vector<Card> getLegalPlays();
  const std::vector<Card> getDeck();


  void nextRound();
  ~Model();

  private:
  void endRound();
  void incrementPlayerTurn();
  void incrementPlayerTurn();
	Deck deck_;
  std::vector<Player> players_;
  std::vector<std::vector<int> > intstable_;
  std::vector<std::vector<Card> > cardstable_;
  int playerturn_;
  int discards_;
  int seed_;

}; // Model


#endif
