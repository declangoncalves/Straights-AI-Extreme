/*
 * Represents a Card with a Suit {Club, Diamond, Heart, Spade} and a Rank
 * {Ace, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K}.
 *
 *  Last updated: 2017-06-06
 *  Copyright 2017 UW. All rights reserved.
 *
 */

#ifndef _CARD_
#define _CARD_
#include <iostream>

class Card {
public:
	// Note that we're not using "explicit" on the Rank/Suit constructors so that we can
	// buy the integer comparison and arithmetic operations for cheap. Default copy/move
	// and assignment operations are fine.

    class Suit {
    public:
    	static const int MAX_SUIT = 4; // Maximum # of suits available for a card
		static const int CLUB = 1;    // Suit index associated with Clubs
		static const int DIAMOND = 2;    // Suit index associated with Diamonds
		static const int HEART = 3;    // Suit index associated with Hearts
		static const int SPADE = 4;    // Suit index associated with Spades

    	Suit( int s );
    	// Throws: "Invalid suit" if s < 0 || s >= MAX_SUIT
    	// Modifies: this

    	int suit() const;
    	// Returns: 0 <= suit < MAX_SUIT where 0 = C, 1 = D, 2 = H, 3 = S

    private:
    	int suit_;
    };

    class Rank {
    public:
    	static const int MAX_RANK = 13; // Maximum # of card ranks (face values)
		static const int ACE = 1;     // Rank index associated with the ACE
		static const int TWO = 2;     // Rank index associated with the 2
		static const int THREE = 3;     // Rank index associated with the 3
		static const int FOUR = 4;     // Rank index associated with the 4
		static const int FIVE = 5;     // Rank index associated with the 5
		static const int SIX = 6;     // Rank index associated with the 6
		static const int SEVEN = 7;     // Rank index associated with the 7
		static const int EIGHT = 8;     // Rank index associated with the 8
		static const int NINE = 9;     // Rank index associated with the 9
		static const int TEN = 10;     // Rank index associated with the 10
		static const int JACK = 11;     // Rank index associated with the Jack
		static const int QUEEN = 12;     // Rank index associated with the Queen
		static const int KING = 13;     // Rank index associated with the King

    	Rank( int r );
    	// Throws: "Invalid rank" if r < 0 || r >= MAX_RANK
    	// Modifies: this

    	int rank() const;
    	// Returns: 0 <= rank < MAX_RANK

    private:
    	int rank_;
    };

	Card( Rank, Suit );
	Suit suit() const;
	Rank rank() const;
	bool operator==( const Card & ) const;

private:
	Suit suit_;
	Rank rank_;
};

// Card I/O in the format <rank><suit>
std::ostream & operator<<( std::ostream &, const Card & );
std::istream & operator>>( std::istream &, Card & );
std::ostream & operator<<( std::ostream &, const Card::Rank & );
std::istream & operator>>( std::istream &, Card::Rank & );
std::ostream & operator<<( std::ostream &, const Card::Suit & );
std::istream & operator>>( std::istream &, Card::Suit & );

#endif
