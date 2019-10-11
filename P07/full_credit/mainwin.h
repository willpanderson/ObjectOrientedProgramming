#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();

  protected:
    void on_scale_value_changed();
    void oncomboboxtext_activate();
  private:
    
    Gtk::Scale* scale;
    Gtk::ComboBoxText* comboboxtext;
    Gtk::Label* label;
    double *s2;
};
