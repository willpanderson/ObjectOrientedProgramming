//#include "average.h"
#include <iostream>
//#include <string>
//#include <cstdlib> 

int main (){
//std::string j;
int i;
Average average;
while (i != 0)
{
	std::cout<<"\t=========================\n";
	std::cout<<"\tMerely Average Calculator\n";
	std::cout<<"\t=========================\n";

	std::cout<<"The current value is" << average.;

	std::cout<<"\n\n1 - Enter a new value";
	std::cout<<"\n2 - Auto enter a random value";
	std::cout<<"\n9 - Clear the calculator";
	std::cout<<"\n0 - Exit\n\n";

	std::cout<<"Selection? ";
	std::cin>>i;

if (i ==1)
{
	std::cout<<"Value\n"; //temp

}

else if (i ==2)
{
	std::cout<<"Auto enter\n"; //temp
}

else if (i ==9)
{
	std::cout<<"Clear\n"; //temp
}

else if (i == 0)
{
	std::exit(0); //temp
}
else
	std::cout<<"\n##Invalid Selection##\n\n";	
}
}
