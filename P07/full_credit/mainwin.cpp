#include "mainwin.h"
#include <cmath>


Mainwin::Mainwin() : 
{
	Gtk::VBox *vbox = Gtk::manage(new Gtk::Vbox);
	add (*vbox);
	set_title("Math Functions");

	vbox->pack_start(*comboboxtext);
	comboboxtext->append("Square");
	comboboxtext->append("Square Root");
	comboboxtext->append("Natural Log");
	comboboxtext->set_active(1);
	comboboxtext->signal_changed().connect([this] {this->on_comboboxtext_activate();});
	
vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_entry_activate()
{
	std::stringstream text;
	text << this entry->get_text();
	text >> *s2;
}

Void Mainwin::oncomboboxtext_activate()
{
	if (comboboxtext->get_row_number() == 1)
	{
		label->set_text(std::to_string(s2*s2);
	}

	else if (comboboxtext->get_row_number() == 2)
	{
		label->set_text(std::to_string(sqrt(s2)));
	}
	
	else if (comboboxtext->get_row_number() == 3)
	{
		label->set_text(std::to_string(log10(s2)));
	}
}