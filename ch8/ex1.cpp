#include <iostream>
#include <string>
int main()
{
    int number;
    std::string str;
    std::cout << "Enter number from 1 to 99: ";
    std::cin >> number;
    switch (number % 10)
    {
    case 1:
        str = " копейка";
        break;
    case 2:
    case 3:
    case 4:
        str = " копейки";
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0:
        str = " копеек";
        break;
    default:
        break;
    }
    std::cout << number << str << std::endl;
}