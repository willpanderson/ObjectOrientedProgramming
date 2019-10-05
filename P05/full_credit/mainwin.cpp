#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
    set_default_size (768,768);
    newbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*newbox);

    // ///////
    // M E N U
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    newbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    

    // /////////////
    // T O O L B A R
    Gtk::Toolbar *toptoolbar = Gtk::manage(new Gtk::Toolbar);   
    newbox->add(*toptoolbar);


    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders



    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////
void Main_window::on_quit_click() 
{
    hide();
}



// /////////////////
// U T I L I T I E S
// /////////////////


