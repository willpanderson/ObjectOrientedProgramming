#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
    
    // ///////
    // M E N U
    Gtk::MenuItem *menuitem = Gtk::manage(new Gtk::MenuItem);
    vbox->pack_start(*menuitem, Gtk::PACK_SHRINK, 0);


    // /////////////
    // T O O L B A R
    Gtk::ToolButton *toptoolbutton = Gtk::manage(new Gtk::ToolButton);



    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders

    Gtk::Label *label = Gtk::manage(new Gtk::Label);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////


// /////////////////
// U T I L I T I E S
// /////////////////
