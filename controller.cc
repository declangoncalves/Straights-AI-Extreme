#include "controller.h"
#include <iostream>
#include "model.h"

using namespace std;

Controller::Controller( Model *m ) : model_{m} {}

void Controller::newRound() {
	model_->initializeRound();
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
					if (model_->getLegalPlays().size() > 0){
						Command my_command = Command("play", model_->getLegalPlays()[0]);
						executeCommand(my_command);
					}
					else {
						Command my_command = Command("discard", model_->getPlayerHand()[0]);
						executeCommand(my_command);
					}
	}
}
