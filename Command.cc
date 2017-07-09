#include "Command.h"
#include <cassert>
#include <sstream>
using std::istream;
using std::string;
using std::stringstream;

Command::Command() : type{Command::Type::BAD_COMMAND}, card{Card::Rank{0}, Card::Suit{0}} {}

Command::Command(std::string cmd, Card c) : type{Command::Type::BAD_COMMAND}, card{Card::Rank{0}, Card::Suit{0}} {

	if ( cmd == "play" ) {
		type = Command::Type::PLAY;
		card = c;
	} else if ( cmd == "discard" ) {
		type = Command::Type::DISCARD;
		card = c;
	} else if ( cmd == "deck" ) {
		type = Command::Type::DECK;
	} else if ( cmd == "quit" ) {
		type = Command::Type::QUIT;
	} else if ( cmd == "ragequit" ) {
		type = Command::Type::RAGEQUIT;
	} // if
}


istream & operator>>( istream & in, Command & c ) {
	c.type = Command::Type::BAD_COMMAND;

	string str;
	getline( in, str );
	stringstream ss{ str };

	string cmd;
	ss >> cmd;

	if ( cmd == "play" ) {
		c.type = Command::Type::PLAY;
		ss >> c.card;
	} else if ( cmd == "discard" ) {
		c.type = Command::Type::DISCARD;
		ss >> c.card;
	} else if ( cmd == "deck" ) {
		c.type = Command::Type::DECK;
	} else if ( cmd == "quit" ) {
		c.type = Command::Type::QUIT;
	} else if ( cmd == "ragequit" ) {
		c.type = Command::Type::RAGEQUIT;
	} // if

	assert( !in.fail() && !ss.fail() && c.type != Command::Type::BAD_COMMAND );

	return in;
} // operator>>
