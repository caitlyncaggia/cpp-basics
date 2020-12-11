//------------------------------------------ Example 2

#include <iostream>

namespace JeffSpace
{
int value1;
int value2;
}

int value1;

int main()
{

int localVariable;

std::cout << "Input first number " << std::endl;
std::cin >> JeffSpace::value1;

std::cout << "Input second number " << std::endl;
std::cin >> JeffSpace::value2;

value1 = JeffSpace::value1 + JeffSpace::value2;
std::cout << value1 << std::endl;
std::cout << JeffSpace::value1 << std::endl;
return 0;

}

