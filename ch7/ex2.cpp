#include <iostream>
bool isEvenNumber(std::string &str)
{
    for(auto it : str)
    {
        if(!(isdigit(it)))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    std::string str;
    std::cout << "Enter string: ";
    std::cin >> str;
    std::cout << str << " ";
    if(isEvenNumber(str))
    {
        std::cout << "is even number\n";
    }
    else
    {
        std::cout << "isn`t even number\n";
    }
}