#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include "observer.h"
#include "Card.h"
#include "Command.h"
#include "Player.h"
#include <vector>

using namespace std;

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
	const void printClubs(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
	const void printSpades(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
	const void printHearts(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
	const void printDiamonds(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
  const void printPlayerDiscards(Player);
	const void printPlayerHand();
	const void printLegalPlays();

	Command receiveCommand();
	void printDeck();

  private:
    Model *model_;
    Controller *controller_;
	   int gamePhase_ = 1; // 1 - RoundStart | 2 - PlayerTurn
}; // View

#endif
