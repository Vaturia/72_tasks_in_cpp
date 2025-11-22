#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <thread>
#include <chrono>
template<typename T>
T getInputValue()
{
    T value;
    while(true)
    {
        std::cin >> value;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32000, '\n');
            std::cout << "Error! Invalid input. Input must be a symbol or number witchout spaces. Retry: ";
            continue;
        }
        std::cin.ignore(100, '\n');
        return value;
    }
    return T(0);
}
template<>
std::string getInputValue()
{
    std::string buffer;
    std::string result;

    while(true)
    {
        buffer.clear();
        std::getline(std::cin, buffer);
        bool validString = true;
        for(int i = 0; i < buffer.size() && validString; ++i)
        {
            if(isspace(buffer[i]))
            {
                continue;
            }
            if(!(isalpha(buffer[i])))
            {
                std::cout << "Error. Invalid character (" << buffer[i] << ") in (" << buffer << ")\n";
                std::cout << "Try input again: ";
                validString = false;
                break;
            }
        }
        if(validString) {break;};
    }
    std::stringstream iss(buffer);
    buffer.clear();
    while(iss >> buffer)
    {
        result += buffer + " ";
    }
    return result;
}
template<>
tm getInputValue()
{

    std::string line;
    int day, month, year;
    tm result;
    while(true)
    {
        std::getline(std::cin, line);
        std::stringstream iss(line);
        iss >> day >> month >> year;
        month -= 1;
        year -= 1900;
        if(!(day > 0 && day < 32))
        {
            std::cout << "Error. Invalid range for day. Input num(1-31). Retry: ";
            continue;
        }
        else if(!(month < 12 && month > -1))
        {
            std::cout << "Error.Invalid range fo month. Input num(1-12). Retry: ";
            continue;
        }
        else if(!(year < 9999 && year > 0))
        {
            std::cout << "Error. Invalid range for year. Input num(1900+). Retry: ";
            continue;
        }
        result.tm_mday = day;
        result.tm_mon = month;
        result.tm_year = year;
        break;
    }
    return result;
}
class TicketManager;

class TicketApplication
{
private:
    std::string m_destination;
    int m_flightNumber;
    std::string m_fullNamePassanger;
    tm m_desiredDepartDate;
    TicketApplication(std::string &destination, int flightNumber,
                        std::string &fullNamePAssanger, tm &desiredDepartDate)
        :m_destination(destination), m_flightNumber(flightNumber),
        m_fullNamePassanger(fullNamePAssanger), m_desiredDepartDate(desiredDepartDate)
    {
    }
    friend std::ostream& operator<<(std::ostream &out, TicketApplication ticket);

    friend class TicketManager;
};
std::ostream& operator<<(std::ostream &out, TicketApplication ticket)
{
    char date[20];
    strftime(date,sizeof(date), "%d/%m/%Y", &(ticket.m_desiredDepartDate));
    out << "Ticket application:\n" << "Destination: " << ticket.m_destination << '\n'
    << "Flight number: " << ticket.m_flightNumber << '\n'
    << "Full name passanger: " << ticket.m_fullNamePassanger << '\n'
    << "Desired departure date: " << date << '\n';

    return out;
}
class TicketManager
{
private:
    std::list<TicketApplication> ticketsList;
    inline void sleep(int ms)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
    void clearConsole()
    {
        system("clear");
        std::cout << "=============================================\n"
        <<           "=                                           =\n"
        <<           "=       Air Ticket Managment System         =\n"
        <<           "=                                           =\n"
        <<           "=============================================\n";
    }
    void addTicketApplication()
    {
        while(true)
        {
            std::string destination = "", fullNamePassanger = "";
            int flightNumber = 0;
            tm desiredDepartDate {};
            char choice = ' ';

            clearConsole();
            std::cout << "Enter destination: ";
            destination = getInputValue<std::string>();
            std::cout << "Enter flight number: ";
            flightNumber = getInputValue<int>();
            std::cout << "Enter full name Passenger: ";
            fullNamePassanger = getInputValue<std::string>();
            std::cout << "Enter despired departure date(dd mm yy): ";
            desiredDepartDate = getInputValue<tm>();
            /*std::cin >> desiredDepartDate.tm_mday >> desiredDepartDate.tm_mon >> desiredDepartDate.tm_year;*/
            TicketApplication ticket(destination, flightNumber, fullNamePassanger, desiredDepartDate);
            clearConsole();
            std::cout << "You created\n";
            std::cout << ticket;
            std::cout << "Is everything right?(y - yes, n - no): ";
            while(true)
            {
                choice = getInputValue<char>();
                if(choice == 'y')
                {
                    ticketsList.push_back(ticket);
                    std::cout << "The application has been successfully created.\n";
                    sleep(2000);
                    return;
                }
                else if(choice == 'n')
                {
                    std::cout << "Re-create the request!\n";
                    sleep(2000);
                    break;
                }
                else
                {
                    std::cout << "Error. Invalid key. Please enter (y) or (n): ";
                    continue;
                }
            }
        }
    }
    void removeTicketApplication()
    {
        clearConsole();
        std::string passanger;
        int flightNumber;
        std::cout << "Enter full name passenger: ";
        passanger = getInputValue<std::string>();
        std::cout << "Enter flight number: ";
        flightNumber = getInputValue<int>();

        std::cout << "Search...\n";

        auto ticketApplication = std::find_if(ticketsList.begin(),ticketsList.end(),
        [=,&passanger](TicketApplication &ticket){
            return ticket.m_fullNamePassanger == passanger && ticket.m_flightNumber == flightNumber;
        });
        sleep(1000);

        if(ticketApplication != ticketsList.end())
        {
            std::cout << "The application has been found and will be deleted.\n";
            ticketsList.erase(ticketApplication);
        }
        else
        {
            std::cout << "The application is not in the database.\n";
        }
        sleep(2000);
    }
    void printAllTicketApplication()
    {
        clearConsole();
        std::cout << "All ticket application\n";
        for(auto it: ticketsList)
        {
            std::cout << it;
            char choice;
            std::cout << "Next(n), Exit(any button): ";
            choice = getInputValue<char>();
            if(choice == 'n' || choice == 'N')
            {
                std::cout << "=============================================\n";
                continue;
            }
            else
            {
                return;
            }
        }
        std::cout << "Applications are sold out :)\n";
        sleep(1000);
    }

public:
    TicketManager()
    {
    }
    void menu()
    {
        while (true)
        {
            char choice;
            clearConsole();
            std::cout << "### Select Action ###\n"
            << "Add application(Enter A/a).\n"
            << "Remove application(Enter R/r).\n"
            << "Print all application(Enter P/p).\n"
            << "Exit(Enter E/e)\n";
            std::cout << "Enter your choice: ";
            choice = getInputValue<char>();
            switch (choice)
            {
            case 'A':
            case 'a':
                addTicketApplication();
                break;
            case 'R':
            case 'r':
                removeTicketApplication();
                break;
            case 'P':
            case 'p':
                printAllTicketApplication();
                break;
            case 'E':
            case 'e':
                clearConsole();
                std::cout << "Thank you for using, Goodbye!\n";
                sleep(2000);
                return;
            default:
                std::cout <<"\nError. Invalid input! Try again!\n";
                sleep(1500);
                break;
            }
        }


    }
};
int main()
{
    TicketManager manager;
    manager.menu();


}