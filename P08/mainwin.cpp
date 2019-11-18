#include "mainwin.h"
#include "dog.h"
#include "cat.h"
#include "rabbit.h"
#include "client.h"
#include <sstream>
#include <fstream> //future sprint
#include <regex> //future release for bonus features!

///////////////////////////////////////////////////////////////////

Mainwin::Mainwin() : shelter{new Shelter{"Mavs Animal Shelter"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);
    set_title(APP_TITLE);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar

    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

/*
    Gtk::MenuItem *menuitem_newshelter = Gtk::manage(new Gtk::MenuItem("_New Shelter", true));
    menuitem_newshelter->signal_activate().connect([this] {this->on_new_shelter_click();});
    filemenu->append(*menuitem_newshelter);

    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load Shelter", true));
    menuitem_load->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_quit);
    
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

 Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);

*/

    //         Q U I T
    // Append Quit to the File menu

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);


///////////////////////////////////////////////////////////////////
    
     //     A N I M A L
    // Create an Animal menu and add to the menu bar

    Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    //           N E W
    // Append New to the Animal menu

    Gtk::MenuItem *menuitem_newanimal = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newanimal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalmenu->append(*menuitem_newanimal);

    //           L I S T
    // Append List to the Animal menu

    Gtk::MenuItem *menuitem_listanimal = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listanimal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_listanimal);

    Gtk::MenuItem *menuitem_newadopt = Gtk::manage(new Gtk::MenuItem("_Adopt", true));
    menuitem_newadopt->signal_activate().connect([this] {this->on_adopt_animal_click();});
    animalmenu->append(*menuitem_newadopt);

    Gtk::MenuItem *menuitem_listadopted = Gtk::manage(new Gtk::MenuItem("_List Adoptions", true));
    menuitem_listadopted->signal_activate().connect([this] {this->on_list_adopted_click();});
    animalmenu->append(*menuitem_listadopted);

////////////////////////////////////////////////////////////////////
    
     //     C L I E N T
    // Create an Client menu and add to the menu bar

    Gtk::MenuItem *menuitem_client = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);

    //           N E W
    // Append New to the Client menu

    Gtk::MenuItem *menuitem_newclient = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newclient->signal_activate().connect([this] {this->on_new_client_click();});
    clientmenu->append(*menuitem_newclient);

    Gtk::MenuItem *menuitem_listclient = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listclient->signal_activate().connect([this] {this->on_list_clients_click();});
    clientmenu->append(*menuitem_listclient);

//////////////////////////////////////////////////////////////////////

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu

    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

 /*Gtk::ToolButton *load_shelter_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    load_shelter_button->set_tooltip_markup("Load a .muss file");
    load_shelter_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*load_shelter_button);

 Gtk::ToolButton *save_shelter_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    save_shelter_button->set_tooltip_markup("Save a .muss file");
    save_shelter_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_shelter_button);




     Gtk::ToolButton *new_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_animal_button->set_tooltip_markup("Create a new animal");
    new_animal_button->signal_clicked().connect([this] {this->on_new_animal_click();});
    toolbar->append(*new_animal_button);

 Gtk::ToolButton *list_animals_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    list_animals_button->set_tooltip_markup("List all animals in the shelter");
    list_animals_button->signal_clicked().connect([this] {this->on_list_animals_click();});
    toolbar->append(*list_animals_button);

 Gtk::ToolButton *new_client_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_client_button->set_tooltip_markup("Create a new client");
    new_client_button->signal_clicked().connect([this] {this->on_new_client_click();});
    toolbar->append(*new_client_button);

 Gtk::ToolButton *client_list_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    client_list_button->set_tooltip_markup("List all the clients in the shelter");
    client_list_button->signal_clicked().connect([this] {this->on_list_clients_click();});
    toolbar->append(*client_list_button);

Gtk::ToolButton *adopt_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    adopt_animal_button->set_tooltip_markup("Match an animal with a client");
    adopt_animal_button->signal_clicked().connect([this] {this->on_adopt_animal_click();});
    toolbar->append(*adopt_animal_button);

Gtk::ToolButton *adopt_list_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    adopt_list_button->set_tooltip_markup("List clients with adoptions");
    adopt_list_button->signal_clicked().connect([this] {this->on_list_adopted_click();});
    toolbar->append(*adopt_list_button);

Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit the Shelter");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});

    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);
*/
////////////////////////////////////////////////////////////////////
   
     // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining data

    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->pack_start(*data, Gtk::PACK_EXPAND_WIDGET, 0);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages

    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();
}

