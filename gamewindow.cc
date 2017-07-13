#include "gamewindow.h"
#include <gtkmm.h>
#include <iostream>

GameWindow::GameWindow(const Glib::RefPtr<Gtk::Application>& app, Controller* c, Model* m) : m_Box(Gtk::ORIENTATION_VERTICAL)
{
    // Prepare game window
    set_title("Straights EXTREME");
    set_default_size(600, 600);
    m_refBuilder = Gtk::Builder::create();
    try
    {
        m_refBuilder->add_from_file("glade_project.glade");
    }
    catch(const Glib::Error& ex)
    {
        std::cerr << "ERROR ADDING FROM: glade_project" <<  ex.what();
    }

    // Prepare MVC
    controller_ = c;
    model_ = m;
    model_->subscribe(this);
}

GameWindow::~GameWindow()
{
  delete model_;
  delete controller_;
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
