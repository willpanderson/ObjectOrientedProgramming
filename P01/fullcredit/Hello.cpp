// William Anderson 1001639071

#include <iostream>  
#include <string>


int main()
{
char input[100];

std::cout << "Hello, please enter your name: ";

std::cin.getline(input,sizeof(input));
 
std::cout << "Hello " << input << std::endl;

return 0;
}


 
