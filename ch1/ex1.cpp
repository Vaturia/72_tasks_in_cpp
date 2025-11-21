#include <iostream>
int getNumberMonth()
{
    int number;

    while(1)
    {
        std::cout << "Enter number of month (number from 1 to 12): ";
        std::cin >> number;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Error input. Please try enter again.\n";
            continue;
        }
        if(number < 1 || number > 12)
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Error input. Input must be a number from 1 to 12!\n";
            continue;
        }
        return number;
    }
}
void printMonth(int numberOfMonth)
{
    switch(numberOfMonth)
    {
        case 1:
        case 2:
        case 12:
            std::cout << "Winter\n";
            break;
        case 3:
        case 4:
        case 5:
            std::cout << "Spring\n";
            break;
        case 6:
        case 7:
        case 8:
            std::cout << "Summer\n";
            break;
        case 9:
        case 10:
        case 11:
            std::cout << "Autumn\n";
            break;
        default:
            break;
    }
}
int main()
{
    printMonth(getNumberMonth());

}