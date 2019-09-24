#include <cmath>
#include "train.h"


void Train::add_locomotive(Locomotive & locomotive)
{
  _locomotives.push_back(&locomotive);
};

void Train::add_coach(Coach & coach)
{
  _coaches.push_back(&coach);
};

double Train::speed(double minutes)
{
  double power{ 0 };
  double weight{ 0 };

  for (auto i : _locomotives){
    power += i->power();
    weight += i->weight();
  }

  for (auto i : _coaches)
    weight += i->Coach::weight();

  double seconds{minutes * 60};

  return std::sqrt(2 * power * seconds / weight); //m/s mode 
};

std::string Train::to_art()
{
  std::string tempo = "";
  int i = 0;

  for (int i = 0; i < 6; i++ )
  {
    for (auto k : _locomotives){
      tempo += k->Stock::ascii_art(i);
    }
    for (auto l : _coaches){
      tempo += l->Stock::ascii_art(i);
    }
    tempo += "\n";
  }
return tempo;
};
