#include <iostream>
#include <iomanip>

const int SIZE = 16;
const int MAX_SIZE = 20;

struct Person
{
    char f_name[SIZE]; // ���
    char l_name[SIZE]; // �������
};

// ������� �� �������� �� �����
void read_Person(Person& p){
    do
    {
        std::cout << "���: "; std::cin >> p.f_name; // �������� �� ���
        std::cout << "�������: "; std::cin >> p.l_name; // �������� �� �������
    } while (p.f_name == "" || p.l_name == "");
    
    
}

// ������������ ������� �� �������� �� �����
Person read_Person() {
    Person p;
    do
    {
        std::cout  << "��������� ���: "; std::cin >> p.f_name; // �������� �� ���
        std::cout  << "������� ���: "; std::cin >> p.l_name; // �������� �� �������
    } while (p.f_name == "" || p.l_name == "");

    return p;
}

void display_Person(const Person& p){
    std::cout << "��������� ���: " << p.f_name << std::endl; // ���������� �� ��������� ���
    std::cout << "������� ���: " << p.l_name << std::endl;  // ���������� �� ������� ���
}

struct Client{
    Person name; // ����
    double amount; // ���� � ������� ������
};

void read_Client(Client& c){
    do
    {
        std::cout << "��� �� ������: "; c.name = read_Person(); // �������� �� ��� �� ������
        std::cout << "���� � ������� ������� "; std::cin >> c.amount; // �������� �� ������� � ������� ������
    } while (c.name.f_name == " " || c.name.l_name == " " || c.amount == 0);
}

Client read_Client(){
    Client c; 
    do
    {
        std::cout  << "��� �� ������: \n"; c.name = read_Person(); // �������� �� ��� �� ������
        std::cout  << "���� � ������� ������: "; std::cin >> c.amount; // �������� �� ������� � ������� ������
    } while (c.name.f_name == " " || c.name.l_name == " ");
    
    return c;
}

void display_Client(const Client& c){
    std::cout <<  "����� �� ������: " << std::endl; display_Person(c.name);
    std::cout <<  "��������� � ������� ������: " << std::setw(5) << c.amount << std::endl;
}

int main(){
    // �) ������� ������� � ��������� ������ �� ����������� �� �������, �������� ���� ��������� �����
    std::cout << "�������� ����� ������� ������� \n�� ������� �� 1 �� " << MAX_SIZE << ": ";
    int n;

    // ����� ����� ������� �� ����� ��������
    do
    {
        std::cin >> n;
    } while (n < 1 || n > MAX_SIZE);

    Client client_list[n];
    for (int i = 0; i < n; i++){
        std::cout << "�������� �� ����� �� ������ " << i + 1 << ": " << std::endl; // ����� ��� ������ �� �� ����� ������� �������
        client_list[i] = read_Client(); // �������� �� ����� �� ��������� ������
        std::cout << std::endl;

    }

    // �) ��������� �� ������� �� ������ ������� �� �����������
    for (int i = 0; i < n; i++)
    {
        std::cout << "����� �� ������ " << i+1 << ": " << std::endl;
        display_Client(client_list[i]);
    }
    
    // �) �������� �� ������� ���� �� ������� � ����������� � ������� ����
    double totalDebt;
    for (int i = 0; i < n; i++)
    {
        if (client_list[i].amount < 0){
            std::cout << "�������� " << client_list[i].name.f_name 
                      << " " << client_list[i].name.l_name 
                      << " �����: " << abs(client_list[i].amount) << std::endl; 
            
            totalDebt += abs(client_list[i].amount);
        }
    }
    std::cout << "\n"<< "������ �� ������������ �� ��������� � ����� ��: " << totalDebt;
    
    return 0;
}