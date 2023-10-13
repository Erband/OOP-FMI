#include <iostream>

int k; // учебни дисциплини
const int MAX_LENGTH = 12; // размер на име
const int MAX_DISCIPLINES = 10; // макс брой дисциплини

struct Student
{
    int fac_n;
    char name[MAX_LENGTH];
    double subjects[MAX_DISCIPLINES]; 
};

void create_Student(Student& s){
    do
    {
        std::cout << "Student faculty number: "; std::cin >> s.fac_n;
    } while (s.fac_n < 0 || s.fac_n > MAX_NUMBER);
    std::cin >> s.name;

}
