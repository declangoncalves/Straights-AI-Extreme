#ifndef GTKMM_GAMEWINDOW_H
#define GTKMM_GAMEWINDOW_H

#include <gtkmm.h>
#include "Command.h"
#include "model.h"
#include "controller.h"

class GameWindow : public Gtk::Window, public Observer
{
public:
  GameWindow(const Glib::RefPtr<Gtk::Application>& app, Controller* c, Model* m);
  void updateTable();
  void executeCommand(Command c);
  void updatePlayerHand();
  void update();
  ~GameWindow();

private:
  //Signal handlers:
//   void on_action_file_new();
//   void on_action_file_quit();
//   void on_action_others();
//   void on_action_toggle();

  //Child widgets:
  Gtk::Box m_Box;

  Glib::RefPtr<Gtk::Builder> m_refBuilder;
  //Glib::RefPtr<Gio::SimpleActionGroup> m_refActionGroup;
  //Glib::RefPtr<Gio::SimpleAction> m_refActionRain;
};

#endif //GTKMM_GAMEWINDOW_H
