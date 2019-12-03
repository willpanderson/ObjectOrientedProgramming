#include "mainwin.h"
#include "dog.h"
#include "cat.h"
#include "rabbit.h"
#include "client.h"
//#include "staff.h"
#include <sstream>
#include <fstream>

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
    menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
   


    //         O P E N
    // Append Open to the File menu
    menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_shelter_click();});
    filemenu->append(*menuitem_new);



    //         O P E N
    // Append Open to the File menu
    menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    //         S A V E
    // Append Save to the File menu
    menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);

    //         S A V E  A S
    // Append Save to the File menu
    menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);

    //         T E S T
    // Append Test to the File menu
    menuitem_test = Gtk::manage(new Gtk::MenuItem("_Test", true));
    menuitem_test->signal_activate().connect([this] {
        Animal* animals[] = {
            new Dog   {Dog_breed::MIX,          "Fido",      Gender::MALE,   3},
            new Cat   {Cat_breed::MIX,          "Mouser",    Gender::FEMALE, 2},
            new Rabbit{Rabbit_breed::HARLEQUIN, "Hopper",    Gender::MALE,   7},
            new Dog   {Dog_breed::BULLDOG,      "Rover",     Gender::MALE,   3},
            new Cat   {Cat_breed::BIRMAN,       "Fluffball", Gender::FEMALE, 1},
            new Rabbit{Rabbit_breed::MIX,       "Pillbox",   Gender::MALE,   7},
            new Dog   {Dog_breed::DACHSHUND,    "Noodle",    Gender::FEMALE, 5},
            new Cat   {Cat_breed::RAGDOLL,      "Sugar",     Gender::FEMALE, 2},
            new Rabbit{Rabbit_breed::POLISH,    "Wiggles",   Gender::MALE,   7},
            new Dog   {Dog_breed::POODLE,       "Priscilla", Gender::FEMALE, 9},
            new Cat   {Cat_breed::SIAMESE,      "Shelley",   Gender::FEMALE, 2},
            new Rabbit{Rabbit_breed::LOP,       "Leo",       Gender::MALE,   4},
        };
        for (auto a : animals) shelter->add_animal(*a);

        Client clients[] = {
            Client{"Clifford Red",     "817-555-1212", "clifford@scholastic.com"},
            Client{"Mary Tyler Moore", "817-CAT-MEOW", "mtm@wjm.tv"             },
            Client{"Mr. Magoo",        "817-555-0000", "mr.magoo@fleamail.com"  },
            Client{"Columbo",          "817-COL-UMBO", "columbo@lapd.gov"       },
            Client{"Natalia Alianova", "817-BLK-WIDO", "natasha@shield.gov"     },
            Client{"Bond, James Bond", "817-007-BOND", "classified"             },
        };
        for (auto c : clients) shelter->add_client(c);
    });
    filemenu->append(*menuitem_test);

    menuitem_properties = Gtk::manage(new Gtk::MenuItem("_Properties", true));
    menuitem_properties->signal_activate().connect([this] {this->on_properties_click();});
    filemenu->append(*menuitem_properties);


    //         Q U I T
    // Append Quit to the File menu
    menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     E D I T
    // Create a Edit menu and add to the menu bar
    menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);

    menuitem_undo = Gtk::manage(new Gtk::MenuItem("_Undo", true));
    menuitem_undo->signal_activate().connect([this] {this->on_undo_click();});
    editmenu->append(*menuitem_undo);

    //    R O L E
    // Create a role menu and add to menu bar
    menuitem_role = Gtk::manage(new Gtk::MenuItem("_Role", true));
    menubar->append(*menuitem_role);
    Gtk::Menu *rolemenu = Gtk::manage(new Gtk::Menu());
    menuitem_role->set_submenu(*rolemenu);
    
    menuitem_clientr = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menuitem_clientr->signal_activate().connect([this] {this->on_client_role_click();});
    rolemenu->append(*menuitem_clientr);
    
    menuitem_staff = Gtk::manage(new Gtk::MenuItem("_Staff", true));
    menuitem_staff->signal_activate().connect([this] {this->on_staff_role_click();});
    rolemenu->append(*menuitem_staff);
    
    menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager", true));
    menuitem_manager->signal_activate().connect([this] {this->on_manager_role_click();});
    rolemenu->append(*menuitem_manager);
    
    menuitem_director = Gtk::manage(new Gtk::MenuItem("_Director", true));
    menuitem_director->signal_activate().connect([this] {this->on_director_role_click();});
    rolemenu->append(*menuitem_director);
    
    
    
    //     A N I M A L
    // Create an Animal menu and add to the menu bar
    menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    //           N E W
    // Append New to the Animal menu
    menuitem_newanimal = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newanimal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalmenu->append(*menuitem_newanimal);

    //           L I S T
    // Append List to the Animal menu
    menuitem_listanimal = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listanimal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_listanimal);


    //     C L I E N T
    // Create a Client menu and add to the menu bar
    menuitem_client = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);

    //           N E W
    // Append New to the Client menu
    menuitem_newclient = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newclient->signal_activate().connect([this] {this->on_new_client_click();});
    clientmenu->append(*menuitem_newclient);

    //           L I S T
    // Append List to the Client menu
    menuitem_listclient = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listclient->signal_activate().connect([this] {this->on_list_clients_click();});
    clientmenu->append(*menuitem_listclient);

    //           A D O P T
    // Append Adopt to the Client menu
    menuitem_adopt = Gtk::manage(new Gtk::MenuItem("_Adopt", true));
    menuitem_adopt->signal_activate().connect([this] {this->on_adopt_animal_click();});
    clientmenu->append(*menuitem_adopt);

    //           S H O W   A D O P T I O N S
    // Append Show Adoptions to the Client menu
    menuitem_list_adoptions = Gtk::manage(new Gtk::MenuItem("_Show Adoptions", true));
    menuitem_list_adoptions->signal_activate().connect([this] {this->on_list_adopted_click();});
    clientmenu->append(*menuitem_list_adoptions);


    //     R E P O R T
    // Create a Report menu and add to the menu bar
    menuitem_report = Gtk::manage(new Gtk::MenuItem("_Report", true));
    menubar->append(*menuitem_report);
    Gtk::Menu *reportmenu = Gtk::manage(new Gtk::Menu());
    menuitem_report->set_submenu(*reportmenu);
    
    menuitem_ranimals = Gtk::manage(new Gtk::MenuItem("_Animals", true));
    menuitem_ranimals->signal_activate().connect([this] {this->on_animal_report_click();});
    reportmenu->append(*menuitem_ranimals);

    menuitem_rclients = Gtk::manage(new Gtk::MenuItem("_Clients", true));
    menuitem_rclients->signal_activate().connect([this] {this->on_client_report_click();});
    reportmenu->append(*menuitem_rclients);
    
    
    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);



    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    Gtk::Image *load_image = Gtk::manage(new Gtk::Image("load.png"));
    load_shelter_button = Gtk::manage(new Gtk::ToolButton(*load_image));
    load_shelter_button->set_tooltip_markup("Load a .muss file");
    load_shelter_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*load_shelter_button);

    Gtk::Image *save_image = Gtk::manage(new Gtk::Image("save_file.png"));
    save_shelter_button = Gtk::manage(new Gtk::ToolButton(*save_image));
    save_shelter_button->set_tooltip_markup("Save a .muss file");
    save_shelter_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_shelter_button);


    Gtk::Image *new_animal = Gtk::manage(new Gtk::Image("dog_aboutx.png"));
    new_animal_button = Gtk::manage(new Gtk::ToolButton(*new_animal));
    new_animal_button->set_tooltip_markup("Create a new animal");
    new_animal_button->signal_clicked().connect([this] {this->on_new_animal_click();});
    toolbar->append(*new_animal_button);

    Gtk::Image *find_image = Gtk::manage(new Gtk::Image("find.png"));
    list_animals_button = Gtk::manage(new Gtk::ToolButton(*find_image));
    list_animals_button->set_tooltip_markup("List all animals in the shelter");
    list_animals_button->signal_clicked().connect([this] {this->on_list_animals_click();});
    toolbar->append(*list_animals_button);

    Gtk::Image *client_image = Gtk::manage(new Gtk::Image("client.png"));
    new_client_button = Gtk::manage(new Gtk::ToolButton(*client_image));
    new_client_button->set_tooltip_markup("Create a new client");
    new_client_button->signal_clicked().connect([this] {this->on_new_client_click();});
    toolbar->append(*new_client_button);

    Gtk::Image *client_list = Gtk::manage(new Gtk::Image("client_list.png"));
    client_list_button = Gtk::manage(new Gtk::ToolButton(*client_list));
    client_list_button->set_tooltip_markup("List all the clients in the shelter");
    client_list_button->signal_clicked().connect([this] {this->on_list_clients_click();});
    toolbar->append(*client_list_button);

    Gtk::Image *adopt_image = Gtk::manage(new Gtk::Image("adopt.png"));
    adopt_animal_button = Gtk::manage(new Gtk::ToolButton(*adopt_image));
    adopt_animal_button->set_tooltip_markup("Match an animal with a client");
    adopt_animal_button->signal_clicked().connect([this] {this->on_adopt_animal_click();});
    toolbar->append(*adopt_animal_button);

    Gtk::Image *info_image = Gtk::manage(new Gtk::Image("info.png"));
    adopt_list_button = Gtk::manage(new Gtk::ToolButton(*info_image));
    adopt_list_button->set_tooltip_markup("List clients with adoptions");
    adopt_list_button->signal_clicked().connect([this] {this->on_list_adopted_click();});
    toolbar->append(*adopt_list_button);

    Gtk::Image *exit_image = Gtk::manage(new Gtk::Image("exit.png"));
    quit_button = Gtk::manage(new Gtk::ToolButton(*exit_image));
    quit_button->set_tooltip_markup("Exit the Shelter");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});

    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);



    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    Gtk::ScrolledWindow* scroller = Gtk::manage(new Gtk::ScrolledWindow);
    scroller->add(*data);
    vbox->pack_start(*scroller, Gtk::PACK_EXPAND_WIDGET, 0);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    
    on_client_role_click();

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////


