#ifndef TRAIN_H
#define TRAIN_H
#include "stock.h"
#include "locomotive.h"
#include "coach.h"

class Train
{
private:
  // Teacher *m_teacher;
  std::vector<Locomotive* > _locomotives;
  std::vector<Coach* > _coaches;
public:
  void add_locomotive(Locomotive & locomotive);
  void add_coach(Coach & coach);
  double speed(double minutes);
  std::string to_art();
};

#endif
