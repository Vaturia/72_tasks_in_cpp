#include <iostream>
#include <iomanip>
void purchaseCostPrint(double purchaseAmount)
{
    int percent = 0;
    if(purchaseAmount > 1000){percent = 5;}
    else if( purchaseAmount > 500){percent = 3;};

    std::cout << "You are given a " << percent << "% discount.\n";
    std::cout << "Amount including discount: ";
    std::cout << std::fixed;
    std::cout << std::setprecision(2) <<
    purchaseAmount - (purchaseAmount / 100 * percent) << '\n';
}
int main()
{
    double purchaseAmount;
    std::cout << "Enter purchase amount: ";
    std::cin >> purchaseAmount;
    purchaseCostPrint(purchaseAmount);
}