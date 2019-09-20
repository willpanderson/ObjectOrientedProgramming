#include "Train.h"
#include "Locomotive.h"
#include "Coach.h"
#include <vector>

add_locomotive(Locomotive& locomotive): _locomotives
{
   _locomotives.push_back(&locomotive);  I
};

add_coach(Coach& coach){};

double speed(double minutes){};

std::string to_art(){};