#include "model.h"
#include "Human.h"
#include "Computer.h"
#include <algorithm>

using namespace std;

Model::Model() : intstable_(4, std::vector<int>(15, 0)) , cardstable_(4, std::vector<Card>(15)) {}

void Model::startGame(int seed, std::vector<char> players) {
  for (int i = 0; i < 4; i++) {
    if (players[i] == 'c') {
      Computer *a = new Computer();
      players_.push_back(a);
    }
    else {
      Human *a = new Human();
      players_.push_back(a);
    }
  }
  deck_ = Deck(seed);
  initializeRound();
  cout << "initializing round worked" << endl;
}

void Model::restartGame(int seed) {
  deck_ = Deck(seed);
  for (player : players_) {
    player->setRoundScore(0);
    player->setTotalScore(0);
    player->emptyHand();
  }
  for (auto& sub : intstable_) {
    std::fill(sub.begin(), sub.end(), 0);
  }
  for (auto& sub : cardstable_) {
    std::fill(sub.begin(), sub.end(), Card());
  }
  initializeRound();
}

const std::vector<std::vector<Card> > Model::getCardTable() {
  return cardstable_;
}

const std::vector<std::vector<int> > Model::getIntTable() {
  return intstable_;
}

std::vector<int> Model::getPlayerScores() {
  std::vector<int> scores;
  for (auto player : players_) {
    scores.push_back(player->getTotalScore());
  }
  return scores;
}

std::vector<vector<Card> > Model::getAllDiscards() {
  std::vector<vector<Card> > retv;
  for (int i = 0; i < 4; i++) {
    std::vector<Card> items;
    retv.push_back(items);
    for (card : players_[i]->getDiscards()) {
      retv[i].push_back(card);
    }
  }
  return retv;
}

std::vector<int> Model::getPlayerDiscards() {
  std::vector<int> discards;
  for (auto player : players_) {
    discards.push_back(player->getDiscards().size());
  }
  return discards;
}

std::vector<int> Model::getPlayerRoundScores() {
  std::vector<int> scores;
  for (auto player : players_) {
    scores.push_back(player->getRoundScore());
  }
  return scores;
}

const int Model::getCurrentPlayerIndex() {
  return playerturn_;
}

void Model::rageQuit() {
  Computer *replacement = nullptr;
  int i = getCurrentPlayerIndex();
  replacement = new Computer(*(players_[i]));
  delete players_[i];
  players_[i] = replacement;
  computerMove();
}

void Model::pickChoice(Card c) {
  cout << "Card being played : " << c << endl;
  vector<Card> plays = getLegalPlays();
  if (plays.size() == 0) {
    discardCard(c);
    return;
  }
  else {
    if (find(plays.begin(), plays.end(), c) !=  plays.end()) {
      playCard(c);
    }
    else {
      return;
    }
  }
}

// void Model::computerMove() {
//   std::vector<Card> legal = getLegalPlays();
//   std::vector<Card> hand = getCurrentPlayer()->getHand();
//   if (legal.size() == 0) {
//     discardCard(hand[0]);
//   }
//   else {
//     playCard(legal[0]);
//   }
//   return;
// }

void Model::computerMove() {
  std::vector<Card> legal = getLegalPlays();
  std::vector<Card> hand = getCurrentPlayer()->getHand();
  if (legal.size() == 0) {
    int min = hand[0].rank().rank();
    int index = 0;
    for (int i = 0; i < hand.size(); i++) {
      if (hand[i].rank().rank() <= min) {
        min = legal[i].rank().rank();
        index = i;
      }
    }
    discardCard(hand[index]);
  }
  else {
    int min = legal[0].rank().rank();
    int index = 0;
    for (int i = 0; i < legal.size(); i++) {
      if (legal[i].rank().rank() == 6) continue;
      if (legal[i].rank().rank() <= min) {
        min = legal[i].rank().rank();
        index = i;
      }
    }
    playCard(legal[index]);
  }
  return;
}

Command Model::getPlayerMove() {
  return getCurrentPlayer()->makeMove();
}

char Model::getCurrentPlayerType() {
  return getCurrentPlayer()->getType();
}

