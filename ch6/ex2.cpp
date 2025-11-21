#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
void printTelegraph(std::string &message)
{

    int timeDelay =  0;
    for(auto letter : message)
    {
        timeDelay = 1 + rand() % (600 - 1 + 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(timeDelay));

        std::cout.put(letter);
        std::cout.flush();
    }
    std::cout << '\n';
}
int main()
{
    srand(time(0));
    std::string mes;
    std::cout << "Enter message: ";
    std::getline(std::cin, mes);
    printTelegraph(mes);
}