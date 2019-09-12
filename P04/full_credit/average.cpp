#include "average.h" 
#include <iostream>


Average::Average() : _sum{sum},_values{value};

std::ostream& operator <<(std::ostream& ost, Average& average);
{
 if (_value != 0)
{
 double averages = _sum/_value;
 ost << averages;
}
else
{
 ost<<"undefined";
}
 return *this;
}

std::istream& operator >>(std::istream& ist, Average& average);
{

 }
Average& operator+=(double value);
{
 }

