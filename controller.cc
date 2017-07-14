#include "controller.h"
#include <iostream>
#include "model.h"

using namespace std;

Controller::Controller( Model *m ) : model_{m} {}

void Controller::newRound() {
	model_->initializeRound();
}

void Controller::startGame(int seed, vector<char> players) {
	model_->startGame(seed, players);
}

void Controller::executeCommand(Command my_command) {

	switch(my_command.type){
				case Command::Type::PLAY:
				model_->playCard(my_command.card);
				break;
				case Command::Type::DISCARD:
				model_->discardCard(my_command.card);
				break;
				case Command::Type::RAGEQUIT:
					model_->rageQuit();
	}
}
