#include <iostream>
#include "coach.h"

Coach::Coach(double weight) : Stock(weight)
{
  _art = { // Coach
    "               ", 
    " ______________", 
    " | [] [] [] []|", 
    " |            |", 
    "='OO--------OO'", 
    "###############",
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
    std::cout << "\nExceeded Passenger Limit!!!\n" << std::endl;
  }
};

double Coach::weight()
{
  double coach_weight;
  coach_weight = Stock::weight() + (60 * _passengers);
  return coach_weight;
};
