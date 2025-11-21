#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
void startTimer(int hours, int minutes, int seconds) {
    int total_seconds = hours * 3600 + minutes * 60 + seconds;

    while (total_seconds >= 0) {
        int mins = total_seconds / 60;
        int secs = total_seconds % 60;

        if (mins > 0) {
            std::cout << "Left " << mins << " minutes " << secs << " seconds\n";
        } else {
            std::cout << "Left " << secs << " seconds\n";
        }

        if (total_seconds-- > 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    std::cout << "Timer finish!\n";
}
int main()
{
    std::string in;
    std::stringstream input;
    std::cout << "Enter time in format(hh mm ss) each parameter can be 0): ";
    std::getline(std::cin, in);
    input << in;
    int hour, minute, second;
    input >> hour >> minute >> second;

    startTimer(hour, minute, second);

    return 0;

}