///////////////////////////////////////////////////////////////////

Mainwin::~Mainwin() { }

///////////////////////////////////////////////////////////////////


// /////////////////
// C A L L B A C K S
// /////////////////


///////////////////////////////////////////////////////////////////

void Mainwin::on_quit_click() { close();}

///////////////////////////////////////////////////////////////////

void Mainwin::on_new_animal_click() {


    Gtk::Dialog dialoga{"Animal Information", *this};
    Gtk::Grid grid2;
    Gtk::Label l_type{"Animal Type"};
    Gtk::ComboBoxText c_type;
    c_type.append("Dog");
    c_type.append("Cat");
    c_type.append("Rabbit");
    c_type.set_active(0);
    dialoga.get_content_area()->add(grid2);
    dialoga.add_button("Add", 1);
    dialoga.add_button("Cancel", 0);
    grid2.attach(l_type, 0, 2, 1, 1);
    grid2.attach(c_type, 1, 2, 2, 1);
    dialoga.show_all();
    int selection = -1;
    int option = dialoga.run();

    if (option == 1)
   {
    selection = c_type.get_active_row_number();
    dialoga.close();

    Gtk::Dialog dialog{"Animal Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_breed{"Breed"};
    Gtk::ComboBoxText c_breed;
    if (selection == 0)
    	for(auto b : dog_breeds) c_breed.append(to_string(b));
    else if (selection == 1)
    	for(auto b : cat_breeds) c_breed.append(to_string(b));
    else if (selection == 2)
        for(auto b : rabbit_breeds) c_breed.append(to_string(b));
    c_breed.set_active(0);
    grid.attach(l_breed, 0, 1, 1, 1);
    grid.attach(c_breed, 1, 1, 2, 1);

    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);
    grid.attach(l_gender, 0, 2, 1, 1);
    grid.attach(c_gender, 1, 2, 2, 1);

    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);
    grid.attach(l_age, 0, 3, 1, 1);
    grid.attach(s_age, 1, 3, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}

    Animal* animal;
    if (selection == 0)
    animal = new Dog{dog_breeds[c_breed.get_active_row_number()],
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};

    if (selection == 1)
    animal = new Cat{cat_breeds[c_breed.get_active_row_number()],
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};

    if (selection == 2)
    animal = new Rabbit{rabbit_breeds[c_breed.get_active_row_number()],
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};


    shelter->add_animal(*animal);
    std::ostringstream oss;
    oss << "Added " << *animal;
    status(oss.str());
    break;
    }
}
}

///////////////////////////////////////////////////////////////////

void Mainwin::on_list_animals_click()
{
    std::ostringstream oss;
    for(int i=0; i<shelter->num_animals(); ++i)
        oss << shelter->animal(i) << '\n';
    data->set_text(oss.str());
    status("");
}      // List all animals

///////////////////////////////////////////////////////////////////

void Mainwin::on_new_client_click()
{
  Gtk::Dialog dialog{"Client Information", *this};

  Gtk::Grid grid;

  Gtk::Label l_name{"Name"};
  Gtk::Entry n_name;
  grid.attach(l_name, 0, 0, 1, 1);
  grid.attach(n_name, 1, 0, 2, 1);

  Gtk::Label l_email{"Email"};
  Gtk::Entry e_email;
  grid.attach(l_email, 0, 1, 1, 1);
  grid.attach(e_email, 1, 1, 2, 1);

  Gtk::Label l_phone{"Phone (no spaces)"};
  Gtk::Entry p_phone;
  grid.attach(l_phone, 0, 2, 1, 1);
  grid.attach(p_phone, 1, 2, 2, 1);

  dialog.get_content_area()->add(grid);

  dialog.add_button("Add Client", 1);
  dialog.add_button("Cancel", 0);

  dialog.show_all();

  while(dialog.run()) {
      if(n_name.get_text().size() == 0 || e_email.get_text().size() == 0 || p_phone.get_text().size() == 0 || p_phone.get_text().size() != 10 /*|| n_name.get_text() == "*required*" || e_email.get_text() == "*required*" || p_phone.get_text() == "*required*" */ )
       {n_name.set_text("*required*");
        e_email.set_text("*required*");
        p_phone.set_text("*required*");
        continue;}


  Client client{n_name.get_text(),e_email.get_text(),p_phone.get_text()};
  shelter->add_client(client);
  std::ostringstream oss;
  oss << "Added " << client;
  status(oss.str());
  break;

}
}

