#include "model.h"

Model::Model(int seed) : deck_(new Deck(seed)) : table_(4, std::vector<Card*>(15, nullptr)) {}
Model::Model(int seed) : deck_(new Deck(seed)) : table_(4, std::vector<Card*>(15, nullptr)) {}

void Model::playCard(string card) {


}

int Model::getCurrentPlayerIndex() {
  return playerturn_;
}

int Model::getCurrentPlayer() {
  return players_[playerturn_];
}

std::vector<Card> Model::getLegalPlays() {
  std::vector<Card> plays;
  for (auto card : getCurrentPlayer().getHand()) {
    int suit = card.suit().suit();
    int rank = card.rank().rank();
    if (table_[suit - 1][rank - 1] == 1 || table_[suit - 1][rank + 1] == 1) {
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

void Model::playCard(Card c) {
  int suit = c.suit().suit();
  int rank = card.rank().rank();
  getCurrentPlayer().playCard(c);
  table_[suit][rank] = 1;
  return;
}

void Model::discardCard(Card c) {
  int suit = c.suit().suit();
  int rank = card.rank().rank();
  getCurrentPlayer().discardCard(c);
  return;
}

void Model::printDeck() {
  for (auto card : deck_) {

  }
}
