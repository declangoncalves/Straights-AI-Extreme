#include <random>
#include "Deck.h"
#include <iostream>

using namespace std;

Deck::Deck(int seed) {
	seed_ = seed;
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < 13; j ++) {
			Card::Suit s(i);
			Card::Rank r(j);
		 	Card c(r, s);
			deck_.push_back(c);
		}
	}
	// shuffle();
}

Card Deck::getCard(int i) {
	return deck_[i];
}

void Deck::shuffle() {
	static mt19937 rng(seed_);

	int n = 52;

	while ( n > 1 ) {
		int k = (int) (rng() % n);
		--n;
		Card c = deck_[n];
		deck_[n] = deck_[k];
		deck_[k] = c;
	} // while
} // shuffle

vector<Card> Deck::getDeck() {
	return deck_;
}
