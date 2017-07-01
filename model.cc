#include "model.h"
#include <algorithm>
#include <iostream>

using namespace std;

Model::Model(int seed, std::vector<Player> players) : deck_(Deck(seed)) , intstable_(4, std::vector<int>(15, 0)) , cardstable_(4, std::vector<Card>(15)), seed_{seed} , players_{players} {
  initializeRound();
}

const std::vector<std::vector<Card> > Model::getCardTable() {
  return cardstable_;
}

const std::vector<std::vector<int> > Model::getIntTable() {
  return intstable_;
}

const int Model::getCurrentPlayerIndex() {
  return playerturn_;
}

std::vector<Player> Model::getPlayers() {
  return players_;
}

void Model::rageQuit() {
  getCurrentPlayer().rageQuit();
}

void Model::incrementPlayerTurn() {
  if (emptyhands_ == 4) endRound();
  const int max_index = 3;
  playerturn_++;
  if (playerturn_ > max_index) playerturn_ = 0;
  while (players_[playerturn_].getHand().size() == 0) {
    playerturn_++;
    if (playerturn_ > max_index) playerturn_ = 0;
  }
  return;
}

Player Model::getCurrentPlayer() {
  return players_[playerturn_];
}

const std::vector<Card> Model::getLegalPlays() {
  std::vector<Card> plays;
  for (auto card : getCurrentPlayer().getHand()) {
    int suit = card.suit().suit();
    int rank = card.rank().rank();
    if ((intstable_[suit + 1][rank] == 1 || intstable_[suit + 1][rank + 2] == 1) || (rank == 6)) {
      plays.push_back(card);
    }
  }
  return plays;
}

const std::vector<Card> Model::getPlayerHand() {
  std::vector<Card> hand;
  for (auto card : getCurrentPlayer().getHand()) {
    hand.push_back(card);
  }
  return hand;
}

const int Model::getGameState() {
  // 1 = Round has ended 2 = Game has ended
  return gamestate_;
}

void Model::initializeRound() {
  gamestate_ = 0;
  playerturn_ = 0;
  emptyhands_ = 0;
  deck_.shuffle();
  for (int j = 0; j < players_.size(); j++) {
    for (int i = 0; i < 13; i ++) {
      players_[j].dealCard(deck_.getCard(i + 13*j));
    }
  }
  for (int i = 0; i < players_.size(); i++) {
    for (auto card : players_[i].getHand()) {
      if (card.suit().suit() == 0 && card.rank().rank() == 6) playerturn_ = i;
    }
  }
  notify();
}

void Model::endRound() {
  gamestate_ = 1;
  std::vector<int> scores;
  for (auto player : players_) {
    for (auto card : player.getDiscards()) {
      player.setRoundScore(player.getRoundScore() + (card.rank().rank() + 1));
    }
    player.emptyHand();
    player.setTotalScore(player.getTotalScore() + player.getRoundScore());
  }
  for (auto player : players_) {
    if (player.getTotalScore() >= 80) gamestate_ = 2;
  }
  notify();
}

Model::~Model() {}

void Model::playCard(Card c) {
  int suit = c.suit().suit();
  int rank = c.rank().rank();
  getCurrentPlayer().play(c);
  intstable_[suit + 1][rank + 1] = 1;
  cardstable_[suit + 1][rank + 1] = c;
  if (getCurrentPlayer().getHand().size() == 0) emptyhands_++;
  incrementPlayerTurn();
  cout << "notifying" << endl;
  notify();
}

void Model::discardCard(Card c) {
  int suit = c.suit().suit();
  int rank = c.rank().rank();
  getCurrentPlayer().discard(c);
  if (getCurrentPlayer().getHand().size() == 0) emptyhands_++;
  incrementPlayerTurn();
  notify();
}

const std::vector<Card> Model::getDeck() {
  return deck_.getDeck();
}
