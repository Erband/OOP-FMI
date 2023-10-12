#include <iostream>
#include <math.h>

const double PI = 3.14159265;

// ���������� �� ��������� polar
struct polar
{
    double mag; // ������
    double ang; // ����
};

// ���������� �� ����������� rect
struct rect{
    double x; // ������
    double y; // �������
};

// ������������� �� ������, ������� ���� ����������, � ������� ����������
polar rect_to_polar(const rect& r){
    polar p;
    p.mag = sqrt(r.x * r.x + r.y * r.y);
    p.ang = atan2(r.y, r.x);
    return p;
}

// ������������� �� ������, ������� ���� �������, � ����������� ����������
rect polar_to_rect(const polar& p){
    const double DEG_TO_RAD = PI/180;
    rect r;
    r.x = p.mag * cos(p.ang*DEG_TO_RAD);
    r.y = p.ang * sin(p.ang*DEG_TO_RAD);
    return r;
}

// ���������� �� ������, ������� � ������� ����������
void print_polar(const polar& p){
    const double RAD_TO_DEG = 180/PI;
    std::cout << "������ = " << p.mag;
    std::cout << ", ���� = " << p.ang * RAD_TO_DEG;
    std::cout << " �������\n";
}

// ���������� �� ������, ������� � ���������� ����������
void print_rect(const rect& r){
    std::cout << "������ = " << r.x
              << ", �������� = " << r.y << "\n";
}
int main(){
    rect r;
    polar p;

    std::cout << "�������� ����� �� ��������� �� ������������: \n";
    std::cout << "r - �� ����������� � p �� ������� ����������. \n";

    char ch; std::cin >> ch;
    switch (ch)
    {
    case 'r':
        std::cout << "�������� ������������� ���������� x � y: \n";
        while (std::cin >> r.x >> r.y)
        {
            p = rect_to_polar(r);
            print_polar(p);
            std::cout << "�������� ����������� ����������, �� ���� ���� end ";
            
        }
        break;
    case 'p':
        std::cout << "�������� ��������� ���������� mag � ang: ";
        while (std::cin >> p.mag >> p.ang)
        {
            r = polar_to_rect(p);
            print_rect(r);
            std::cout << "���������� ������� ����������, �� ���� �������� ���� end ";
        }
        break;
    }
    
    return 0;
}