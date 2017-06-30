#include <random>

void Deck::shuffle() {
	static mt19937 rng(0); // Seed = 0

	int n = CARD_COUNT;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	} // while
} // shuffle
