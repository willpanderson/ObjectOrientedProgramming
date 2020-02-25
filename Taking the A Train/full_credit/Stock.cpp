#include "stock.h"
#include <cmath>
#include <iostream>


Stock::Stock () : _weight(NAN){ };

Stock::Stock (double weight) : _weight(weight){ };

std::string Stock::ascii_art(int row)
{
  return _art[row];
};

double Stock::weight()
{
  return _weight;
};
