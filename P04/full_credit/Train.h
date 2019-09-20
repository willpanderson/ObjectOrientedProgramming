#ifndef __TRAIN_H
#define __TRAIN_H

#include <vector>
#include "Locomotive.h"
#include "Coach.h"

class Train{

public:

   add_locomotive(Locomotive& locomotive);
   add_coach(Coach& coach);
   double speed(double minutes);
   string to_art();

private:

   std::vector <Locomotive*> _locomotives;
   std::vector <Coach*> _coaches;
}

#endif
