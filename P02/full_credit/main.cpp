#include "average.h"
#include <iostream>
#include <random>

int main (){
int i;
Average average;
while (i != 0)
{
	std::cout<<"\t=========================\n";
	std::cout<<"\tMerely Average Calculator\n";
	std::cout<<"\t=========================\n";

	std::cout<<"The current value is" << average;

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
	double lower = 0;
  double upper = 100;
  std::uniform_real_distribution<double> unif(lower,upper);
  std::default_random_engine read;
  average = unif(read);
}

else if (i ==9)
{
average._values = 0;
average._sum = 0;
}

else if (i == 0)
{
	std::exit(0); //temp
}
else
	std::cout<<"\n##Invalid Selection##\n\n";
}
}};
