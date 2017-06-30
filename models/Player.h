#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
	public:
		char getType(); // Returns the type of player: 'h' - human | 'c' - computer

		std::vector<Card> getHand(); // Returns the hand vector
		std::vector<Card> getDiscards(); // Returns the discard vector

		void emptyHand(); // Used to completely empty hand / discards
		void dealCard(Card); // Insert Card into hand

		void discard(string card); // Remove from hand / add to discards
		void play(string card); // Remove from hand

		int getScore(); // Returns player score
		void setScore(int score); // Sets player score

		// TODO: Check for certain card

	private:
		std::vector<Card> hand_;
		std::vector<Card> discards_;
		int score_;
		char type;

}; // Player

#endif