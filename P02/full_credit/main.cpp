#include "average.h"
#include <iostream>
#include <cstdlib>

int main (){
int i;
Average average;
while (i != 0)
{
	std::cout<<"\t=========================\n";
	std::cout<<"\tMerely Average Calculator\n";
	std::cout<<"\t=========================\n";

	std::cout<<"The current value is " << average;

	std::cout<<"\n\n1 - Enter a new value";
	std::cout<<"\n2 - Auto enter a random value";
	std::cout<<"\n9 - Clear the calculator";
	std::cout<<"\n0 - Exit\n\n";

	std::cout<<"Selection? ";
	std::cin>>i;

if (i ==1)
{
	std::cout<<"Value? ";
	std::cin >>average;

}

else if (i ==2)
{
  double number = rand() % 100; 
  std::cout << number;
  average+= number;
 } 

else if (i ==9)
{
average.Clear();
}

else if (i == 0)
{
	std::exit(0); //temp
}
else
	std::cout<<"\n##Invalid Selection##\n\n";
}
}
