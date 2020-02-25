#include "train.h"
#include "coach.h"
#include "locomotive.h"
#include "stock.h"
#include <iostream>
#include <iomanip>


int main(){

  Locomotive locomotive{80000, 13500};
  Coach coach{28000};
  Train train;
  std::string s;
  int command;
  while(true) 
  {
    std::cout << R"(
                =========================
                    The CSE1325 Express
                =========================
)"
                << train.to_art() << R"(
  Minutes |     1        5         15        35        55
  --------|---------|---------|---------|---------|----------
  m/s     |)";


  std::cout.width(9);
  std::cout << train.speed(1) << '|';
  std::cout.width(9);
  std::cout << train.speed(5) << '|';
  std::cout.width(9);
  std::cout << train.speed(15) << '|';
  std::cout.width(9);
  std::cout << train.speed(35) << '|';
  std::cout.width(9);
  std::cout << train.speed(55);
 

  std::cout << "\n\n\n1 - Add a locomotive\n";
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
      std::exit(0); //I prefer to exit the program rather than break
    } 

    else if (command == 1) 
    {
      train.add_locomotive(locomotive);
    }

    else if (command == 2) 
    {
      train.add_coach(coach); 
    } 
      
    else if (command == 9)
    {
      Train ClearTrain;
      train = ClearTrain;
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
