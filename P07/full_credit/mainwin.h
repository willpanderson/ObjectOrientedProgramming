#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();

  protected:
    void on_scale_value_changed();
    void on_button_click(int button);
  private:

    Gtk::Scale* scale;
    Gtk::Button* button;
    Gtk::Button* button2;
    Gtk::Button* button3;
    Gtk::Label* label;
    double *s2;
};
