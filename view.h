#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include "observer.h"
#include "Card.h"
#include "Command.h"
#include "Player.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include <string>
#include <vector>
#include <iostream>
#include <gtkmm.h>

// Include GTK widgets
#include <gtkmm/window.h>
#include <gtkmm/fixed.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/table.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>

using namespace std;

class Controller;
class Model;

class View : public Observer, public Gtk::Window {
  public:

    View( Controller*, Model* );
    ~View();
    void update() override;

	void roundStart();
	void playerTurn();
	void roundEnd();

	// Helper Functions
	const void printClubs(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
	const void printSpades(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
	const void printHearts(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
	const void printDiamonds(std::vector<vector<Card> > cardTable, std::vector<vector<int> > intTable);
  const void printPlayerDiscards(Player*);
	const void printPlayerHand();
	const void printLegalPlays();

	Command receiveCommand();
	const void printDeck();

  private:
    Model *model_;
    Controller *controller_;
	  int gamePhase_ = 1; // 1 - RoundStart | 2 - PlayerTurn

		// Glade / GTK
		Glib::RefPtr<Gtk::Builder> builder;
		Gtk::Window* pWindow = nullptr;



}; // View

//helper functions

string rankToLetter(int rank);

#endif
