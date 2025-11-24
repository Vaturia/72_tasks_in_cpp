#include <iostream>
#include <stdlib.h>
#include <array>
#include <map>
#include <ctime>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <chrono>
#include <thread>
/*using graphNumber = std::array<char,12>;
static std::map<unsigned int, graphNumber> numbers
{
    {0, {' ', '_', '_', ' ',
         '|', ' ', ' ', '|',
         '|', '_', '_', '|'}},
    {1, {' ', '_', '_', ' ',
         ' ', ' ', ' ', '|',
         ' ', ' ', ' ', '|'}},
    {2, {' ', '_', '_', ' ',
         ' ', '_', '_', '|',
         '|', '_', '_', ' '}},
    {3, {' ', '_', '_', ' ',
         ' ', '_', '_', '|',
         ' ', '_', '_', '|'}},
    {4, {' ', ' ', ' ', ' ',
         '|', '_', '_', '|',
         ' ', ' ', ' ', '|'}},
    {5, {' ', '_', '_', ' ',
         '|', '_', '_', ' ',
         ' ', '_', '_', '|'}},
    {6, {' ', '_', '_', ' ',
         '|', '_', '_', ' ',
         '|', '_', '_', '|'}}
};*/
inline void sleep(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
using graphNumber = std::array<std::string,3>;
static std::map<unsigned int, graphNumber> numbers
{
    {0,{" __ ",
        "|  |",
        "|__|"}},
    {1, {"    ",
         "   |",
         "   |"}},
    {2, {" __ ",
         " __|",
         "|__ "}},
    {3, {" __ ",
         " __|",
         " __|"}},
    {4, {"    ",
         "|__|",
         "   |"}},
    {5, {" __ ",
         "|__ ",
         " __|"}},
    {6, {" __ ",
         "|__",
         "|__|"}},
    {7, {" __ ",
         "   |",
         "   |"}},
    {8, {" __ ",
         "|__|",
         "|__|"}},
    {9, {" __ ",
         "|__|",
         " __|"}},
    {10,{"    ",
         " .. ",
         " `` "}}
};
bool kbhit() {
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}
void clearConsole()
{
    system("clear");
    std::cout << "=============================================\n"
    <<           "=                                           =\n"
    <<           "=              Cool Clock!                  =\n"
    <<           "=                                           =\n"
    <<           "=============================================\n";
}
void drawWatch(std::array<int,5> time)
{
    std::string output = "";
    clearConsole();
    for(int i = 0; i < 3; ++i)
    {
        output = "          ";
        for(auto it: time)
        {
            output += numbers[it][i] ;
        }
        std::cout << output << '\n';
    }
    std::cout << "\n\nFor exit, enter any button...\n";
}
inline std::array<int,5> convertTimeToArray()
{
    time_t now = std::time(nullptr);
    tm* local = std::localtime(&now);
    int hours = local->tm_hour;
    int minutes = local->tm_min;
    return {hours /10, hours % 10, 10, minutes / 10, minutes % 10};
}
void Clock()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    drawWatch(convertTimeToArray());


    time_t now = std::time(nullptr);
    tm* local = std::localtime(&now);
    int last_minute = local->tm_min;

    while (true) {

        now = std::time(nullptr);
        local = std::localtime(&now);
        int current_minute = local->tm_min;


        if (current_minute != last_minute) {
            drawWatch(convertTimeToArray());
            last_minute = current_minute;
        }


        if (kbhit()) {
            break;
        }



    }
    std::cout << "\nExit from clock.\n";
    sleep(1500);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
int main()
{
    Clock();
    return 0;
}

