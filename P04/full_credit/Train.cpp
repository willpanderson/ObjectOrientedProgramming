#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include "stock.h"
#include "train.h"
#include "locomotive.h"
#include "coach.h"

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

  for (auto i : _locomotives)
    power += i->power();

  double seconds{minutes * 60};

  return std::sqrt(2 * power * seconds / weight);
};

std::string Train::to_art(){};
