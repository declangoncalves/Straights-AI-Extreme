#include "gamewindow.h"
#include <gtkmm.h>
#include <iostream>

GameWindow::GameWindow(const Glib::RefPtr<Gtk::Application>& app, Controller* c, Model* m) : m_Box(Gtk::ORIENTATION_VERTICAL)
{
    // Prepare game window
    set_title("Straights EXTREME");
    set_default_size(800, 500);
    choices_ = {'h', 'h', 'h', 'h'};
    // Prepare MVC
    controller_ = c;
    model_ = m;
    model_->subscribe(this);

    refBuilder = Gtk::Builder::create();
    refActionGroup = Gio::SimpleActionGroup::create();
    try {
      refBuilder->add_from_file("start_screen.glade");
    }
    catch(const Glib::Error& ex)
    {
      std::cerr << "ERROR ADDING FROM: glade_project" <<  ex.what();
    }

    refBuilder->get_widget("window1", start_screen);
    refBuilder->get_widget("start_game_btn", start_game_btn);
    refBuilder->get_widget("p1_type", p1_choice);
    refBuilder->get_widget("p2_type", p2_choice);
    refBuilder->get_widget("p3_type", p3_choice);
    refBuilder->get_widget("p4_type", p4_choice);
    refBuilder->get_widget("seed_input", seed_input);


    start_game_btn->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::startGame));
    p1_choice->signal_clicked().connect( sigc::bind<int>( sigc::mem_fun(*this, &GameWindow::setPlayer), 0) );
    p2_choice->signal_clicked().connect( sigc::bind<int>( sigc::mem_fun(*this, &GameWindow::setPlayer), 1) );
    p3_choice->signal_clicked().connect( sigc::bind<int>( sigc::mem_fun(*this, &GameWindow::setPlayer), 2) );
    p4_choice->signal_clicked().connect( sigc::bind<int>( sigc::mem_fun(*this, &GameWindow::setPlayer), 3) );

    //start_game_btn->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::startGame));
    //p1_choice->signal_clicked().connect(sigc::mem_fun(*this, GameWindow::setPlayer, n)
    //p2_choice->signal_clicked().connect(sigc::mem_fun(*this, GameWindow::setPlayer);
    //p3_choice->signal_clicked().connect(sigc::mem_fun(*this, GameWindow::setPlayer(2)));
    //p4_choice->signal_clicked().connect(sigc::mem_fun(*this, GameWindow::setPlayer(3)));


    // refActionGroup->add_action("start_game_btn", sigc::mem_fun(*this, &GameWindow::startGame) );
    // refActionGroup->add_action("p1_type", sigc::mem_fun(*this, &GameWindow::setPlayer(0)) );
    // refActionGroup->add_action("p2_type", sigc::mem_fun(*this, &GameWindow::setPlayer(1)) );
    // refActionGroup->add_action("p3_type", sigc::mem_fun(*this, &GameWindow::setPlayer(2)) );
    // refActionGroup->add_action("p4_type", sigc::mem_fun(*this, &GameWindow::setPlayer(3)) );

    add(container);
    container.add(*start_screen);
    show_all_children();
}

void GameWindow::setPlayer(int i) {
  switch (i) {
    case 0:
      if (choices_[0] == 'c') {
        p1_choice->set_label("Human");
        choices_[0] = 'h';
      }
      else {
        p1_choice->set_label("Computer");
        choices_[0] = 'c';
      }
      break;
    case 1:
      if (choices_[1] == 'c') {
        p2_choice->set_label("Human");
        choices_[1] = 'h';
      }
      else {
        p2_choice->set_label("Computer");
        choices_[1] = 'c';
      }
      break;
    case 2:
      if (choices_[2] == 'c') {
        p3_choice->set_label("Human");
        choices_[2] = 'h';
      }
      else {
        p3_choice->set_label("Computer");
        choices_[2] = 'c';
      }
      break;
    case 3:
      if (choices_[3] == 'c') {
        p4_choice->set_label("Human");
        choices_[3] = 'h';
      }
      else {
        p4_choice->set_label("Computer");
        choices_[3] = 'c';
      }
      break;
  }
  return;
}

