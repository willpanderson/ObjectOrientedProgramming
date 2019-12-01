#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"

const std::string APP_TITLE{"Mavs Animal Shelter Software"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};
const std::string COOKIE{"MASS1"};
const std::string EXT{".mass"};

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_open_click();              // Load the shelter's data
        void on_save_click();              // Save the shelter's data
        void on_quit_click();              // Exit the application
        void on_new_animal_click();        // Create a new animal
        void on_list_animals_click();      // List all animals
        void on_new_client_click();        // Create a new client
        void on_list_clients_click();      // List all clients
        void on_adopt_animal_click();      // A client adopts an animal
        void on_list_adopted_click();      // List all adoptions by a client
        void on_new_shelter_click();       // Create a new shelter
        void on_save_as_click();
        bool on_delete_event(GdkEventAny* event);
        bool safe_to_exit();
        bool all_data_saved();
        void on_about_click();
        void on_client_report_click();
        void on_animal_report_click();
        void on_client_role_click();
        void on_properties_click();
        void on_staff_role_click();
        void on_manager_role_click();
        void on_director_role_click();
        void status(std::string s);        // Set the status message
    private:
        Shelter *shelter;                  // Current animal shelter
        Gtk::Label *data;                 // Display for data area
        Gtk::Label *msg;                   // Status message display
        Gtk::MenuItem *menuitem_file;
        Gtk::MenuItem *menuitem_open;
        Gtk::MenuItem *menuitem_save;
        Gtk::MenuItem *menuitem_saveas;
        Gtk::MenuItem *menuitem_test;
        Gtk::MenuItem *menuitem_properties;
        Gtk::MenuItem *menuitem_quit;
	Gtk::MenuItem *menuitem_undo;
	Gtk::MenuItem *menuitem_edit;
        Gtk::MenuItem *menuitem_role;
        Gtk::MenuItem *menuitem_clientr;
        Gtk::MenuItem *menuitem_staff;
        Gtk::MenuItem *menuitem_manager;
        Gtk::MenuItem *menuitem_director;
        Gtk::MenuItem *menuitem_animal;
        Gtk::MenuItem *menuitem_newanimal;
        Gtk::MenuItem *menuitem_listanimal;
        Gtk::MenuItem *menuitem_show_adoptions;
        Gtk::MenuItem *menuitem_client;
        Gtk::MenuItem *menuitem_newclient;
        Gtk::MenuItem *menuitem_listclient;
        Gtk::MenuItem *menuitem_adopt;
        Gtk::MenuItem *menuitem_list_adoptions;
        Gtk::MenuItem *menuitem_report;
        Gtk::MenuItem *menuitem_ranimals;
        Gtk::MenuItem *menuitem_rclients;
        Gtk::ToolButton *load_shelter_button;
        Gtk::ToolButton *save_shelter_button;
        Gtk::ToolButton *new_animal_button;
        Gtk::ToolButton *list_animals_button;
	Gtk::ToolButton *new_client_button;
        Gtk::ToolButton *client_list_button;
        Gtk::ToolButton *adopt_animal_button;
        Gtk::ToolButton *adopt_list_button;
        Gtk::ToolButton *quit_button;
};
#endif
