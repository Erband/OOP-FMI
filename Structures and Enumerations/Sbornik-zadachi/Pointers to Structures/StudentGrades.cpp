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
    std::cout << "Student family name: ";
    std::cin >> s.name;
    for (int i = 0; i < k; i++){
        std::cout << "Grade for " << i + 1 << " subject";
        std::cin >> s.subjects[i];
    }
}

void print_student(const Student& s){
    std::cout << setw(5) << s.fac_n << setw(MAX_LENGTH) << s.name;
    for (int i = 0; i < k; i++) {
        std::cout << setw(5) << s.subjects[i];
    }
}

double averageGrade(const Student& s) {
    double total = 0;
    for (int i = 0; i < k; i++){
        total+= s.subjects[i];
    }

    return total / k;
}

void create_Group(int n, Student *s){
    for (int i = 0; i < n; i++){
        std::cout << "Data for " << i + 1 << " student";
        create_Student(s[i]);
    }
}

void print_table(){
    std::cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);

    int i;
    for ( i = 0; i < 5 + MAX_LENGTH + 2 + 5*(k + 1) + 1; i++)
    {
        std::cout << "+";
    }
    std::cout << std::endl;
    std::cout << setw(5) <<"FN. " << setw(MAX_LENGTH=2) << "Family name";
    for (i = 0; i < k; i++) {
        std::cout << setw(4) << "Subject" << i+1;
    }
    std::cout << setw(6) << "Average grade" << std::endl;
    for ( i = 0; i < 5 + MAX_LENGTH + 2 + 5*(k + 1) + 1; i++){
        std::cout << "+";
    }    
    std::cout << std::endl;
}

void print_Group(int n; Student *students){
    print_table();
    int i, j;

    double temp[MAX_DISCIPLINES] = {0, };
    // finding the average grade for each subject
    for (j = 0; j < k; j++){
        for (i = 0; i < k; i++) {
            temp[j] += students[i].subjects[j];
        }
        temp[j] /= n;
    }

    // printing the data for the students as well as the sum from their average grades
    double sum = 0;
    for (i = 0; i < n; i++){
        print_student(students[i]);
        double res = averageGrade(students[i]);
        sum += res;
        std::cout << setw(6) << res;
    }
    for (i = 0; i < 5 + MAX_LENGTH + 2 + 5 *(k+1) + 1; i++){
        std::cout << "=";
    }

    // printing the average grade for students in the group for all subjects
    std::cout << std::endl << setw(5 + SIZE+2+5) << temp[0];
    for(j = 1; j < k; j++) {
        std::cout << setw(5) << temp[j];
    }
    std::cout << setw(6) << sum/n << std::endl;
}

void sortGroup(int n, Student **s){
    for (int i = 0; i < n-1; i++){
        int k = i;
        double max = averageGrade(*s[k]);
        for (int j = i + 1; j < n; j++){
            double d = averageGrade(*s[j]);
            if (d > max){
                max = d;
                k = j;
            }
        }
        Student* x;
        x = s[i]; s[i] = s[k]; s[k] = x;
    }

}