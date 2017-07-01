#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
	public:
		Deck(int seed = 0);
		Card getCard(int);
		std::vector<Card> getDeck();
		void shuffle();

	private:
		std::vector<Card> deck_;
		int seed_;

}; // Deck

#endif
