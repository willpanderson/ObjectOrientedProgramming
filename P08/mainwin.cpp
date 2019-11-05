#include "mainwin.h"
#include "shelter.h"
#include <iostream>

Mainwin::Mainwin()
{

    // ///////////////// //
    // G U I   S E T U P //
    // ///////////////// //

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
  std::string name = "";
  int age = -1;
  int gender = -1;
  int breed = -1;
  Gender _gender;
  Breed  _breed;
  Gtk::Dialog *dialog = new Gtk::Dialog{"Add A New Animal", *this};
  
  Gtk::HBox b_name;
  
  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(15);
  b_name.pack_start(l_name, Gtk::PACK_SHRINK);
  
  Gtk::Entry e_name;
  e_name.set_max_length(50);
  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
  
  Gtk::HBox b_agex;
  
  Gtk::Label l_agex{"Age:"};
  l_agex.set_width_chars(15);
  b_agex.pack_start(l_agex, Gtk::PACK_SHRINK);

  Gtk::Entry e_agex;
  e_agex.set_max_length(50);
  b_agex.pack_start(e_agex, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_agex, Gtk::PACK_SHRINK);

  
  Gtk::HBox b_options;
  Gtk::Label l_options{"Gender:"};
  l_options.set_width_chars(15);
  b_options.pack_start(l_options);

      Gtk::ComboBoxText options;
      options.append("Male");
      options.append("Female");
      options.set_active(0);
      b_options.pack_start(options, Gtk::PACK_SHRINK);
      dialog->get_vbox()->pack_start(b_options);


  Gtk::HBox b_options2;
  Gtk::Label l_options2{"Breed:"};
  l_options2.set_width_chars(15);
  b_options2.pack_start(l_options2);

      Gtk::ComboBoxText options2;
      options2.append("Bloodhound");
      options2.append("Rotwiler");
      options2.append("Beagle");
      options2.append("Pitbull");
      options2.append("Bulldog");
      options2.append("Chihuahua");
      options2.append("Samoyed");
      options2.append("Poodle");
      options2.set_active(0);
      b_options2.pack_start(options2, Gtk::PACK_SHRINK);
      dialog->get_vbox()->pack_start(b_options2);

  dialog->add_button("Cancel", 0);
  dialog->add_button("Create", 1);
  dialog->show_all(); //Throws an GTK::critical error

  int result; // of the dialog (1 = OK)
  bool fail = true;  // set to true if any data is invalid
  
  while (fail) {
        fail = false;  // optimist!
        result = dialog->run();
        if (result != 1) {

            msg->set_text("New animal entry cancelled");
            delete dialog;
            return;}
        try {
            age = std::stod(e_agex.get_text());
        } catch(std::exception e) {
            e_agex.set_text("### Invalid ###");
            fail = true;
        }
        name = e_name.get_text();
        gender = options.get_active_row_number();
        breed = options2.get_active_row_number();
        if (name.size() == 0) {
            e_name.set_text("### Invalid ###");
            fail = true;
    }
    delete dialog;
  }

  if (gender == 0)
  {
   _gender = Gender::Male;
  }
  else if (gender == 1)
  {
   _gender = Gender::Female;
  }
  
  if (breed == 0)
  {
   _breed = Breed::Bloodhound;
  }
  else if (breed == 1)
  {
   _breed = Breed::Rotwiler;
  }
  else if (breed == 2)
  {
   _breed = Breed::Beagle;
  }
  else if (breed == 3)
  {
   _breed = Breed::Pitbull;
  }
  else if (breed == 4)
  {
   _breed = Breed::Bulldog;
  }
  else if (breed == 5)
  {
   _breed = Breed::Chihuahua;
  }
  else if (breed == 6)
  {
   _breed = Breed::Samoyed;
  }
  else if (breed == 7)
  {
   _breed = Breed::Poodle;
  }

 Dog animal{_breed, name, _gender, age};
 //shelter->add_animal(animal); Throws a seg fault
 
}

void Mainwin::on_list_animals_click()
{
 int i;
 std::string s = "<span size='large' weight='bold'>";
 for (int i = 0; i < shelter->num_animals(); i++)
 {
  s += shelter->animal(i).to_string(); + "\n";
 }
 s+="</span>";
 label->set_text(s);
 msg->set_text("List of Animals in the Shelter");
}

void Mainwin::on_quit_click()
{
 close();
}


