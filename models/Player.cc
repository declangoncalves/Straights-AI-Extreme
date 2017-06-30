#include "Card.h"

char getType() { // Returns the type of player: 'h' - human | 'c' - computer
	return type_;
}

std::vector<Card> getHand() { // Returns the hand vector
	return hand_;
}

std::vector<Card> getDiscards() { // Returns the discard vector
	return discards_;
}

void emptyHand() { // Used to completely empty hand / discards
	hand_.clear();
} 

void dealCard(Card c) { // Insert Card into hand
	hand_.push_back(c);
}

void discard(string card) { // Remove from hand / add to discards

}

void play(string card); // Remove from hand

int getScore(); // Returns player score

void setScore(int score); // Sets player score