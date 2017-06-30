#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include <iostream>

View::View(Controller* c, Model* m) {
	controller_ = c;
	model_ = m;
}

View::~View() {}
