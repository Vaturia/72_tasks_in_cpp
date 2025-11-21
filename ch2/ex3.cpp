#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
int matchesNumbers(std::string userNumber, std::string hiddenNumber, int &guessed)
{
    int user, hidden, position = 0;

    for(auto it: userNumber)
    {
        if(hiddenNumber.find(it) != std::string::npos)
        {
            guessed++;
        }
    }
    std::stringstream convertToInt(userNumber + " " + hiddenNumber);

    convertToInt >> user >> hidden;

    while(user > 0)
    {
        if(user % 10 == hidden % 10)
        {
            position++;
        }
        user/= 10;
        hidden/=10;
    }

    return position;
}
int main()
{
    int tries = 10;
    srand(time(0));

    int hiddenRandNumber =  1 + rand() % (1000 - 1 + 1);

    std::stringstream hiddenStr;
    hiddenStr << hiddenRandNumber;
    std::string hiddenNum;
    hiddenStr >> hiddenNum;

    std::cout << "######################################################\n";
    std::cout << "#    The computer generated a three-digit number.    #\n";
    std::cout << "#    You must guess it. After entering each number,  #\n";
    std::cout << "#    you will be told how many numbers are guessed   #\n";
    std::cout << "#    and how many of them are in their places.       #\n";
    std::cout << "######################################################\n\n";
    while(tries > 0)
    {
        int guessed = 0, position = 0;
        std::string userNum;
        std::cout << "Your variant: ";
        std::cin >> userNum;
        position = matchesNumbers(userNum, hiddenNum, guessed);

        std::cout << "Guessed: " << guessed
        << ". In their places: " << position << '\n';
        if(userNum == hiddenNum)
        {
            std::cout << "***You guessed the number "
            << hiddenNum << "!***\n";
            break;
        }
        tries--;
    }
}