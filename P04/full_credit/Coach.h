#ifndef __COACH_H
#define __COACH_H

#include "stock.h"
class Coach : public Stock
{
private:
  int _passengers;

public:
  Coach(double weight=28.000);
  void add_passengers(int passengers);
  double weight();
};

#endif
