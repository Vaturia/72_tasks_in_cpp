#include <iostream>
#include <iomanip>
double convertToKm(double miles_distance)
{
    return miles_distance * 1.0668;
}
int main()
{
    double distance = 0.0;
    std::cout << "Enter distance in miles: ";
    std::cin >> distance;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << int(distance) <<" miles = " <<  convertToKm(distance) << " km\n";
}