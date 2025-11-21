#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <thread>
#include <chrono>
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
        m_desiredDepartDate.tm_mon -= 1;
        m_desiredDepartDate.tm_year -= 1900;
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
            std::getline(std::cin, destination);
            std::cout << "Enter flight number: ";
            std::cin >> flightNumber;
            std::cin.ignore();

            std::cout << "Enter full name Passenger: ";
            std::getline(std::cin, fullNamePassanger);
            std::cout << "Enter despired departure date(dd mm yy): ";
            std::cin >> desiredDepartDate.tm_mday >> desiredDepartDate.tm_mon >> desiredDepartDate.tm_year;
            TicketApplication ticket(destination, flightNumber, fullNamePassanger, desiredDepartDate);
            clearConsole();
            std::cout << "You created\n";
            std::cout << ticket;
            std::cout << "Is everything right?(y - yes, n - no): ";
            while(true)
            {
                std::cin >> choice;
                std::cin.ignore();
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
        std::getline(std::cin, passanger);
        std::cout << "Enter flight number: ";
        std::cin >> flightNumber;

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
            std::cin >> choice;
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
            std::cin >> choice;
            std::cin.ignore();
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