#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
	public:
		std::vector<Card> getHand();
		void discard(int card);
		int getScore();
		void setScore(int score);

	private:
		std::vector<Card> hand_;
		int score_;

}; // Player

#endif