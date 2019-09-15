#include "average.h"
#include <iostream>
#include <iomanip>
#include <random>

int main (){
int i;
Average average{};
Average temp{};
while (i != 0)
{
	std::cout<<"\t=========================\n";
	std::cout<<"\tMerely Average Calculator\n";
	std::cout<<"\t=========================\n";

	std::cout<<"The current value is " <<std::setprecision(4) <<std::fixed << average;

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
	std::cout <<"\n";
}

else if (i ==2)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 100.0);
	double number = dis(gen);
	std::cout << "\n";
  average+= number;
 }

else if (i ==9)
{
	average = temp;
}

else if (i == 0)
{
	std::exit(0); //temp
}

else
	std::cout<<"\n##Invalid Selection##\n\n";
}
}
