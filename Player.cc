#include <iostream>
#include <algorithm>
#include "Player.h"
using namespace std;

Player::Player(): type_{'c'} {}

Player::Player(const Player &player) : hand_(player.hand_), discards_(player.discards_), roundscore_{player.roundscore_}, totalscore_{player.totalscore_}, type_{'c'} {}

const std::vector<Card> Player::getHand() { // Returns the hand vector
	return hand_;
}

Command Player::makeMove() {}

const std::vector<Card> Player::getDiscards() { // Returns the discard vector
	return discards_;
}

const char Player::getType() {
	return type_;
}

const int Player::getRoundScore() { // Returns player score
	return roundscore_;
}

void Player::rageQuit() {
	return;
}

const int Player::getTotalScore() { // Returns player score
	return totalscore_;
}

void Player::setRoundScore(int score) { // Sets player score
	roundscore_ = score;
}

void Player::setTotalScore(int score) { // Sets player score
	totalscore_ = score;
}

void Player::emptyHand() { // Used to completely empty hand / discards
	discards_.clear();
}

void Player::dealCard(Card c) { // Insert Card into hand
	hand_.push_back(c);
}

void Player::discard(Card c) { // Remove from hand / add to discards
	discards_.push_back(c);
	hand_.erase(std::remove(hand_.begin(), hand_.end(), c), hand_.end());
}

void Player::play(Card c) { // Remove from hand
	hand_.erase(std::remove(hand_.begin(), hand_.end(), c), hand_.end());
}

// Helper Functions

int Player::getCardIndex(Card c) { // Returns index of card in hand

	for (int i = 0; i < hand_.size(); i++) {
		if ((hand_.at(i).rank().rank() == c.rank().rank()) && (hand_.at(i).suit().suit() == c.suit().suit())){
			return i;
		}
	}

	// Throw Exception (Not Found)
}
