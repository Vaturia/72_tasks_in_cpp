#include <iostream>
#include <string>
bool isIcecreamSandwich(const std::string &sandwich)
{
    int counter = 0;
    auto it_first = sandwich.begin();
    auto it_last = sandwich.end() - 1;
    if(sandwich.length() < 3){return false;};
    for(;it_first != it_last; it_first++, it_last--)
    {
        if(*it_first != *it_last){return false;};
        if(it_last - it_first == 1){break;};
        if((*it_first != *(it_first + 1)) || (*it_last != *(it_last - 1))){counter++;};
    }
    if(counter != 1){return false;};

    return true;
}
int main()
{
    std::cout << isIcecreamSandwich("CDC") << '\n';
    std::cout << isIcecreamSandwich("AAABB") << '\n';
    std::cout << isIcecreamSandwich("AA") << '\n';
    std::cout << isIcecreamSandwich("BBBBB") << '\n';
    std::cout << isIcecreamSandwich("AAACCCAA") << '\n';
    std::cout << isIcecreamSandwich("AACDCAA") << '\n';
    std::cout << isIcecreamSandwich("A") << '\n';
    std::cout << isIcecreamSandwich("DDDDCCCCDDDD") << '\n';
    std::cout << isIcecreamSandwich("AABBBAA") << '\n';
    std::cout << isIcecreamSandwich("3&&3") << '\n';
    std::cout << isIcecreamSandwich("yyyyymmmmmmmmyyyyy") << '\n';
    std::cout << isIcecreamSandwich("hhhhhhhhmhhhhhhhh") << '\n';


}