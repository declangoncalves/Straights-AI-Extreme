#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
	public:
		Deck(int seed = 0);
		std:vector<Card> getDeck();
		void shuffle(int seed = 0);

	private:
		std::vector<Card> deck;

}; // Deck

#endif
