#include "model.h"
#include "controller.h"
#include "view.h"
#include "Player.h"
#include <string>
#include <vector>
#include <iostream>

int main( int argc, char * argv[] ) {

    std::vector<Player> players;
    // for (int i = 0; i < 4; i ++) {
    //   std::cout <<  "Is player " << (i + 1) << " a human(h) or a computer(c)?\n";
    //   std::string type;
    //   std::cin >> type;
    //   // todo: throw exception
    //   // if (type != "h" && type != "c") cerr << "error: wrong type" << endl;
    //   Player player(type[0]);
    //   players.push_back(player);
    // }
    // int seed = atoi(argv[1]);
    Player a('h');
    Player b('h');
    Player c('h');
    Player d('h');
    players.push_back(a);
    players.push_back(b);
    players.push_back(c);
    players.push_back(d);
    int seed = 42;
    Model model(seed, players); // Create model
    // cout << model.getDeck()[13] << endl;
    model.initializeRound();
    // cout << model.getDeck()[13] << endl;
    // cout << model.getCurrentPlayer().getHand().size();
    Controller controller( &model ); // Create controller
    View view( &controller, &model ); // Create the view

    return 0;
} // main
