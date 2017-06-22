#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include "observer.h"

class Controller;
class Model;

class View : public Observer {
  public:
    View( Controller*, Model* );
    virtual ~View();
    virtual void update();

  private:
    Model *model_;
    Controller *controller_;
}; // View

#endif
