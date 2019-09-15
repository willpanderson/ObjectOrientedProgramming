#include "average.h"
#include <iostream>


Average::Average(){
  _value = 0;
  _sum = 0;
}

std::ostream& Average::operator <<(std::ostream& ost, Average& average)
{
 if (_value != 0)
{
 double averages = _sum/_value;
 ost << averages;
}
else
{
 ost<< "undefined";
}
 return ost;
}

std::istream& Average::operator >>(std::istream& ist, Average& average)
{
  double f;
  ist >> f;
  average._sum = f + average._sum;
  average._value++;
  return ist;
 }
Average& Average::operator+=(double value)
{
  this._sum += value;
  this._value++;
  return *this;
 }
