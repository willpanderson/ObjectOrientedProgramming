#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"


const std::string VERSION{"0.0.1"};
const std::string APP_NAME{"edu.uta.cse1325.MASS.v0_0_1"};

class Mainwin : public Gtk::Window
{

public:
  Mainwin();
  virtual ~Mainwin();

protected:
  void on_quit_click();
  void on_new_animal_click();
  void on_list_animals_click();


private:
  Shelter *shelter;
  Gtk::Label *label;
  Gtk::Label *msg;
  Gtk::MenuItem *menuitem_add_animal;    // Animal > Add
  Gtk::MenuItem *menuitem_list_animal;  // Animal > List

};


#endif
