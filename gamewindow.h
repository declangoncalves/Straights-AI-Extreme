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
//   void on_action_file_new();
//   void on_action_file_quit();
//   void on_action_others();
//   void on_action_toggle();

  //Child widgets:

  Gtk::Button* start_game_btn = nullptr;
  Gtk::Button* end_game_btn = nullptr;
  Gtk::Button* p1_RQ = nullptr;
  Gtk::Button* p2_RQ = nullptr;
  Gtk::Button* p3_RQ = nullptr;
  Gtk::Button* p4_RQ = nullptr;

  Gtk::Box m_Box;
  Controller* controller_;
  vector<Gtk::Button> handButtons_;
  Gtk::Table table_;

  Model* model_;
  Glib::RefPtr<Gtk::Builder> m_refBuilder;
  //Glib::RefPtr<Gio::SimpleActionGroup> m_refActionGroup;
  //Glib::RefPtr<Gio::SimpleAction> m_refActionRain;
};

#endif //GTKMM_GAMEWINDOW_H
