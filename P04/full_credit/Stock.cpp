#include "Stock.h"
#include <virtal>

Stock(): _weight{-nan} {};

Stock(double weight): _weight{0}{};

<<virtual>> double weight(){};

ascii_art(int row){}