#include "Train.h"
#include "Locomotive.h"
#include "Coach.h"
#include <vector>

Locomotive::add_locomotive(Locomotive& locomotive): _locomotives
{
   _locomotives.push_back(&locomotive);  I
};

Coach::add_coach(Coach& coach){
   _coaches.push_back(&Coach);
};

double speed(double minutes){};

std::string to_art()
{
    "      * # @  ",
    "     . ______",
    "   _()_||__||",
    "  ( cse1325 |",
    " /-OO----OO''",
    "#############",

    "               ",
    " ______________",
    " | [] [] [] []|",
    " |            |",
    "='OO--------OO'",
    "###############",
};