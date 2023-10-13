#include <iostream>
#include <iomanip>

const int SIZE = 16;
const int MAX_SIZE = 20;

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
        std::cout  << "Собствено Име: "; std::cin >> p.f_name; // вкарване на Име
        std::cout  << "Фамилно Име: "; std::cin >> p.l_name; // вкарване на Фамилия
    } while (p.f_name == "" || p.l_name == "");

    return p;
}

void display_Person(const Person& p){
    std::cout << "Собствено име: " << p.f_name << std::endl; // принтиране на собствено име
    std::cout << "Фамилно име: " << p.l_name << std::endl;  // принтиране на фамилно име
}

struct Client{
    Person name; // лице
    double amount; // сума в банкова сметка
};

void read_Client(Client& c){
    do
    {
        std::cout << "Име на клиент: "; c.name = read_Person(); // вкарване на име на клиент
        std::cout << "Сума в банкова сметкаЛ "; std::cin >> c.amount; // вкарване на финанси в банкова сметка
    } while (c.name.f_name == " " || c.name.l_name == " " || c.amount == 0);
}

Client read_Client(){
    Client c; 
    do
    {
        std::cout  << "Име на клиент: \n"; c.name = read_Person(); // вкарване на име на клиент
        std::cout  << "Сума в банкова сметка: "; std::cin >> c.amount; // вкарване на финанси в банкова сметка
    } while (c.name.f_name == " " || c.name.l_name == " ");
    
    return c;
}

void display_Client(const Client& c){
    std::cout <<  "Имена на клиент: " << std::endl; display_Person(c.name);
    std::cout <<  "Наличност в банкова сметка: " << std::setw(5) << c.amount << std::endl;
}

int main(){
    // а) въвежда имената и банковите сметки на множеството от клиенти, зададено чрез едномерен масив
    std::cout << "Въведете колко клиента желаете \nда вкарате от 1 до " << MAX_SIZE << ": ";
    int n;

    // избор колко клиента ще бъдат вкарвани
    do
    {
        std::cin >> n;
    } while (n < 1 || n > MAX_SIZE);

    Client client_list[n];
    for (int i = 0; i < n; i++){
        std::cout << "Вкарване на данни за клиент " << i + 1 << ": " << std::endl; // Анонс кой клиент ще му бъдат вкарани данните
        client_list[i] = read_Client(); // Вкарване на данни на съответен клиент
        std::cout << std::endl;

    }

    // б) Извеждане на данните на всички клиенти от множеството
    for (int i = 0; i < n; i++)
    {
        std::cout << "Данни на клиент " << i+1 << ": " << std::endl;
        display_Client(client_list[i]);
    }
    
    // в) намиране на дължими суми на клиенти в множеството и техният сбор
    double totalDebt;
    for (int i = 0; i < n; i++)
    {
        if (client_list[i].amount < 0){
            std::cout << "Клиентът " << client_list[i].name.f_name 
                      << " " << client_list[i].name.l_name 
                      << " дължи: " << abs(client_list[i].amount) << std::endl; 
            
            totalDebt += abs(client_list[i].amount);
        }
    }
    std::cout << "\n"<< "Сумата от задълженията на клиентите е равна на: " << totalDebt;
    
    return 0;
}