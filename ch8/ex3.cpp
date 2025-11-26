#include <iostream>
double calculateRating(double experience, double averagePoint)
{
    if(experience == 0.0)
    {
        return averagePoint;
    }
    else if(experience <= 2.0)
    {
        return averagePoint * 13;
    }
    else if(experience > 2.0 && experience <= 5.0)
    {
        return averagePoint * 16;
    }
    return 0.0;
}
int main()
{
    double averagePoint, experience;
    do
    {
        std::cout << "Enter your GPA(x.xx) from 3.0 to 5.0: ";
        std::cin >> averagePoint;
        if(averagePoint < 3.0 || averagePoint > 5.0)
        {
            std::cout << "Error! GPA must be from 3.0 to 5.0\n";
            continue;
        }

        std::cout << "Enter your experience(x(year).xx(months)): ";
        std::cin >> experience;

        if(experience < 0.0 || experience > 5.0)
        {
            std::cout << "Error! Experience must be from 3.0 to 5.0\n";
            continue;
        }
        break;
    } while(true);
    int result = calculateRating(experience, averagePoint);
    if(result >= 45)
    {
        std::cout << "Congratulations, your passing score: " << result << " you will be admitted\n";
    }
    else
    {
        std::cout << "Unfortunately, you did not pass, your passing score: " << result << '\n';
    }
}
