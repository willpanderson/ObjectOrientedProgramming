#include "locomotive.h"

Locomotive::Locomotive (double weight, double power) :
                       _power(power), Stock(weight){ };

double Locomotive::power() {return _power;};
