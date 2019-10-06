#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
    set_default_size(600, 600);
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);

    Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add Sweets", true));
    menuitem_add->signal_activate().connect([this] {this->on_add_sweet_click();});
    filemenu->append(*menuitem_add);

    Gtk::MenuItem *menuitem_lists = Gtk::manage(new Gtk::MenuItem("_List Sweets", true));
    menuitem_lists->signal_activate().connect([this] {this->on_list_sweets_click();});
    filemenu->append(*menuitem_lists);

    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Place Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_place_order_click();});
    filemenu->append(*menuitem_order);

    Gtk::MenuItem *menuitem_listo = Gtk::manage(new Gtk::MenuItem("_List Orders", true));
    menuitem_listo->signal_activate().connect([this] {this->on_list_orders_click();});
    filemenu->append(*menuitem_listo);


    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);


    // /////////////
    // T O O L B A R
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit game");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders



    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_store_click()
{
  close();//temp
}
void Mainwin::on_add_sweet_click()
{
  close();//temp
}
void Mainwin::on_list_sweets_click()
{
  close();//temp
}
void Mainwin::on_place_order_click()
{
  close();//temp
}
void Mainwin::on_list_orders_click()
{
  close();//temp
}
void Mainwin::on_about_click()
{
  close();//temp
}
void Mainwin::on_quit_click()
{
  close();
}

// /////////////////
// U T I L I T I E S
// /////////////////
