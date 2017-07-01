#include "model.h"

Model::Model(int seed = 0, std::vector<Player> players) : deck_(new Deck(seed)) , intstable_(4, std::vector<int>(15, nullptr)) , cardstable_(4, std::vector<Card>(15)), seed_{seed} , players_{players}{}

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

void Model::rageQuit() {
  currentPlayer().rageQuit();
}

void Model::incrementPlayerTurn() {
  if (emptyhands_ == 4) endRound();
  const int max_index = 3;
  playerturn_++;
  if (playerturn > max_index) playerturn_ = 0;
  while (players_[playerturn_].getHand().size() == 0) {
    playerturn_++;
    if (playerturn > max_index) playerturn_ = 0;
  }
  return;
}

Player Model::getCurrentPlayer() {
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

void Model::getRoundFlag() {
  // 1 = Round has ended 2 = Game has ended
  return gamestate_;
}

void Model::initializeRound() {
  roundflag_ = 0;
  playerturn_ = 0;
  emptyhands_ = 0;
  deck_.shuffle();
  for (auto player: players_) {
    for (int i = 0; i < 13; i ++) {
      player.dealCard(deck_[i]);
    }
  }
  for (int i = 0; i < players_.size(); i++) {
    for (auto card : players[i].getHand()) {
      if (card.suit().suit() == 0 && card.rank().rank() == 6) playerturn_ = i;
    }
  }
  notify();
}

void Model::endRound() {
  roundflag_ = 1;
  vector<int> scores;
  for (auto player : players_) {
    for (auto card : player.getDiscards()) {
      player.setRoundScore(player.getRoundScore() += (card.rank().rank() + 1));
    }
    player.emptyHand();
    player.setTotalScore(player.getTotalScore() += player.getRoundScore());
  }
  for (auto player : players_) {
    if (player.getTotalScore() >= 80) roundflag_ = 2;
  }
  notify();
}

void Model::playCard(Card c) {
  int suit = c.suit().suit();
  int rank = card.rank().rank();
  getCurrentPlayer().playCard(c);
  intstable_[suit + 1][rank + 1] = 1;
  cardstable_[suit + 1][rank + 1] = c;
  if (getCurrentPlayer().getHand().size() == 0) emptyhands_++;
  incrementPlayerTurn();
  notify();
  return;
}

void Model::discardCard(Card c) {
  int suit = c.suit().suit();
  int rank = card.rank().rank();
  getCurrentPlayer().discardCard(c);
  if (getCurrentPlayer().getHand().size() == 0) emptyhands_++;
  incrementPlayerTurn();
  notify();
  return;
}

void Model::printDeck() {
  for (auto card : deck_) {
    cout  << " " << card << endl;
  }
}
