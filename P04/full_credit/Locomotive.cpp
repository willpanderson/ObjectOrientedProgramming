#include "locomotive.h"

Locomotive::Locomotive (double weight, double power) : _power(power), Stock(weight)
{
  _art =
  {   // Locomotive
    "      * # @  ", // row 0
    "     . ______", // row 1
    "   _()_||__||", // row 2
    "  ( cse1325 |", // row 3
    " /-OO----OO''", // row 4
    "#############", // row 5
  };

};
double Locomotive::power() {return _power;};
