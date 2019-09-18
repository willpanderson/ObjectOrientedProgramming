//#include "Locomotive.h"
//#include "Train.h"
//#include "Coach.h"
//#include "Stock.h"
#include <iostream>

//include other stuff i dont know of as yet

int main (){

int selection;
while (selection != 0)
{
   std::cout<<"\n\t===================\n";
   std::cout<<"\tThe CSE1325 Express\n";
   std::cout<<"\t===================\n\n\n";

   //std::cout<<train.to_art()<<"\n";
   
   std::cout<<" Minutes  |    1    |    5    |    15   |    30   |    60   \n";
   std::cout<<" ---------|---------|---------|---------|---------|---------\n";
   std::cout<<"   m/s    |         |         |         |         |         \n\n";
   
   std::cout<<"1 - Add a locomotive\n";
   std::cout<<"2 - Add an empty coach\n";
   std::cout<<"9 - Clear the train\n";
   std::cout<<"0 - Exit\n";

   std::cout<<"\nCommand? ";
   std::cin >> selection;
   std::cout <<"\n";

   }
}