GameWindow::~GameWindow()
{
  delete model_;
  delete controller_;
}

void GameWindow::handClicked(int i) {
  return;
}

void GameWindow::startGame() {
  // int seed = 0;
  // const gchar* seed_str = gtk_entry_get_text(GTK_ENTRY(seed_input));
  // seed = atoi(seed_str);
  std::cout << "this worked" << std::endl;
  try
  {
    refBuilder->add_from_file("glade_project.glade");
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "ERROR ADDING FROM: glade_project" <<  ex.what();
  }

  std::cout << "this worked 2" << std::endl;

  refBuilder->get_widget("glade_window", glade_window);
  if (!glade_window) {
    std::cout << "this didn't work" << std::endl;
  }

  //remove(*start_screen);
  container.remove(*start_screen);
  container.add(*glade_window);

  refBuilder->get_widget("end_game_btn", end_game_btn);
  refBuilder->get_widget("p1_RQ", p1_RQ);
  refBuilder->get_widget("p2_RQ", p2_RQ);
  refBuilder->get_widget("p3_RQ", p3_RQ);
  refBuilder->get_widget("p4_RQ", p4_RQ);

  for (int i=0; i < 13; i++){
    handButtons_.push_back(nullptr);
  }

  refBuilder->get_widget("hand_btn_1", handButtons_[0]);
  refBuilder->get_widget("hand_btn_2", handButtons_[1]);
  refBuilder->get_widget("hand_btn_3", handButtons_[2]);
  refBuilder->get_widget("hand_btn_4", handButtons_[3]);
  refBuilder->get_widget("hand_btn_5", handButtons_[4]);
  refBuilder->get_widget("hand_btn_6", handButtons_[5]);
  refBuilder->get_widget("hand_btn_7", handButtons_[6]);
  refBuilder->get_widget("hand_btn_8", handButtons_[7]);
  refBuilder->get_widget("hand_btn_9", handButtons_[8]);
  refBuilder->get_widget("hand_btn_10", handButtons_[9]);
  refBuilder->get_widget("hand_btn_11", handButtons_[10]);
  refBuilder->get_widget("hand_btn_12", handButtons_[11]);
  refBuilder->get_widget("hand_btn_13", handButtons_[12]);

  for (auto button : handButtons_){
    GtkWidget *image = gtk_image_new_from_file("./img/nothing.png");

    gtk_button_set_image(GTK_BUTTON (button), image);

  }


  // for (int i = 0; i < 13; i++) {
  //   Gtk::Button* handButton;
  //   refBuilder->get_widget("hand_" + i, handButton);
  //   handButtons_.push_back(handButton);
  // }
  //action groups
  //refActionGroup->add_action("end_game_btn", sigc::mem_fun(*this, &GameWindow::endGame) );
  //refActionGroup->add_action("p1_RQ", sigc::mem_fun(*this, &GameWindow::rageQuit) );
  //refActionGroup->add_action("p2_RQ", sigc::mem_fun(*this, &GameWindow::rageQuit) );
  //refActionGroup->add_action("p3_RQ", sigc::mem_fun(*this, &GameWindow::rageQuit) );
  //refActionGroup->add_action("P4_RQ", sigc::mem_fun(*this, &GameWindow::rageQuit) );

  // add(*glade_window);

  // handButtons_[0]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(0)));
  // handButtons_[1]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(1)));
  // handButtons_[2]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(2)));
  // handButtons_[3]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(3)));
  // handButtons_[4]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(4)));
  // handButtons_[5]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(5)));
  // handButtons_[6]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(6)));
  // handButtons_[7]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(7)));
  // handButtons_[8]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(8)));
  // handButtons_[9]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(9)));
  // handButtons_[10]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(10)));
  // handButtons_[11]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(11)));
  // handButtons_[12]->signal_clicked().connect(sigc::mem_fun(*this, &GameWindow::handClicked(12)));


  show_all_children();
  return;
}

