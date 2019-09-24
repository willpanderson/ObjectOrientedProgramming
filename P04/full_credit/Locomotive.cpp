#include "locomotive.h"

Locomotive::Locomotive (double weight, double power) : _power(power), Stock(weight)
{
  _art =
  {
    "      * # @  ", 
    "     . ______", 
    "   _()_||__||", 
    "  ( cse1325 |", 
    " /-OO----OO''", 
    "#############", 
  };

};
double Locomotive::power() {return _power;};
