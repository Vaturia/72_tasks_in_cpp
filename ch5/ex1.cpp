#include <iostream>
int ConvetToHourMinute(int &minutes)
{
    int hours = minutes / 60;
    minutes = minutes % 60;
    return hours;
}
int main()
{
    int minutes, hours;
    std::cout << "Enter time enterval (in minutes): ";
    std::cin >> minutes;
    std::cout << minutes << " minutes = " << ConvetToHourMinute(minutes)
    << " h. " << minutes << " min.\n";
}