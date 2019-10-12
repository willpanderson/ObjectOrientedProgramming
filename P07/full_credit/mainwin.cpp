#include "mainwin.h"
#include <cmath>


Mainwin::Mainwin()
:
button{Gtk::manage(new Gtk::Button{"Square Root"})},
button2{Gtk::manage(new Gtk::Button{"Trignometric Cosine"})},
button3{Gtk::manage(new Gtk::Button{"Natural Log"})},
scale{Gtk::manage(new Gtk::Scale)},
label{Gtk::manage(new Gtk::Label{"-nan"})}
{
	Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
	add (*vbox);
	set_title("William Anderson 1");
	set_default_size(200, 100);

	vbox->pack_start(*scale);
	scale->set_range(0.0, 100.0);
	scale->set_increments(1.0, 1.0);
	scale->signal_value_changed().connect([this] {this->on_scale_value_changed();});

	vbox->pack_start(*button);
	button->set_tooltip_markup("This will take the square of the selected number");
	button->signal_clicked().connect([this] {this->on_button_click(1);});

	vbox->pack_start(*button2);
	button2->set_tooltip_markup("This will take the cosine the selected number");
	button2->signal_clicked().connect([this] {this->on_button_click(2);});

	vbox->pack_start(*button3);
	button3->set_tooltip_markup("This will take natural log the selected number");
	button3->signal_clicked().connect([this] {this->on_button_click(3);});

	vbox->pack_start(*label);
	vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_scale_value_changed()
{
    *s2 = scale->get_value();
}

void Mainwin::on_button_click(int button) {
	*s2 = scale->get_value();//needed if scale dosent change when button is pressed
	if (button == 1)
	{

		label->set_text(std::to_string(sqrt (*s2)));
	}

	else if (button == 2)
	{
		label->set_text(std::to_string(cos (*s2)));
	}

	else if (button == 3)
	{
		if (*s2 == 0.0)
		{
			label->set_text("Undefined");
		}
		else
		{
		  label->set_text(std::to_string(log (*s2)));
		}
	}
}
