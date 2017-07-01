#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>
#include <string>

class Player {
	public:
		Player();
		Player(char type);
		char getType(); // Returns the type of player: 'h' - human | 'c' - computer

		std::vector<Card> getHand(); // Returns the hand vector
		std::vector<Card> getDiscards(); // Returns the discard vector

		void dealCard(Card c); // Insert Card into hand
		void rageQuit(); // ragequit method to turn it into a computer

		void discard(Card c); // Remove from hand / add to discards
		void play(Card c); // Remove from hand

		int getRoundScore(); // Returns player score
		int getTotalScore(); // Returns player score
		void setRoundScore(int score); // Sets player score
		void setTotalScore(int score); // Sets player score

		// Helper Functions
		int getCardIndex(Card c); //  Returns index of card in hand

		// TODO: Check for certain card

	private:
		void emptyHand(); // Used to completely empty hand / discards
		std::vector<Card> hand_;
		std::vector<Card> discards_;
		int roundscore_;
		int totalscore_;
		char type_;

}; // Player

#endif