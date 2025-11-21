#include <iostream>
double rideCost(double distance, double fuelConsumpt, double costOfGas)
{
    return ((fuelConsumpt / 100) * (distance * 2) * costOfGas);
}
int main()
{
    double distance, fuelConsumt, costOfGas;
    std::cout << "Enter the value for calculation\n";

    std::cout << "Distance to house (km): ";
    std::cin >> distance;

    std::cout << "Fuel consuption (liters per 100 km): ";
    std::cin >> fuelConsumt;

    std::cout << "Price per liter of gasoline: ";
    std::cin >> costOfGas;

    std::cout << "A trip to the house and back will cost: "
    << rideCost(distance, fuelConsumt, costOfGas) << '\n';
}