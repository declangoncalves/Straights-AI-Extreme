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

int getScore() { // Returns player score
	return score;
}

void setScore(int s) { // Sets player score
	score = s;
}

void emptyHand() { // Used to completely empty hand / discards
	hand_.clear();
}

void dealCard(Card c) { // Insert Card into hand
	hand_.push_back(c);
}

void discard(string card) { // Remove from hand / add to discards
	discards_.push_back(hand_.at(getCardIndex(card)));
	hand_.erase(hand_.begin() + getCardIndex(card));
}

void play(string card) { // Remove from hand
	hand_.erase(hand_.begin() + getCardIndex(card));
}

// Helper Functions

int getCardIndex(string card) { // Returns index of card in hand

	int rank = 0;
	int suit = 0;

	switch (card[0]) {
	case 'A':	rank = 1;
		break;
	case '2':	rank = 2;
		break;
	case '3':	rank = 3;
		break;
	case '4':	rank = 4;
		break;
	case '5':	rank = 5;
		break;
	case '6':	rank = 6;
		break;
	case '7':	rank = 7;
		break;
	case '8':	rank = 8;
		break;
	case '9':	rank = 9;
		break;
	case '10':	rank = 10;
		break;
	case 'J':	rank = 11;
		break;
	case 'Q':	rank = 12;
		break;
	case 'K':	rank = 13;
		break;
	case default:
		// Throw Exception
	}

	switch (card[1]) {
	case 'C':	suit = 1;
		break;
	case 'D':	suit = 2;
		break;
	case 'H':	suit = 3;
		break;
	case 'S':	suit = 4;
		break;
	case default:
		// Throw Exception
	}

	for (int i = 0; i < hand_.size(); i++) {
		if ((hand_.at(i).rank() == rank) && (hand_.at(i).suit() == suit)){
			return i;
		}
	}

	// Throw Exception (Not Found)
}