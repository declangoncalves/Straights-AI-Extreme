#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "Card.h"
#include <iostream>


View::View(Controller* c, Model* m) {
	controller_ = c;
	model_ = m;
}

View::~View() {}

void update() override {

	if (gamePhase == 1) { // Start Round
		roundStart();
	}

	else if (gamePhase == 3) { // Start new round
		gamePhase = 1;
		roundEnd();
	}

	else {
		playerTurn();
	}
}

void roundStart() {
	cout << "A	new	round	begins.	It’s	player	" << model_->getCurrentPlayerIndex() + 1 << "’s	turn	to	play.\n";
	gamePhase = 2;
	playerTurn();
}

void playerTurn() {
	std::vector<Cards> cardTable = model->getCardTable();
	std::vector<int> intTable = model->getIntTable();
	std::vector<int> legalPlays = model->getLegalPlays();

	cout << "Cards	on	the	table:\n";
	cout << "\nClubs:";
	printClubs();
	cout << "\nDiamonds:";
	printDiamonds();
	cout << "\nHearts:";
	printHearts();
	cout << "\nSpades:";
	printSpades();
	cout << "\nYour	hand:"
	printPlayerHand(cardTable, intTable);
	cout << "\nLegal	plays:"
	printLegalPlays(legalPlays);

}

// Print Legal Plays
void printLegalPlays(std::vector<Cards> legalPlays) {
	for (int i = 0; i < legalPlays.size(); i++) {
		cout << legalPlays[i];
	}
}

// Print Player Hand
void printPlayerHand(std::vector<Cards> cardTable, std::vector<Cards> intTable) {
	Player p = model->getCurrentPlayer();
	for (int i = 0; i < p.getHand().size(); i++) {
		cout << p[i];
	}
}

// Print Clubs
void printClubs(std::vector<Cards> cardTable, std::vector<Cards> intTable) {
	for (int i = 1; i < 14; i++) {
		if (intTable[0][i] == 1) {
			cout << rankToLetter(cardTable[0][i].rank());
		}
	}
}

// Print Diamonds
void printDiamonds(std::vector<Cards> cardTable, std::vector<Cards> intTable) {
	for (int i = 1; i < 14; i++) {
		if (intTable[1][i] == 1) {
			cout << rankToLetter(cardTable[0][i].rank());
		}
	}
}

// Print Hearts
void printHearts(std::vector<Cards> cardTable, std::vector<Cards> intTable) {
	for (int i = 1; i < 14; i++) {
		if (intTable[2][i] == 1) {
			cout << rankToLetter(cardTable[0][i].rank());
		}
	}
}

// Print Spades
void printSpades(std::vector<Cards> cardTable, std::vector<Cards> intTable) {
	for (int i = 1; i < 14; i++) {
		if (intTable[3][i] == 1) {
			cout << rankToLetter(cardTable[0][i].rank());
		}
	}
}

// Return character rank
char rankToLetter(int rank) {
	switch (rank) {
	case 1: return 'A';
	case 10: return 'T';
	case 11: return 'J';
	case 12: return 'Q';
	case 13: return 'K';
	case default: return "" + rank;
	}
}

void roundEnd();