#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
	public:
		std::vector<Card> getHand();
		std::vector<Card> getDiscards();
		void discard(int card);
		void play(int card);

		int getScore();
		void setScore(int score);

	private:
		std::vector<Card> hand_;
		std::vector<Card> discards_;
		int score_;

}; // Player

#endif