void GameWindow::endGame() {
  return;
}

void GameWindow::updatePlayerHand() {
  return;
}

void GameWindow::update() {
		if (model_->getGameState() != 0){ // Round Finished
			roundEnd();
		}
		else { // Round not finished
			playerTurn();
	  }
}

void GameWindow::playerTurn() {
  updateTable();
  return;
}

void GameWindow::roundEnd() {
  return;
}

void GameWindow::resetTable() {
  return;
}

void GameWindow::executeCommand(Command c) {
  // If command is valid, send to controller_

  // If commmand is invalid, update widgets and do nothing
  Command my_command;
	std::vector<Card> legalPlays = model_->getLegalPlays();
	std::vector<Card> playerHand = model_->getCurrentPlayer()->getHand();

	// First check if computer or human player
	if (model_->getCurrentPlayer()->getType() == 'c') {
		my_command = model_->getCurrentPlayer()->makeMove(legalPlays);
	}
	else { // Human Player

		bool validCommand = false;

		while (!validCommand){
			std::cout << ">";
			std::cin >> my_command;

			switch(my_command.type){
				case Command::Type::PLAY:
					if (std::find(legalPlays.begin(), legalPlays.end(), my_command.card) != legalPlays.end()){
						controller_->executeCommand(my_command);
					}
					else {
            // Update window widgets
					}
					break;
				case Command::Type::DISCARD:
					if (legalPlays.size() == 0) {
					  controller_->executeCommand(my_command);
					}
					else {
						// Update window widgets
					}
					break;
				case Command::Type::QUIT:
					exit(0);
				case Command::Type::RAGEQUIT:
					controller_->executeCommand(my_command);
			}
		}
	}
}

void GameWindow::updateTable() {
  return;
}

void GameWindow::rageQuit() {
  return;
}




  //add(m_Box); //We can put a MenuBar at the top of the box and other stuff below it.

  //Define the actions:
//   m_refActionGroup = Gio::SimpleActionGroup::create();

//   m_refActionGroup->add_action("new",
//     sigc::mem_fun(*this, &ExampleWindow::on_action_file_new) );
//   m_refActionGroup->add_action("open",
//     sigc::mem_fun(*this, &ExampleWindow::on_action_others) );


//   m_refActionRain = m_refActionGroup->add_action_bool("rain",
//     sigc::mem_fun(*this, &ExampleWindow::on_action_toggle),
// //     false);

//   m_refActionGroup->add_action("quit",
//     sigc::mem_fun(*this, &ExampleWindow::on_action_file_quit) );

//   m_refActionGroup->add_action("cut",
//     sigc::mem_fun(*this, &ExampleWindow::on_action_others) );
//   m_refActionGroup->add_action("copy",
//     sigc::mem_fun(*this, &ExampleWindow::on_action_others) );
//   m_refActionGroup->add_action("paste",
// //     sigc::mem_fun(*this, &ExampleWindow::on_action_others) );

//   insert_action_group("example", m_refActionGroup);

  //Define how the actions are presented in the menus and toolbars:

  //Layout the actions in a menubar and toolbar:
