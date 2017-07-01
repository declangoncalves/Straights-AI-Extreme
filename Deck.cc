#include <random>
#include "Deck.h"

void Deck::shuffle() {
	static std::mt19937 rng(seed); // Seed = 0

	int n = 52;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card c = deck_[n];
		deck_[n] = deck_[k];
		deck_[k] = c;
	} // while
} // shuffle

std::vector<Card> Deck::getDeck() {
	return deck_;
}
