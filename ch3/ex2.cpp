#include <iostream>
int EvenNumberSum(int countNumbers)
{
    int result = 0;
    for(int i = 1; i <= countNumbers; ++i)
    {
        if(i % 2 == 0)
        {
            result += i;
        }
    }
    return result;
}
int main()
{
    int countNum = 0;
    std::cout << "Enter the number of numbers to be summed: ";
    std::cin >> countNum;
    std::cout << "Summary of " << countNum << " positive even numbers is: "
    << EvenNumberSum((countNum)) << '\n';
}