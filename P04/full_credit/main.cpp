//#include "Locomotive.h"
//#include "Train.h"
//#include "Coach.h"
//#include "Stock.h"
#include <iostream>

//include other stuff i dont know of as yet

int main (){

int selection = 21;

while (selection != 0)
{
   std::cout<<"\n\t===================\n";
   std::cout<<"\tThe CSE1325 Express\n";
   std::cout<<"\t===================\n\n\n";

   //std::cout<<train.to_art()<<"\n";
   
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
	
}

else if (selection ==2)
{

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
}

