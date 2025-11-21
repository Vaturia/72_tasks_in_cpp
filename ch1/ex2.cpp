#include<iostream>
void findMinElementInSeq()
{
    int minElement = INT32_MAX, inputField, counter = 1;
    while(1)
    {
        std::cout << "Enter positive number №" << counter << " or (0 to end sequence): ";
        std::cin >> inputField;
        if(std::cin.fail() || inputField < 0)
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Error input. Try enter again.\n";
            continue;
        }
        else if(inputField == 0){break;}
        else
        {
            counter++;
            minElement = inputField < minElement ? inputField : minElement;

        }
    }
    if(counter == 1)
    {
        std::cout << "You not enter any seq.\n";
    }
    else
    {
        std::cout << "Min number in sequence is: " << minElement << '\n';
    }
}
int main()
{
    findMinElementInSeq();
}