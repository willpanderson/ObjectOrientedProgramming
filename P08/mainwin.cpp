#include "mainwin.h"



Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(640, 480);
    set_title("Mav's Animal Shelter Software");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     A N I M A L S    M E N U
    // Create an Animal menu and add to the menu bar
    Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    //         A D D   A N I M A L
    // Append Add to the Sweets menu
    menuitem_add_animal = Gtk::manage(new Gtk::MenuItem("_New Animal", true));
    menuitem_add_animal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalmenu->append(*menuitem_add_animal);

    //         L I S T   A N I M A L S
    // Append List to the Animals menu
    menuitem_list_animal = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_list_animal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_list_animal);
    
    //     H E L P
    // Create a Help menu and add to the menu bar
    //Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    //menubar->append(*menuitem_help);
    //Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    //menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    //Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    //menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    //helpmenu->append(*menuitem_about);

        // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    label = Gtk::manage(new Gtk::Label());
    label->set_hexpand(true);
    label->set_vexpand(true);
    vbox->add(*label);

    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    // Set the sensitivity of menu and tool bar items to match what data is available
    //reset_sensitivity();

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_animal_click()
{
  close();
}
void Mainwin::on_list_animals_click()
{
 close();
}
void Mainwin::on_quit_click()
{
 close();
}