void Model::incrementPlayerTurn() {
  cout << "Player's turn: " << playerturn_ << endl;
  if (emptyhands_ == 4) {
    endRound();
    return;
  }
  const int max_index = 3;
  playerturn_++;
  if (playerturn_ > max_index) playerturn_ = 0;
  while (players_[playerturn_]->getHand().size() == 0) {
    playerturn_++;
    if (playerturn_ > max_index) playerturn_ = 0;
  }
  notify();
  return;
}

Player* Model::getCurrentPlayer() {
  return (players_[playerturn_]);
}

const std::vector<Card> Model::getLegalPlays() {
  std::vector<Card> plays;
  for (auto card : players_[getCurrentPlayerIndex()]->getHand()) {
    int suit = card.suit().suit();
    int rank = card.rank().rank();
    if ((intstable_[suit][rank] == 1 || intstable_[suit][rank + 2] == 1) || (rank == 6)) {
      plays.push_back(card);
    }
    if (suit == 3 && rank == 6) {
      std::vector<Card> single_play;
      single_play.push_back(card);
      return single_play;
    }
  }
  return plays;
}

const std::vector<Card> Model::getPlayerHand() {
  std::vector<Card> hand;
  for (auto card : players_[getCurrentPlayerIndex()]->getHand()) {
    hand.push_back(card);
  }
  return hand;
}

const int Model::getGameState() {
  // 1 = Round has ended 2 = Game has ended
  return gamestate_;
}

void Model::initializeRound() {
  cout << "New Round is Initializing" << endl;
  gamestate_ = 0;
  playerturn_ = 0;
  emptyhands_ = 0;
  deck_.shuffle();
  for (auto player : players_) {
    player->emptyHand();
  }
  cout << "Emptying hand worked" << endl;
  for (int j = 0; j < players_.size(); j++) {
    for (int i = 0; i < 13; i ++) {
      players_[j]->dealCard(deck_.getCard(i + 13*j));
    }
  }
  cout << "dealing cards worked" << endl;
  for (int i = 0; i < players_.size(); i++) {
    for (auto card : players_[i]->getHand()) {
      if (card.suit().suit() == 3 && card.rank().rank() == 6) playerturn_ = i;
    }
  }
  cout << "picking the player turn worked" << endl;
  notify();
  cout << "notify worked" << endl;
}

const int Model::calculateWinner() {
  int player = 0;
  int max = 0;
  for (int i = 0; i < players_.size(); i++) {
    if ((players_[i]->getTotalScore()) >= max) {
      max = players_[i]->getTotalScore();
      player = i;
    }
  }
  return player;
}

void Model::endRound() {
  cout << "ROUND ENDING HAS BEGUN";
  gamestate_ = 1;
  std::vector<int> scores;
  for (auto player : players_) {
    for (auto card : player->getDiscards()) {
      player->setRoundScore(player->getRoundScore() + (card.rank().rank() + 1));
    }
    player->setTotalScore(player->getTotalScore() + player->getRoundScore());
  }
  for (auto player : players_) {
    if (player->getTotalScore() >= 80) gamestate_ = 2;
  }
  for (int i = 0; i < intstable_.size(); i++) {
    for (int j = 0; j < intstable_[i].size(); j++) {
      intstable_[i][j] = 0;
    }
  }
  notify();
}

Model::~Model() {}

const std::vector<Card> Model::getCurrentPlayerHand() {
  return getCurrentPlayer()->getHand();
}

void Model::playCard(Card c) {
  int suit = c.suit().suit();
  int rank = c.rank().rank();
  players_[getCurrentPlayerIndex()]->play(c);
  intstable_[suit][rank + 1] = 1;
  cardstable_[suit][rank + 1] = c;
  if (players_[getCurrentPlayerIndex()]->getHand().size() == 0) emptyhands_++;
  incrementPlayerTurn();
  return;
}

void Model::discardCard(Card c) {
  int suit = c.suit().suit();
  int rank = c.rank().rank();
  players_[getCurrentPlayerIndex()]->discard(c);
  if (players_[getCurrentPlayerIndex()]->getHand().size() == 0) emptyhands_++;
  incrementPlayerTurn();
  return;
}

const std::vector<Card> Model::getDeck() {
  return deck_.getDeck();
}
