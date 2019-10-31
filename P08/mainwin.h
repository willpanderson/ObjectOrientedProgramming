#ifndef __MAINWIN_H_
#define __MAINWIN_H_

class Mainwin
{

public:
  void Mainwin();
  void ~Mainwin();

protected:
void on_quit_click();
void on_new_animal_click();
void on_list_animals_click();

private:
Shelter *shelter;
Gtk::Label *label;
Gtk::Label *msg;
};


#endif
