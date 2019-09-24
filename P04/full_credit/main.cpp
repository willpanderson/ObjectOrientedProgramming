#include "Train.h"
#include "coach.h"
#include "locomotive.h"
#include "stock.h"
#include <iostream>
#include <iomanip>


int main(){

  Locomotive locomotive{80000, 13500};
  Coach coach{28000};
  Train Train;
  Train ClearTheTrain;
  std::string s;
  int selection;
  while(true) 
  {
    std::cout << "R(
                =========================
                    The CSE1325 Express
                =========================
                    )";
                
  std::cout<< Train.to_art() << R"(
  Minutes |    1         5         15        30       60
  --------|---------|---------|---------|---------|----------
  m/s     |
                                )";


  std::cout.width(9);
  std::cout << Train.speed(1) << '|';
  std::cout.width(9);
  std::cout << Train.speed(5) << '|';
  std::cout.width(9);
  std::cout << Train.speed(15) << '|';
  std::cout.width(9);
  std::cout << Train.speed(35) << '|';
  std::cout.width(9);
  std::cout << Train.speed(65);
 

  std::cout << "1 - \nAdd a locomotive\n";
  std::cout << "2 - Add an empty coach\n";
  std::cout << "9 - Clear Train\n";
  std::cout << "0 - Exit\n";
  std::cout<< "\n\nCommand? ";

  std::getline(std::cin, s);
  
  try 
  {
    command = std::stoi(s);
      
    if(command == 0) 
    {
      std::exit(0);
    } 

    else if (command == 1) 
    {
      Train.add_locomotive(locomotive);
    }

    else if (command == 2) 
    {
      Train.add_coach(coach) 
    } 
      
    else if (command == 9)
    {
      Train = ClearTheTrain;
    } 

    else 
    {
      std::cerr << "### Invalid Entry!! ###\n\n";
    }

  }

catch(std::invalid_argument e)
  {
    std::cerr << "### Invalid Entry!! ###\n\n";
  }
}
}
