#include "model.h"
#include "controller.h"
#include "view.h"
#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include <string>

#include <vector>
#include <iostream>
#include <sstream>

#include <gtkmm.h>
#include "gamewindow.h"

using namespace std;

int main( int argc, char * argv[] ) {

	auto app = Gtk::Application::create(argc, argv);
  GameWindow window(app);

  std::vector<Player*> players;

  int seed = 0;
  for (int i = 0; i < 4; i ++) {
      Human *a = new Human();
      players.push_back(a);
  }

  app->run(window);
  

  Model model(seed, players); // Create model
  Controller controller( &model ); // Create controller
  View view( &controller, &model); // Create the view

  return 0;

} // main
