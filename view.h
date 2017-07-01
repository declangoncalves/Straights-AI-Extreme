#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include "observer.h"

class Controller;
class Model;

class View : public Observer {
  public:

    View( Controller*, Model* );
    virtual ~View();
    void update() override;

	void roundStart();
	void playerTurn();
	void roundEnd();

	// Helper Functions
	const void printClubs(std::vector<Cards>;
	const void printSpades(std::vector<Cards>;
	const void printHearts(std::vector<Cards>;
	const void printDiamonds(std::vector<Cards>;

	const void printPlayerHand(std::vector<Cards>;
	const void printLegalPlays(std::vector<Cards>;

	Commmand receiveCommand();
	void printDeck();

  private:
    Model *model_;
    Controller *controller_;
	int gamePhase_ = 1; // 1 - RoundStart | 2 - PlayerTurn | 3 - RoundEnd
}; // View

#endif
