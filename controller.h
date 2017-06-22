#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H

class Model;

class Controller {
  public:
    Controller( Model* );
    
    // UI Interaction Events

  private:
    Model *model_;
}; // Controller

#endif

