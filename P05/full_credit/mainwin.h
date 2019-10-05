#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        Mainwin(Store& store);
        virtual ~Mainwin();

    protected:
        on_new_store_click();
        on_add_sweet_click();
        on_list_sweets_click();
        on_place_order_click();
        on_list_orders_click();
        on_about_click();
        on_quit_click();
        ~reset_sensitivity();
        
    private:
        Store *_store;
        Gtk::MenuItem *menuitem_add_sweet;
        Gtk::MenuItem *menuitem_list_sweets;
        Gtk::MenuItem *menuitem_place_orders;
        Gtk::MenuItem *menuitem_list_orders;
        Gtk::ToolButton *add_sweet_button;
        Gtk::ToolButton *list_sweets_button;
        Gtk::ToolButton *place_order_button;
        Gtk::ToolButton *list_orders_button;
        Gtk::Label *data;
        Gtk::Label *msg;
    
};
#endif 

