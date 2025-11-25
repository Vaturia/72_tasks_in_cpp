#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
inline bool isValidGrade(int grade)
{
    return grade >= 1 && grade <=5;
}
class StudentManager;

class Student
{
private:
    std::string m_fullName;
    int m_math, m_phys, m_info;
    double m_average;
    Student(std::string fullName, int math, int phys, int info, double average)
        :m_fullName(fullName), m_math(math), m_phys(phys), m_info(info), m_average(average)
    {
    }
    friend std::ostream& operator<<(std::ostream &out, Student student);

    friend class StudentManager;
};
std::ostream& operator<<(std::ostream &out, const Student student)
{
    out << std::left << std::setw(35) << student.m_fullName
    << std::right << std::setw(20) << " Mathematics: "
    << std::setw(2) << student.m_math << " Physics: "
    << std::setw(2) << student.m_phys << " Informatics: "
    << std::setw(2) << student.m_info << " Average score: "
    << std::setw(5) <<std::fixed << std::setprecision(2)
    << student.m_average;

    return out;
}
class StudentManager
{
private:
    std::vector<Student> students;
public:
    StudentManager()
    {
    }
    void readFile(std::string &fileName)
    {
        std::string fullNameStudent = "",FirstName, SecondName, LastName;
        int math = 0, phys = 0, info = 0;
        double average = 0.0;
        int countStr = 0;
        std::string LineFile;
        std::ifstream file(fileName);

        if(!file)
        {
            std::cerr <<"Uh oh, " << fileName << " could not be opened for reading!";
            std::exit(1);
        }
        std::cout << "Reading file is start..." << std::endl;

        file >> countStr;
        file.ignore(100, '\n');
        for(int i = 0; i < countStr && std::getline(file, LineFile); ++i)
        {
            std::istringstream iss(LineFile);
            if(!(iss >> SecondName >> FirstName >> LastName >> math >> phys >> info) || !(iss.eof()))
            {
                std::cerr << "Error. Invalid Format string in file(" << fileName << "): "
                << LineFile << '\n'
                << "String must be: (Second_Name First_name Last_name 1-5 1-5 1-5)" << std::endl;
                std::exit(1);
            }
            if(!isValidGrade(math) || !isValidGrade(phys) | !isValidGrade(info))
            {
                std::cerr << "Error. Grades must be from 1 to 5 in file(" << fileName << "): "
                << LineFile << std::endl;
                exit(1);
            }
            fullNameStudent = SecondName + " " + FirstName + " " + LastName;
            average = (math + phys + info) / 3.0;

            students.push_back(Student(fullNameStudent, math, phys, info, average));
        }
        std::string extra;
        if(file >> extra)
        {
            std::cerr << "Error. The number of lines does not match. Extra string: " << extra << std::endl;
        }
        std::cout << "Reading file - sucessful." << std::endl;
    }
    void printStudentsOnAverageGrade()
    {
        std::sort(students.begin(), students.end(),
        [](Student &a, Student &b){
            return a.m_average > b.m_average;
        });
        for(auto it : students)
        {
            std::cout << it << std::endl;
        }
    }

};
int main()
{
    StudentManager manager;
    std::string file = "input_data.txt";
    manager.readFile(file);
    manager.printStudentsOnAverageGrade();
}