#include "model.h"
#include "controller.h"
#include "view.h"
#include <string>
#include <vector>

int main( int argc, char * argv[] ) {

    std::vector<char> players;
    for (int i = 0; i < 4; i ++) {
      std::cout <<  "Is player " << (i + 1) << " a human(h) or a computer(c)?\n" << endl;
      std::string type;
      std::cin >> type;
      // todo: throw exception
      // if (type != "h" && type != "c") cerr << "error: wrong type" << endl;
      Player player = new Player(type);
      players.push(player);
    }
    int seed = atoi(argv[1], players);
    Model model(seed); // Create model
    Controller controller( &model ); // Create controller
    View view( &controller, &model ); // Create the view

    return 0;
} // main
