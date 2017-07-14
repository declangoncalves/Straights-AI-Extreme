#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm.h>
#include "Command.h"
#include "model.h"
#include "controller.h"
#include <vector>

class GameWindow : public Gtk::Window, public Observer
{
public:
  GameWindow(const Glib::RefPtr<Gtk::Application>& app, Controller* c, Model* m);
  void updateTable();
  void resetTable();
  void executeCommand(Command c);
  void updatePlayerHand();
  void update();
  void roundEnd();
  void playerTurn();
  ~GameWindow();

private:
  //Signal handlers:
  void startGame();
  void endGame();
  void rageQuit();
  void handView();
  void handClicked(int);

  //Child widgets:
  Gtk::Box* glade_window = nullptr;
  Gtk::Button* start_game_btn = nullptr;
  Gtk::Button* end_game_btn = nullptr;
  Gtk::Button* p1_RQ = nullptr;
  Gtk::Button* p2_RQ = nullptr;
  Gtk::Button* p3_RQ = nullptr;
  Gtk::Button* p4_RQ = nullptr;
  Gtk::Entry* seed_input = nullptr;
  std::vector<Gtk::Button*> handButtons_;
  Gtk::Table* table_ = nullptr;
  Gtk::Box* start_screen = nullptr;
  Gtk::Box m_Box;

  Glib::RefPtr<Gio::SimpleActionGroup> refActionGroup;
  Glib::RefPtr<Gio::SimpleAction> refActionRain;
  Glib::RefPtr<Gtk::Builder> refBuilder;

  //mvc
  Controller* controller_;
  Model* model_;
};

#endif //GTKMM_GAMEWINDOW_H