void Mainwin::on_open_click() {
    try {
        if(!all_data_saved()) return;
        Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_muss = Gtk::FileFilter::create();
    filter_muss->set_name("Shelter Files");
    filter_muss->add_pattern("*.mass");
    dialog.add_filter(filter_muss);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        delete shelter;
        std::string s;
        std::ifstream ifs{dialog.get_filename()};
        std::getline(ifs,s);
        if(s != COOKIE) throw std::runtime_error{"Not a MASS file"};
        std::getline(ifs,s);
        if(s != VERSION) throw std::runtime_error{"Incompatible MASS file version"};
        shelter = new Shelter{ifs};
        shelter->setFilename(dialog.get_filename());
        data->set_text(shelter->name());
        on_client_role_click();
}
    } catch (std::exception& e) {
        std::ostringstream oss;
        oss << "Unable to open file\n" << e.what();
        Gtk::MessageDialog{*this, oss.str(), false, Gtk::MESSAGE_ERROR}.run();
    }
}

void Mainwin::on_save_click() {
    try {
        std::ofstream ofs{"untitled.mass"};
        ofs << COOKIE << '\n';
        ofs << VERSION << '\n';
        shelter->save(ofs);
    } catch (std::exception& e) {
        std::ostringstream oss;
        oss << "Unable to save file: untitled.mass\n" << e.what();
        Gtk::MessageDialog{*this, oss.str(), false, Gtk::MESSAGE_ERROR}.run();
    }
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_undo_click(){
    if (statusu == "animal")
   {
    shelter->undo_animal();
    on_list_animals_click();
}
    else if (statusu == "client")
{
   shelter->undo_client();
   on_list_clients_click();
}
}


void Mainwin::on_new_animal_click() {
    status("");

    Gtk::Dialog adialog{"Animal Type", *this};
    Gtk::ComboBoxText atype;
    atype.append("Dog");
    atype.append("Cat");
    atype.append("Rabbit");
    atype.set_active(0);
    adialog.get_content_area()->pack_start(atype, Gtk::PACK_SHRINK, 0);
    adialog.add_button("Select", 1);
    adialog.add_button("Cancel", 0);
    adialog.show_all();
    if (adialog.run() == 0) return;

    std::string animal_type;
    Gtk::ComboBoxText c_breed;
    if (atype.get_active_row_number() == 0) {
        animal_type = "Dog";
        for(auto& [b, s] : dogs_map) c_breed.append(to_string(b));
    } else if (atype.get_active_row_number() == 1) {
        animal_type = "Cat";
        for (auto& [c, s] : cats_map) c_breed.append(to_string(c));
    } else if (atype.get_active_row_number() == 2) {
        animal_type = "Rabbit";
        for(auto r : rabbit_breeds) c_breed.append(to_string(r));
    }
    c_breed.set_active(0);

    Gtk::Dialog dialog{animal_type + "Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_breed{"Breed"};
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

    dialog.add_button("Add " + animal_type, 1);
    dialog.add_button("Cancel", 0);
    
    dialog.show_all();

    while(dialog.run()) {
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        Animal* animal;
        if (animal_type == "Dog")
            animal = new Dog{dog_breeds[c_breed.get_active_row_number()],
                             e_name.get_text(),
                             (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                             static_cast<int>(s_age.get_value())};
        else if (animal_type == "Cat")
            animal = new Cat{cat_breeds[c_breed.get_active_row_number()],
                             e_name.get_text(),
                             (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                             static_cast<int>(s_age.get_value())};
        else if (animal_type == "Rabbit")
            animal = new Rabbit{rabbit_breeds[c_breed.get_active_row_number()],
                             e_name.get_text(),
                             (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                             static_cast<int>(s_age.get_value())};
        else
            throw std::runtime_error{"Invalid animal type: " + animal_type};
        shelter->add_animal(*animal);
        std::ostringstream oss;
        oss << "Added " << *animal;
        status(oss.str());
        break;
    }
 statusu = "animal";
 on_list_animals_click();
}

void Mainwin::on_list_animals_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_animals(); ++i)
        oss << shelter->animal(i) << '\n';
    data->set_text(oss.str());
    status("List of All Animals");
    statusu = "animal";
}
void Mainwin::on_new_client_click() {
    status("");
    Gtk::Dialog dialog{"Client Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Client", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        if (e_phone.get_text().size() == 0) {e_phone.set_text("*required*"); continue;}
        if (e_email.get_text().size() == 0) {e_email.set_text("*required*"); continue;}

        Client* client = new Client{e_name.get_text(), e_phone.get_text(), e_email.get_text()};
        shelter->add_client(*client);

        std::ostringstream oss;
        oss << "Added " << *client;
        status(oss.str());

        break;
    }
  statusu = "client";
  on_list_clients_click();
}

void Mainwin::on_list_clients_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_clients(); ++i)
        oss << shelter->client(i) << '\n';
    data->set_text(oss.str());
    status("List of All Clients");
   statusu = "client";
}

void Mainwin::on_adopt_animal_click() {
    status("");

    if(shelter->num_animals() == 0) {
        Gtk::MessageDialog{*this, "No animals available to adopt!"}.run();
        return;
    }
    if(shelter->num_clients() == 0) {
        Gtk::MessageDialog{*this, "No clients currently registered!"}.run();
        return;
    }

    Gtk::Dialog *dialog = new Gtk::Dialog{"Adopt an animal",this};

    Gtk::Grid grid;

    Gtk::ComboBoxText c_client;
    for(int i=0; i<shelter->num_clients(); ++i) {
        std::ostringstream oss;
        oss << shelter->client(i);
        c_client.append(oss.str());
    }
    c_client.set_active(0);
    Gtk::Label l_client{"Client"};
    grid.attach(l_client, 0, 1, 1, 1);
    grid.attach(c_client, 1, 1, 2, 1);

    Gtk::ComboBoxText c_animal;
    for(int i=0; i<shelter->num_animals(); ++i) {
        std::ostringstream oss;
        oss << shelter->animal(i);
        c_animal.append(oss.str());
    }
    c_animal.set_active(0);
    Gtk::Label l_animal{"Animal"};
    grid.attach(l_animal, 0, 0, 1, 1);
    grid.attach(c_animal, 1, 0, 2, 1);

    dialog->get_content_area()->add(grid);

    dialog->add_button("Adopt", 1);
    dialog->add_button("Cancel", 0);
    dialog->add_button("Add Client", 2);
    dialog->add_button("Add Animal", 3);
    dialog->show_all();
    int result = dialog->run();

     if (result == 1)
      {  shelter->adopt(shelter->client(c_client.get_active_row_number()),
                       shelter->animal(c_animal.get_active_row_number()));
      delete dialog;
     }
    else if (result == 2)
     {
      delete dialog;
      on_new_client_click();
      on_adopt_animal_click();
     }
    else if (result == 3)
     {
      delete dialog;
      on_new_animal_click();
      on_adopt_animal_click();
     }
    else if (result == 0)
    {
     delete dialog;
    }


}

void Mainwin::on_list_adopted_click() {
    if(shelter->num_clients() == 0) {
        Gtk::MessageDialog{*this, "No clients currently registered!"}.run();
        return;
    }

    Gtk::Dialog dialog{"List Adoptions by a Client", *this};

    Gtk::Grid grid;

    Gtk::ComboBoxText c_client;
    std::vector<int> c2index;
    for(int i=0; i<shelter->num_clients(); ++i) {
        if(shelter->client(i).num_adopted()) {
            std::ostringstream oss;
            oss << shelter->client(i);
            c_client.append(oss.str());
            c2index.push_back(i);
        }
    }
    c_client.set_active(0);
    Gtk::Label l_client{"Client"};
    grid.attach(l_client, 0, 1, 1, 1);
    grid.attach(c_client, 1, 1, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("List Adoptions", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    if(dialog.run()) {
        int index = c2index[c_client.get_active_row_number()];
        Client& client = shelter->client(index);
        std::ostringstream oss;

        for(int i=0; i < client.num_adopted(); ++i)
            oss << client.animal(i) << '\n';
        data->set_text(oss.str());

        std::ostringstream osc;
        osc << "List of animals adopted by " << client;
        status(osc.str());
    }
 statusu = "adopted";
}

// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::status(std::string s) {
    msg->set_text(s);
}


void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Save As",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_ctp = Gtk::FileFilter::create();
    filter_ctp->set_name("Shelter files");
    filter_ctp->add_pattern("*.mass");
    dialog.add_filter(filter_ctp);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.mass");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        try{
        std::ofstream ofs{dialog.get_filename()};
        shelter->setFilename(dialog.get_filename());
        ofs << COOKIE << '\n';
        ofs << VERSION << '\n';
        shelter->save(ofs);
        }catch(std::exception e){
        Gtk::MessageDialog{*this, "Unable to save shelter"}.run();
        
    }
}
}

