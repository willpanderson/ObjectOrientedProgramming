#ifndef __STOCK_H
#define __STOCK_H

#include <vector>
#include <string>

class Stock

{

private:
  double _weight;

protected:
  std::vector<std::string> _art;

public:
  Stock();
  Stock(double weight);
  std::string ascii_art(int row);
  virtual double weight();

};

#endif
