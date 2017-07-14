#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H

#include "Command.h"

class Model;

class Controller {
  public:
    Controller( Model* );

	void executeCommand(Command);
	void newRound();
  void startGame(int seed, std::vector<char> players);

  private:
    Model *model_;
}; // Controller

#endif
