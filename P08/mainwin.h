#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"

const std::string APP_TITLE{"Mavs Animal Shelter Software"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};
const std::string COOKIE{"M⅍S1"};
const std::string MASS{".mass"};

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
        //  void on_new_shelter_click();       // Create a new shelter
        void on_save_as_click();
        bool on_delete_event(GdkEventAny* event);
        bool safe_to_exit();
        bool all_data_saved(); 
        void on_about_click();
        void status(std::string s);        // Set the status message
    private:
        Shelter *shelter;                  // Current animal shelter
        Gtk::Label *data;                 // Display for data area
        Gtk::Label *msg;                   // Status message display
};
#endif 

