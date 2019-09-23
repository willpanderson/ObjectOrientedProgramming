#include "Locomotive.h"
#include "Train.h"
#include "Coach.h"
#include "Stock.h"
#include <iostream>

Locomotive locomotive{};
Coach mcoach{};
int main (){

int selection = 21;

while (selection != 0)
{
   std::cout<<"\n\t===================\n";
   std::cout<<"\tThe CSE1325 Express\n";
   std::cout<<"\t===================\n\n\n";

   //std::cout<<train.to_art()<<"\n";
   
  std::cout<<" Minutes  |    1    |    5    |    15   |    30   |    60   \n";
  std::cout<<" ---------|---------|---------|---------|---------|---------\n";
  std::cout<<"   m/s    |         |         |         |         |         \n\n";
   
//std::cout<<Stock::to_art,,"\n";
   
   std::cout<<"1 - Add a locomotive\n";
   std::cout<<"2 - Add an empty coach\n";
   std::cout<<"9 - Clear the train\n";
   std::cout<<"0 - Exit\n";

   std::cout<<"\nCommand? ";
   std::cin >> selection;
   std::cout <<"\n";

if (selection ==1)
{
  locomotive.push_back(&locomotive);
}

else if (selection ==2)
{
  mcoach.push_back(&coach);
 }

else if (selection ==9)
{
	
}

else if (selection == 0)
{
	std::exit(0); 
}

else
	std::cout<<"\n##Invalid Selection##\n\n";
}
}
}


