#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H
#include "stock.h"
class Locomotive : public Stock
{
private:
  double _power;
public:
  Locomotive(double weight=80.000, double power=13.500);
  double power();
};

#endif
