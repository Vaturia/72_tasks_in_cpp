#include <iostream>
int main()
{
    int first, second;
    std::cout << "Enter 2 integer: ";
    std::cin >> first >> second;
    if(first < second)
    {
        std::cout << first << " less " << second << '\n';
    }
    else if(second < first)
    {
        std::cout << second << " less " << first << '\n';
    }
    else
    {
        std::cout << "Numbers are equal\n";
    }

    return 0;

}