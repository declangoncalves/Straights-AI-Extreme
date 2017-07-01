#include "Card.h"
#include "Player.h"

// Player::Player(char type) : type_{type} {}
//
// Player::Player() : type_{'h'} {}

char getType() { // Returns the type of player: 'h' - human | 'c' - computer
	return type_;
}

std::vector<Card> getHand() { // Returns the hand vector
	return hand_;
}

std::vector<Card> getDiscards() { // Returns the discard vector
	return discards_;
}

int getRoundScore() { // Returns player score
	return roundscore_;
}

int getTotalScore() { // Returns player score
	return totalscore_;
}

void setRoundScore(int score) { // Sets player score
	roundscore_ = score;
}

void setTotalScore(int score) { // Sets player score
	totalscore_ = score;
}

void emptyHand() { // Used to completely empty hand / discards
	discards_.clear();
}

void rageQuit() {
	type_ = 'c';
	return;
}

void dealCard(Card c) { // Insert Card into hand
	hand_.push_back(c);
}

void discard(Card c) { // Remove from hand / add to discards
	discards_.push_back(c);
	hand_.erase(hand_.begin() + getCardIndex(c));
}

void play(Card c) { // Remove from hand
	hand_.erase(hand_.begin() + getCardIndex(card));
}

// Helper Functions

int getCardIndex(Card c) { // Returns index of card in hand

	for (int i = 0; i < hand_.size(); i++) {
		if ((hand_.at(i).rank().rank() == c.rank().rank()) && (hand_.at(i).suit().suit() == c.suit().suit())){
			return i;
		}
	}

	// Throw Exception (Not Found)
}
