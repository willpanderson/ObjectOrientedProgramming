#include "mainwin.h"
#include <cmath>


Mainwin::Mainwin():
comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})},
scale{Gtk::manage(new Gtk::Scale)},
label{Gtk::manage(new Gtk::Label{"0"})}
{
	Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
	add (*vbox);
	set_title("Functions");
	set_default_size(200, 100);

	vbox->pack_start(*scale);
	scale->set_range(0.0, 100.0);
	scale->set_increments(1.0, 1.0);
	scale->signal_value_changed().connect([this] {this->on_scale_value_changed();});

	vbox->pack_start(*comboboxtext);
	comboboxtext->append("Select A Function");
	comboboxtext->append("Trignometric Cosine");
	comboboxtext->append("Square Root");
	comboboxtext->append("Natural Log");
	comboboxtext->set_active(0);
	comboboxtext->signal_changed().connect([this] {this->oncomboboxtext_activate();});

	vbox->pack_start(*label);
	vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_scale_value_changed()
{
    *s2 = scale->get_value();

}

void Mainwin::oncomboboxtext_activate()
{
	if (comboboxtext->get_active_row_number() == 1)
	{
		label->set_text(std::to_string(cos (*s2)));
	}

	else if (comboboxtext->get_active_row_number() == 2)
	{
		label->set_text(std::to_string(sqrt (*s2)));
	}

	else if (comboboxtext->get_active_row_number() == 3)
	{
		if (*s2 == 0.0)
		{
			std::string text = "Negative Infinity";
			label->set_text(text);
		}
		else
		{
		  label->set_text(std::to_string(log (*s2)));
		}
	}
}
