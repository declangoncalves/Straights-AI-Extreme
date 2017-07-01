#include "Card.h"
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(char type) : type_{type} {}

Player::Player() : type_{'h'} {}

char Player::getType() { // Returns the type of player: 'h' - human | 'c' - computer
	return type_;
}

std::vector<Card> Player::getHand() { // Returns the hand vector
	return hand_;
}

std::vector<Card> Player::getDiscards() { // Returns the discard vector
	return discards_;
}

int Player::getRoundScore() { // Returns player score
	return roundscore_;
}

int Player::getTotalScore() { // Returns player score
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

void Player::rageQuit() {
	type_ = 'c';
	return;
}

void Player::dealCard(Card c) { // Insert Card into hand
	hand_.push_back(c);
}

void Player::discard(Card c) { // Remove from hand / add to discards
	discards_.push_back(c);
	hand_.erase(std::remove(hand_.begin(), hand_.end(), c), hand_.end());
	cout << hand_.size() << "size" << endl;
}

void Player::play(Card c) { // Remove from hand
	cout << "Card Index: " << getCardIndex(c) << endl;
	hand_.erase(std::remove(hand_.begin(), hand_.end(), c), hand_.end());
	cout << hand_.size() << "size" << endl;
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
