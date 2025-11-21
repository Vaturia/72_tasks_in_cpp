#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
void averagePrint(std::vector<double> &sequence)
{
    double average = 0.0;
    for (auto it : sequence)
    {
        average += it;
    }

    std::cout << "Arithmetic mean: " << average / sequence.size() << '\n';
    std::cout << "Minimal element: " << *(std::min_element(sequence.begin(), sequence.end())) << '\n';
    std::cout << "Max element: " << *(std::max_element(sequence.begin(), sequence.end())) << '\n';
}
int main ()
{
    int countNumbers = 0;
    std::cout << "Enter count Number of sequence: ";
    std::cin >> countNumbers;
    std::vector<double> seq;
    std::cout << "Enter sequance: ";
    for (int i = 0; i < countNumbers; ++i)
    {
        double buf;
        std::cin >> buf;
        seq.push_back(buf);
    }
    averagePrint(seq);

    return 0;
}