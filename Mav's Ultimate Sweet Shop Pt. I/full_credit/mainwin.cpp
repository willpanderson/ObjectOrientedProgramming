#include "mainwin.h"

#include <iostream>
Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
    set_default_size(600, 600);
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
/////////////////////////////////////////////////////////////////////////////////////////
    // ///////
    // M E N U
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

/////////////////////////////////////////////////////////////////////////////////////////

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

///////////////////////////////////////////////////////////////////////////////////////////////

    Gtk::MenuItem *menuitem_sweets = Gtk::manage(new Gtk::MenuItem("_Sweets", true));
    menubar->append(*menuitem_sweets);
    Gtk::Menu *sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(*sweetsmenu);

    menuitem_add_sweet = Gtk::manage(new Gtk::MenuItem("_Add Sweets", true));
    menuitem_add_sweet->signal_activate().connect([this] {this->on_add_sweet_click();});
    sweetsmenu->append(*menuitem_add_sweet);


    menuitem_list_sweets = Gtk::manage(new Gtk::MenuItem("_List Sweets", true));
    menuitem_list_sweets->signal_activate().connect([this] {this->on_list_sweets_click();});
    sweetsmenu->append(*menuitem_list_sweets);
    menuitem_list_sweets->set_sensitive(false);
////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
    data->set_text("\t\tWelcome to Mav's Ultimate Sweet Shop!\n\n   Please click on the Store icon in order to get started");

    vbox->show_all();
}

//////////////////////////////////////////////////////////////

Mainwin::~Mainwin() { }

///////////////////////////////////////////////////////////////////
EntryDialog::EntryDialog(Gtk::Window& parent,
                         const Glib::ustring& message,
                         bool use_markup,
                         Gtk::MessageType type,
                         Gtk::ButtonsType buttons,
                         bool modal)
  : MessageDialog(parent, message, use_markup, type,buttons, modal), entry{new Gtk::Entry{}} {
    get_content_area()->pack_start(*entry);  // Add the entry to the MessageDialog
    entry->show();                           // Make the Entry visible
}

// Reflect the next two methods to their equivalents in the Entry widget
void EntryDialog::set_text (const Glib::ustring& text) {entry->set_text(text);}
Glib::ustring EntryDialog::get_text () const {return entry->get_text();}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_store_click()
{
  free(_store);
  _store = new Store();
  Gtk::MessageDialog{*this, "New Store added"}.run();
  data->set_text("You currently have " + std::to_string(this->_store->num_sweets()) + " sweets");

}


void Mainwin::on_add_sweet_click()
{
  std::string name = "";
  std::string price = "";
  double newprice;


  while (name == "")
  {
  EntryDialog edialog{*this, "Please enter the name of a sweet"};
  edialog.set_text("Enter the sweet name here");
  edialog.run();
  name = edialog.get_text();
}
 while(price == "")
  {
  EntryDialog qedialog{*this, "Please enter the " + name + " price" };
  qedialog.run();
  price = qedialog.get_text();
}

newprice = stof(price);
Sweet *candy = new Sweet(name,newprice);
  this->_store->add(*candy);
  data->set_text("You currently have " + std::to_string(this->_store->num_sweets()) + " sweets");
  menuitem_list_sweets->set_sensitive(true);
}


void Mainwin::on_list_sweets_click()
{
  int i;
  std::string name = "Here's a list of your Sweets\n\n\n";
  for (i = 0; i < this->_store->num_sweets(); i++)
  {
   name += "(" + this->_store->sweet(i).name() + "\t$";
   std::string t(16, '\0');
   auto written = std::snprintf(&t[0], t.size(), "%.2f", this->_store->sweet(i).price());
   t.resize(written);
   name += t + ")" + "\n";
  }
  data->set_text(name);
}

void Mainwin::on_about_click()
{
  Glib::ustring s = R"(
  <span size='24000' weight='bold'>Mav's Ultimate Sweet Shop</span>
  <span size='large'>Copyright 2019 by William Anderson</span>
  <span size='small'>Licensed under Creative Commons Attribution 4.0 International
  Icon created by the GNOME Project and XCF, used under free attribution license</span>

The user creates a new store by clicking File>New Store or adding a sweet. The user can create a sweet and enter its name and price by clicking Sweets>Add Sweet. The user may view their current sweets by clicking Sweets>List Sweet.
)";

  Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
  dlg.run();
}

void Mainwin::on_quit_click()
{
  free (_store);
  close();
}