//   const char* ui_info =
//     "<interface>"
//     "  <menu id='menubar'>"
//     "    <submenu>"
//     "      <attribute name='label' translatable='yes'>_File</attribute>"
//     "      <section>"
//     "        <item>"
//     "          <attribute name='label' translatable='yes'>_New</attribute>"
//     "          <attribute name='action'>example.new</attribute>"
//     "          <attribute name='accel'>&lt;Primary&gt;n</attribute>"
//     "        </item>"
//     "        <item>"
//     "          <attribute name='label' translatable='yes'>_Open</attribute>"
//     "          <attribute name='action'>example.open</attribute>"
//     "          <attribute name='accel'>&lt;Primary&gt;o</attribute>"
//     "        </item>"
//     "      </section>"
//     "      <section>"
//     "        <item>"
//     "          <attribute name='label' translatable='yes'>Rain</attribute>"
//     "          <attribute name='action'>example.rain</attribute>"
//     "        </item>"
//     "      </section>"
//     "      <section>"
//     "        <item>"
//     "          <attribute name='label' translatable='yes'>_Quit</attribute>"
//     "          <attribute name='action'>example.quit</attribute>"
//     "          <attribute name='accel'>&lt;Primary&gt;q</attribute>"
//     "        </item>"
//     "      </section>"
//     "    </submenu>"
//     "    <submenu>"
//     "      <attribute name='label' translatable='yes'>_Edit</attribute>"
//     "      <item>"
//     "        <attribute name='label' translatable='yes'>_Cut</attribute>"
//     "        <attribute name='action'>example.cut</attribute>"
//     "        <attribute name='accel'>&lt;Primary&gt;x</attribute>"
//     "      </item>"
//     "      <item>"
//     "        <attribute name='label' translatable='yes'>_Copy</attribute>"
//     "        <attribute name='action'>example.copy</attribute>"
//     "        <attribute name='accel'>&lt;Primary&gt;c</attribute>"
//     "      </item>"
//     "      <item>"
//     "        <attribute name='label' translatable='yes'>_Paste</attribute>"
//     "        <attribute name='action'>example.paste</attribute>"
//     "        <attribute name='accel'>&lt;Primary&gt;v</attribute>"
//     "      </item>"
//     "    </submenu>"
//     "  </menu>"
//     "</interface>";

  // When the menubar is a child of a Gtk::Window, keyboard accelerators are not
  // automatically fetched from the Gio::Menu.
  // See the examples/book/menus/main_menu example for an alternative way of
  // adding the menubar when using Gtk::ApplicationWindow.
  // Gtk::Application::set_accel_for_action() is new in gtkmm 3.11.9.
//   app->set_accel_for_action("example.new", "<Primary>n");
//   app->set_accel_for_action("example.open", "<Primary>o");
//   app->set_accel_for_action("example.quit", "<Primary>q");
//   app->set_accel_for_action("example.cut", "<Primary>x");
//   app->set_accel_for_action("example.copy", "<Primary>c");
//   app->set_accel_for_action("example.paste", "<Primary>v");


  //Get the menubar:
//   auto object = m_refBuilder->get_object("menubar");
//   auto gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
//   if (!gmenu)
//     g_warning("GMenu not found");
//   else
//   {
//     auto pMenuBar = Gtk::manage(new Gtk::MenuBar(gmenu));

//     //Add the MenuBar to the window:
//     m_Box.pack_start(*pMenuBar, Gtk::PACK_SHRINK);
//   }

//   //Get the toolbar and add it to a container widget:
//   Gtk::Toolbar* toolbar = nullptr;
//   m_refBuilder->get_widget("toolbar", toolbar);
//   if (!toolbar)
//     g_warning("GtkToolbar not found");
//   else
//     m_Box.pack_start(*toolbar, Gtk::PACK_SHRINK);

//   show_all_children();
// }

// void ExampleWindow::on_action_file_quit()
// {
//   hide(); //Closes the main window to stop the app->run().
// }

// void ExampleWindow::on_action_file_new()
// {
//    std::cout << "A File|New menu item was selected." << std::endl;
// }

// void ExampleWindow::on_action_others()
// {
//   std::cout << "A menu item was selected." << std::endl;
// }

// void ExampleWindow::on_action_toggle()
// {
//   std::cout << "The toggle menu item was selected." << std::endl;

//   bool active = false;
//   m_refActionRain->get_state(active);

//   //The toggle action's state does not change automatically:
//   active = !active;
//   m_refActionRain->change_state(active);

//   Glib::ustring message;
//   if(active)
//     message = "Toggle is active.";
//   else
//     message = "Toggle is not active";

//   std::cout << message << std::endl;
// }
