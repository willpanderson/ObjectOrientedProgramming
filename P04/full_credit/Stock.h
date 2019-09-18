#ifndef __STOCK_H
#define __STOCK_H

#include <string>
#include <vector>

class Stock {
  
public:
   Stock();
   Stock(double weight);
   virtual double weight();
   string ascii_art (int row);

private:
   double _weight;
   vector <string> _art;
}

#endif