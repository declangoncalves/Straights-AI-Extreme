#include "model.h"

Model::Model(int seed = 0, std::vector<char> players = {'c', 'c', 'c', 'c'}) : deck_(new Deck(seed)) , table_(4, std::vector<int>(15, nullptr)) , table_(4, std::vector<Card>(15)), seed_(seed) {}

vector<vector<Card> > Model::getCardTable() {
  return cardstable_;
}

vector<vector<int> > Model::getIntTable() {
  return intstable_;
}


int Model::getCurrentPlayerIndex() {
  return playerturn_;
}

const std::vector<Player> Model::getPlayers() {
  return players_;
}

void Model::incrementPlayerTurn() {
  const int max_index = 3;
  playerturn_++;
  if (playerturn > max_index) playerturn_ = 0;
  return;
}

int Model::getCurrentPlayer() {
  return players_[playerturn_];
}

std::vector<Card> Model::getLegalPlays() {
  std::vector<Card> plays;
  for (auto card : getCurrentPlayer().getHand()) {
    int suit = card.suit().suit();
    int rank = card.rank().rank();
    if (intstable_[suit + 1][rank] == 1 || table_[suit + 1][rank + 2] == 1) {
      plays.push(card);
    }
  }
  return plays;
}

std::vector<Card> Model::getPlayerHand() {
  std::vector<Card> hand;
  for (auto card : getCurrentPlayer().getHand()) {
    hand.push(card);
  }
  return hand;
}

void Model::checkEmptyHand() {
    if (getCurrentPlayer().getHand().size() == 0) emptyhands_++;
    if (emptyhands_ == 4) endRound();
}

void Model::getRoundFlag() {
  // 1 = Round has ended 2 = Game has ended
  return gamestate_;
}

void Model::initializeRound() {
  roundflag_ = 0;
}

void Model::endRound() {
  roundflag_ = 1;
  vector<int> scores;
  for (auto player : players_) {
    for (auto card : player.getDiscards()) {
      
    }
  }
}

void Model::playCard(Card c) {
  int suit = c.suit().suit();
  int rank = card.rank().rank();
  getCurrentPlayer().playCard(c);
  intstable_[suit + 1][rank + 1] = 1;
  cardstable_[suit + 1][rank + 1] = c;
  incrementPlayerTurn();
  emptyhands_ = 0;
  return;
}

void Model::discardCard(Card c) {
  int suit = c.suit().suit();
  int rank = card.rank().rank();
  getCurrentPlayer().discardCard(c);
  incrementPlayerTurn();
  return;
}

void Model::printDeck() {
  for (auto card : deck_) {
    cout  << " " << card << endl;
  }
}
