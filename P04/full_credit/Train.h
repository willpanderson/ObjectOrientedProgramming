#ifndef __TRAIN_H
#define __TRAIN_H

#include <vector>

class Train{

public:

   add_locomotive(Locomotive& locomotive);
   add_coach(Coach& coach);
   double speed(double minutes);
   string to_art();

private:

   vector <Locomotive*> _locomotives;
   vector <Coach*> _coaches;
}

#endif


