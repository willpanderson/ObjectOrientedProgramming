#include "average.h" 
#include <iostream>


Average::Average() : _sum{sum},_values{value};

std::ostream& operator <<(std::ostream& ost, Average& average);
{
 if (_value != 0)
{
 average = _sum/_value;
 ost << average << std::endl
}
else
{
 ost<<"undefined"<< std::endl;
}
 return *this;
}

std::istream& operator >>(std::istream& ist, Average& average);
{
 }
Average& operator+=(double value);
{
 }

