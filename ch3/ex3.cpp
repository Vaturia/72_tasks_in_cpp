#include<iostream>
#include <map>
static std::map<char, const char*> alphabet
{
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D',"-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L',".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d',"-.."},
    {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
    {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l',".-.."},
    {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
    {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
    {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
    {'y', "-.--"}, {'z', "--.."}
};
std::string Telegraph(std::string message)
{
    std::string result_messsage;
    for(auto it: message)
    {
        if(it != ' ' && it != '\n' && it != '\t')
        {
            result_messsage.append(alphabet[it]);
            result_messsage +=  ' ';
        }
    }
    result_messsage += '\n';
    return result_messsage;
}
int main()
{
    std::string message;
    std::cout << "Enter your message for translate to alphabet morze: ";
    std::getline(std::cin, message);
    std::cout << "Yout message in alphabet morze#\n" << Telegraph(message);
}