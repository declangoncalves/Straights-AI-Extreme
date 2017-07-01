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
	const void printClubs(std::vector<Card>);
	const void printSpades(std::vector<Card>);
	const void printHearts(std::vector<Card>);
	const void printDiamonds(std::vector<Card>);

	const void printPlayerHand(std::vector<Card>);
	const void printLegalPlays(std::vector<Card>);

	Command receiveCommand();
	void printDeck();

  private:
    Model *model_;
    Controller *controller_;
	int gamePhase_ = 1; // 1 - RoundStart | 2 - PlayerTurn
}; // View

#endif
