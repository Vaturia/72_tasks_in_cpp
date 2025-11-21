#include<iostream>
#include <vector>
#include <algorithm>
void mergeArrays(std::vector<int> &a, std::vector<int> &b, std::vector<int> &result)
{
    for(auto it : a)
    {
        result.push_back(it);
    }
    for(auto it : b)
    {
        result.push_back(it);
    }
    std::sort(result.begin(), result.end());
}
void enterArray(std::vector<int> &array)
{
    int number = 0;
    do
    {
        std::cin >> number;
        array.push_back(number);
    } while (std::cin.get() != '\n');

}
int main()
{
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> result;

    std::cout << "Enter elements first array (enter e for exit): ";
    enterArray(a);
    std::cout << "Enter elements second array (enter e for exit): ";
    enterArray(b);

    mergeArrays(a, b, result);
    std::cout << "Array-result: ";
    for(auto it : result)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}