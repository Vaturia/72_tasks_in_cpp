#include <iostream>
bool numberIsPalindrom(int number)
{
    bool first_last = number % 10 == number / 1000;
    bool second_third = (number / 100) % 10 ==  (number / 10) % 10;
    return (first_last && second_third);
}
int main()
{
    int number;
    std::cout << "Enter number(1000-9999):";
    std::cin >> number;
    if(numberIsPalindrom(number))
    {
        std::cout << number << " is a palindrom\n";
    }
    else
    {
        std::cout << number << " is not a palindrom\n";
    }
}