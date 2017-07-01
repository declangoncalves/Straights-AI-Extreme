#include "model.h"
#include "controller.h"
#include "view.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main( int argc, char * argv[] ) {

    std::vector<Player> players;
    for (int i = 0; i < 4; i ++) {
      std::cout <<  "Is player " << (i + 1) << " a human(h) or a computer(c)?\n" << endl;
      std::string type;
      std::cin >> type;
      // todo: throw exception
      // if (type != "h" && type != "c") cerr << "error: wrong type" << endl;
      Player player(type[0]);
      players.push_back(player);
    }
    int seed = stoi(argv[1]);
    Model model(seed, players); // Create model
    Controller controller( &model ); // Create controller
    View view( &controller, &model ); // Create the view

    return 0;
} // main
