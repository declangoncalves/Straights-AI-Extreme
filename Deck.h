#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
	public:
		Deck(int seed = 0);
		std::vector<Card> getDeck();
		void shuffle();

	private:
		std::vector<Card> deck_;
		int seed;

}; // Deck

#endif
