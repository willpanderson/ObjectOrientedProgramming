#include "average.h"
#include <iostream>


Average::Average()
{
  _values=0.0;
  _sum=0.0;
}

std::ostream& operator <<(std::ostream& ost, Average& average)
{
 if (average._values != 0)
{
 double averages = average._sum/average._values;
 ost << averages;
}
else
{
 ost<< "undefined";
}
 return ost;
}

std::istream& operator >>(std::istream& ist, Average& average)
{
  double f;
  ist >> f;
  average._sum = f + average._sum;
  average._values++;
  return ist;
 }

Average& Average::operator+=(double value)
{
  this->_sum += value;
  this->_values++;
  return *this;
 }
