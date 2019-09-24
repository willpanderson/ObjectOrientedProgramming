#ifndef COACH_H
#define COACH_H
#include "stock.h"
class Coach : public Stock
{
private:
  int _passengers = 0;
public:
  Coach(double weight=28.000);
  void add_passengers(int passengers);
  virtual double weight() override;

};

#endif
