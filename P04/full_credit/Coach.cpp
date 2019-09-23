#include <iostream>
#include "coach.h"

Coach::Coach(double weight) : Stock(weight) {};

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
    std::cout << "\nExceeding Passenger Limit!\n" << std::endl;
  }
};
double Coach::weight()
{
  Stock::weight() + (60 * _passengers);
  return Stock::weight() + (60 * _passengers);
};
