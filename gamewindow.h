#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm.h>
#include "Command.h"
#include "model.h"
#include "controller.h"
#include <vector>
#include <string>
#include <iostream>


class GameWindow : public Gtk::Window, public Observer
{
public:
  GameWindow(const Glib::RefPtr<Gtk::Application>& app, Controller* c, Model* m);
  ~GameWindow();
  void update();

private:
  //Signal handlers:
  void startGame();
  void executeCommand(Command c);
  void updateTable();
  void resetTable();
  void updateScores();
  void updatePlayerHand();
  void playerTurn();
  std::string listDiscards(std::vector<Card>);
  void roundEnd();
  void endGame();
  void rageQuit();
  void handView();
  void setPlayer(int);
  void handClicked(int);
  void nextRoundClick();

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
  Gtk::Label* p1_score = nullptr;
  Gtk::Label* p2_score = nullptr;
  Gtk::Label* p3_score = nullptr;
  Gtk::Label* p4_score = nullptr;
  Gtk::Label* p1_discards = nullptr;
  Gtk::Label* p2_discards = nullptr;
  Gtk::Label* p3_discards = nullptr;
  Gtk::Label* p4_discards = nullptr;
  Gtk::Button* next_round = nullptr;
  std::vector<Gtk::Button*> handButtons_;
  std::vector<std::vector<Gtk::Image*> > imgTable_;
  std::vector<std::vector<int> > intTable_;
  Gtk::Box* start_screen = nullptr;
  Gtk::Box m_Box;
  Gtk::Box container;
  Glib::RefPtr<Gio::SimpleActionGroup> refActionGroup;
  Glib::RefPtr<Gio::SimpleAction> refActionRain;
  Glib::RefPtr<Gtk::Builder> refBuilder;

  //mvc
  Controller* controller_;
  Model* model_;

  std::vector<char> choices_;
  bool recurring_ = false;
};

#endif //GTKMM_GAMEWINDOW_H
