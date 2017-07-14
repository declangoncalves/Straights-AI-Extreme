#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm.h>
#include "Command.h"
#include "model.h"
#include "controller.h"
#include <vector>
#include <string>

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
  void setPlayer(int);
  void handClicked(int);

  //Child widgets:
  Gtk::Box* glade_window = nullptr;
  Gtk::Button* start_game_btn = nullptr;
  Gtk::Button* end_game_btn = nullptr;
  Gtk::Button* p1_RQ = nullptr;
  Gtk::Button* p2_RQ = nullptr;
  Gtk::Button* p3_RQ = nullptr;
  Gtk::Button* p4_RQ = nullptr;
  Gtk::Button* p1_choice = nullptr;
  Gtk::Button* p2_choice = nullptr;
  Gtk::Button* p3_choice = nullptr;
  Gtk::Button* p4_choice = nullptr;
  Gtk::Entry* seed_input = nullptr;
  std::vector<Gtk::Button*> handButtons_;
  Gtk::Table* table_ = nullptr;
  Gtk::Box* start_screen = nullptr;
  Gtk::Box m_Box;
  Gtk::Box container;

  // Hand Button
  Gtk::Button* hand_btn_1 = nullptr;
  Gtk::Button* hand_btn_2 = nullptr;
  Gtk::Button* hand_btn_3 = nullptr;
  Gtk::Button* hand_btn_4 = nullptr;
  Gtk::Button* hand_btn_5 = nullptr;
  Gtk::Button* hand_btn_6 = nullptr;
  Gtk::Button* hand_btn_7 = nullptr;
  Gtk::Button* hand_btn_8 = nullptr;
  Gtk::Button* hand_btn_9 = nullptr;
  Gtk::Button* hand_btn_10 = nullptr;
  Gtk::Button* hand_btn_11 = nullptr;
  Gtk::Button* hand_btn_12 = nullptr;
  Gtk::Button* hand_btn_13 = nullptr;

  Glib::RefPtr<Gio::SimpleActionGroup> refActionGroup;
  Glib::RefPtr<Gio::SimpleAction> refActionRain;
  Glib::RefPtr<Gtk::Builder> refBuilder;

  //mvc
  Controller* controller_;
  Model* model_;

  std::vector<char> choices_;
};

#endif //GTKMM_GAMEWINDOW_H
