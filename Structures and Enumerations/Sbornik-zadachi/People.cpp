#include <iostream>

const int SIZE = 16;

struct Person
{
    char f_name[SIZE]; // Име
    char l_name[SIZE]; // Фамилия
};

// функция за вкарване на човек
void read_Person(Person& p){
    do
    {
        std::cout << "Име: "; std::cin >> p.f_name; // вкарване на Име
        std::cout << "Фамилия: "; std::cin >> p.l_name; // вкарване на Фамилия
    } while (p.f_name == "" || p.l_name == "");
    
    
}

// алтернативна функция за вкарване на човек
Person read_Person() {
    Person p;
    do
    {
        std::cout << "Име: "; std::cin >> p.f_name; // вкарване на Име
        std::cout << "Фамилия: "; std::cin >> p.l_name; // вкарване на Фамилия
    } while (p.f_name == "" || p.l_name == "");

    return p;
}

void display_Person(const Person& p){
    std::cout << "Собствено име: " << p.f_name << std::endl;
    std::cout << "Фамилно име: " << p.l_name << std::endl;
}

struct Client{
    Person name; // лице
    double amount; // сума в банкова сметка
};

void read_Client(Client& c){
    std::cout << "Име на клиент: \n"; c.name = read_Person();
    std::cout << "Сума в банкова сметкаЛ "; std::cin >> c.amount;
}

int main(){
    return 0;
}