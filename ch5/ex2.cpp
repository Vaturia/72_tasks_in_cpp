#include <iostream>
#include <iomanip>
void printCosts(double costPerKg)
{
    std::cout << "Weight\t  Cost  \n";
    std::cout << "(g)   \t  (rub.)\n";
    for(int i = 1; i <= 10; ++i)
    {
        std::cout << i*100 << "\t  " << std::fixed <<
        std::setprecision(2) << costPerKg * i * 0.1 << '\n';
    }
}
int main()
{
    double cost;
    std::cout << "Enter the price of 1 kg apples: ";
    std::cin >> cost;

    printCosts(cost);
}