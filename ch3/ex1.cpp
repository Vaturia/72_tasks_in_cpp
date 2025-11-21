#include <iostream>
#include <iomanip>
double CalculateSpeed(double distance, double minutes)
{
    int seconds = (minutes - static_cast<int>(minutes)) * 100 + static_cast<int>(minutes) * 60;

    return distance / seconds * 3.6;
}
int main()
{
    double distance, minutes;
    std::cout << "Enter distance (meters): ";
    std::cin >> distance;
    std::cout << "Enter time (minutes.seconds): ";
    std::cin >> minutes;

    std::cout << std::fixed;
    std::cout << "You ran at speed " <<
    std::setprecision(2) <<
    CalculateSpeed(distance, minutes) << " km/hour\n";
}