void Mainwin::on_list_clients_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_clients(); ++i)
        oss << shelter->client(i) << '\n';
    data->set_text(oss.str());
    status("");
}      // List all animals
///////////////////////////////////////////////////////////////////
void Mainwin::on_adopt_animal_click()
{
  if (shelter->num_clients() == 0 || (shelter->num_animals() == 0))
  {
  Gtk::MessageDialog{*this, "No animals or clients defined"}.run();
  }
  else{

  Gtk::Dialog dialog{"Want to Adopt an Animal?", *this};
  Gtk::Grid grid;

  Gtk::Label l_name{"Client"};
  Gtk::ComboBoxText c_client;
  for (int k = 0; k < shelter->num_clients(); k++)
  {
    c_client.append(shelter->client(k).name());
  }
  c_client.set_active(0);
  Gtk::Label l_animal{"Animal"};
  Gtk::ComboBoxText c_animal;
  for (int l = 0; l < shelter->num_animals(); l++)
  {
    c_animal.append(shelter->animal(l).adoptname());
  }
  c_animal.set_active(0);
  grid.attach(l_name, 0, 0, 1, 1);
  grid.attach(c_client, 1, 0, 2, 1);
  grid.attach(l_animal, 0, 1, 1, 1);
  grid.attach(c_animal, 1, 1, 2, 1);
  dialog.get_content_area()->add(grid);

  dialog.add_button("Add Client", 1);
  dialog.add_button("Cancel", 0);

  dialog.show_all();
  int client_a;
  int animal_a;
  while(dialog.run()) {
  client_a = c_client.get_active_row_number();
  animal_a = c_animal.get_active_row_number();
  
  Animal& animal = shelter->animal(animal_a);
  Client& client = shelter->client(client_a);
  shelter->adopt(client,animal);
  break;
}
}
}
///////////////////////////////////////////////////////////////////

void Mainwin::on_list_adopted_click()
{
 std::ostringstream oss;
   for (int i = 0; i < shelter-> num_clients(); i++){
   if (shelter->client(i).num_adopted() != 0){
   oss << shelter->client(i) << " " << "adopted: ";
  for (int j = 0; j < shelter->client(i).num_adopted(); j++)
   {
    oss << "\n" << shelter->client(i).animal(j) << "\n";
}
 oss << "\n";
}
}
 data->set_text(oss.str());
 status("");
}

////////////////////////////////////////////////////////////////////

/*void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_ctp = Gtk::FileFilter::create();
    filter_ctp->set_name(MUSS);
    filter_ctp->add_pattern("*."+MUSS);
    dialog.add_filter(filter_ctp);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled."+MUSS);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        std::ofstream ofs{dialog.get_filename()};
        if(!ofs) throw std::runtime_error{"Error writing file"};
    }
}

////////////////////////////////////////////////////////////////////

//void Mainwin::on_new_shelter_click() {}

///////////////////////////////////////////////////////////////////

void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_ctp = Gtk::FileFilter::create();
    filter_ctp->set_name(MUSS);
    filter_ctp->add_pattern("*."+MUSS);
    dialog.add_filter(filter_ctp);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled."+MUSS);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            std::ifstream ifs{dialog.get_filename()};
            if(!ifs) throw std::runtime_error{"File contents bad"};
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open shelter"}.run();
        }
    }
}

////////////////////////////////////////////////////////////////////

void Mainwin::on_save_click() {
    try {
        std::ofstream ofs{shelter->get_filename()};
        shelter->save(ofs);
    } catch(std::exception e) {
        Gtk::MessageDialog{*this, "Unable to save data", false, Gtk::MESSAGE_ERROR}.run();
    }
}

////////////////////////////////////////////////////////////////////

void Mainwin::on_profile_manager_click() {} //BONUS FEATURE

////////////////////////////////////////////////////////////////////

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name(TITLE);
    //auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    //dialog.set_logo(logo);
    dialog.set_version(VERSION);
    dialog.set_copyright("Copyright 2019");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"William P. Anderson"};
    dialog.set_authors(authors);
    //std::vector< Glib::ustring > artists = {};
    //dialog.set_artists(artists);
    //dialog.set_comments("Animal Shelter.");
    dialog.run();
}
///////////////////////////////////////////////////////////////////
*/

// //////////////////
// U T I L I T I E S
// /////////////////


////////////////////////////////////////////////////////////////////

void Mainwin::status(std::string s) {msg->set_text(s);}

////////////////////////////////////////////////////////////////////



