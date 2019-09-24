#include <iostream>
#include "coach.h"
Coach::Coach(double weight) : Stock(weight)
{
  _art = { // Coach
    "               ", // row 0
    " ______________", // row 1
    " | [] [] [] []|", // row 2
    " |            |", // row 3
    "='OO--------OO'", // row 4
    "###############", // row 5
  };
  _passengers = 0;
};
void Coach::add_passengers(int passengers)
{
  try
  {
    _passengers += passengers;
    if (_passengers > 120)
    {
      throw 120;
    }
  }
  catch (int e)
  {
    std::cout << "\nExceeding 120\n" << std::endl;
  }
};
double Coach::weight()
{
  double coach_weight;
  coach_weight = Stock::weight() + (60 * _passengers);
  return coach_weight;
};