void Mainwin::on_new_shelter_click() { 
 
 std::string name;
 Gtk::Dialog dialog{"Shelter Information", *this};
 Gtk::Grid grid;
 Gtk::Entry e_name;
 Gtk::Label l_name; 
 grid.attach(l_name, 0, 0, 1, 1);
 grid.attach(e_name, 1, 0, 2, 1);
 dialog.get_content_area()->add(grid);
 dialog.add_button("Enter" ,1);
 dialog.add_button("Cancel", 0);
 dialog.show_all();
 while(dialog.run()) {
    if (e_name.get_text().size() == 0)
     {
      e_name.set_text("*invalid*"); continue;
      } 
     name = e_name.get_text(); 
     delete shelter; 
     shelter = new Shelter(name);
    break;
 }
}

void Mainwin::on_properties_click()
{
  std::ostringstream oss;
  std::ostringstream ost;
  std::ostringstream osc;
  osc << "Name: " << shelter->name();
  oss << "Animals: " << shelter->num_animals();
  ost << "Clients: " << shelter->num_clients();
   Gtk::Dialog dialog{"Shelter Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{osc.str()};
    grid.attach(l_name, 0, 0, 1, 1);

    Gtk::Label l_phone{oss.str()};
    grid.attach(l_phone, 0, 1, 1, 1);

    Gtk::Label l_email{ost.str()};
    grid.attach(l_email, 0, 2, 1, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Cancel", 0);

    dialog.show_all();
    int result = dialog.run();
}


void Mainwin::on_client_report_click() {
  std::ostringstream oss;
 for (int i = 0; i < shelter->num_clients(); i++)
   {
    oss << shelter->client(i) << " ";  
    for (int j = 0; j < shelter->client(i).num_adopted(); j++)
    {
     oss << "\n" << shelter->client(i).animal(j) << "\n";
    }
     oss << "\n";
   }
        data->set_text(oss.str());
        std::ostringstream osc;
        osc << "List of all clients in the shelter";
        status(osc.str());
 }

void Mainwin::on_animal_report_click(){
    
   std::ostringstream oss;
   for (int k = 0; k < shelter->num_animals(); ++k)
   {
        oss << shelter->animal(k) << '\n';
    }
   for (int i = 0; i < shelter->num_clients(); ++i)
   { 
    for (int j = 0; j < shelter->client(i).num_adopted(); ++j)
    {
     oss << "\n" << shelter->client(i).animal(j) << "\n";
    }
     oss << "\n";
   }
    data->set_text(oss.str());
    std::ostringstream osc;
    osc << "List of all animals in the shelter";
    status(osc.str());
}

void Mainwin::on_client_role_click(){
    menuitem_saveas->set_sensitive(false);
    menuitem_save->set_sensitive(false);
    menuitem_test->set_sensitive(false);
    menuitem_open->set_sensitive(false);
    menuitem_rclients->set_sensitive(false);
    menuitem_ranimals->set_sensitive(true);
    menuitem_quit->set_sensitive(false);
    menuitem_newanimal->set_sensitive(false);
    menuitem_listanimal->set_sensitive(false);
    load_shelter_button->set_sensitive(false);
    save_shelter_button->set_sensitive(false);
    new_animal_button->set_sensitive(false);
    list_animals_button->set_sensitive(false);
    quit_button->set_sensitive(false);
 }


void Mainwin::on_staff_role_click(){
    status("");
    Gtk::Dialog dialog{"Please enter your password", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Password"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);
    dialog.get_content_area()->add(grid);

    dialog.add_button("Login", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    while(dialog.run()) {
    if (e_name.get_text().size() == 0 || e_name.get_text() != "staff")
     {
      e_name.set_text("*invalid*"); continue;
      }
     break;
    }
    menuitem_saveas->set_sensitive(false);
    menuitem_save->set_sensitive(false);
    menuitem_test->set_sensitive(false);
    menuitem_open->set_sensitive(false);
    menuitem_rclients->set_sensitive(false);
    menuitem_ranimals->set_sensitive(true);
    menuitem_quit->set_sensitive(false);
    menuitem_newanimal->set_sensitive(true);
    menuitem_listanimal->set_sensitive(true);
    load_shelter_button->set_sensitive(false);
    save_shelter_button->set_sensitive(false);
    new_animal_button->set_sensitive(true);
    list_animals_button->set_sensitive(true);
    quit_button->set_sensitive(false);
}

void Mainwin::on_manager_role_click(){
    status("");
    Gtk::Dialog dialog{"Please enter your password", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Password"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);
    dialog.get_content_area()->add(grid);

    dialog.add_button("Login", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    while(dialog.run()) {
     if (e_name.get_text().size() == 0 || e_name.get_text() != "manager")
     {
      e_name.set_text("*invalid*"); continue;
      }
      break;
    }
    menuitem_saveas->set_sensitive(true);
    menuitem_save->set_sensitive(true);
    menuitem_test->set_sensitive(false);
    menuitem_open->set_sensitive(true);
    menuitem_rclients->set_sensitive(true);
    menuitem_ranimals->set_sensitive(true);
    menuitem_quit->set_sensitive(true);
    menuitem_newanimal->set_sensitive(true);
    menuitem_listanimal->set_sensitive(true);
    load_shelter_button->set_sensitive(true);
    save_shelter_button->set_sensitive(true);
    new_animal_button->set_sensitive(true);
    list_animals_button->set_sensitive(true);
    quit_button->set_sensitive(true);
}


void Mainwin::on_director_role_click(){
   status("");
    Gtk::Dialog dialog{"Please enter your password", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Password"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);
    dialog.get_content_area()->add(grid);

    dialog.add_button("Login", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    while(dialog.run()) {
     if (e_name.get_text().size() == 0 || e_name.get_text() != "director")
     {
      e_name.set_text("*invalid*"); continue;
      }
     break;
    }
    menuitem_saveas->set_sensitive(true);
    menuitem_save->set_sensitive(true);
    menuitem_test->set_sensitive(true);
    menuitem_open->set_sensitive(true);
    menuitem_rclients->set_sensitive(true);
    menuitem_ranimals->set_sensitive(true);
    menuitem_quit->set_sensitive(true);
    menuitem_newanimal->set_sensitive(true);
    menuitem_listanimal->set_sensitive(true);
    load_shelter_button->set_sensitive(true);
    save_shelter_button->set_sensitive(true);
    new_animal_button->set_sensitive(true);
    list_animals_button->set_sensitive(true);
    quit_button->set_sensitive(true);
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name(APP_TITLE);
    auto logo = Gdk::Pixbuf::create_from_file("dog_about.png");
    dialog.set_logo(logo);
    dialog.set_version(VERSION);
    dialog.set_copyright("Copyright 2019");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"William P. Anderson"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"https://commons.wikimedia.org/wiki/File:Creative-Tail-Animal-dog.svg","https://fr.m.wikipedia.org/wiki/Fichier:Boss-icon.png","https://commons.wikimedia.org/wiki/File:Find_it_EZ_Logo.png","https://commons.wikimedia.org/wiki/File:Rie_Black_Icon_User.png","https://en.wikipedia.org/wiki/File:Information.svg","https://commons.wikimedia.org/wiki/File:Icon_Disk_256x256.png","https://commons.wikimedia.org/wiki/File:Human-gnome-session-logout.svg","https://commons.wikimedia.org/wiki/File:Folder_4_icon-72a7cf.svg","https://de.wikipedia.org/wiki/Datei:Icon_Cabinet_02_256x256.png","https://en.m.wikipedia.org/wiki/File:Childbook.png"};
    dialog.set_artists(artists);
    dialog.set_comments("A Animal Shelter.");
    dialog.run();
}

// /////////////
// S I G N A L S
// /////////////

// Signaled when the main window is about to close
// False enables closing the app, true aborts close
bool Mainwin::on_delete_event(GdkEventAny* event) {
    return !all_data_saved();
}

bool Mainwin::all_data_saved() {
  if (shelter->saved()) return true;
  Gtk::MessageDialog dialog{*this, "Unsaved data will be lost", false,Gtk::MESSAGE_WARNING, Gtk::BUTTONS_NONE};

  dialog.add_button("Save", 1);
  dialog.add_button("Discard", 2);
  dialog.add_button("Cancel", 3);
  int response = dialog.run();
  if (response == 1) {        // Save
    try {
        on_save_as_click();
        return true; // save was successful
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to save data", false, Gtk::MESSAGE_ERROR}.run();
        return false;
    }
  } else if (response == 2) { // Discard
    return true;
  } else {                    // Cancel
    return false;
  }
}


