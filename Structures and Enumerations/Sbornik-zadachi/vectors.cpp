#include <iostream>
#include <math.h>

const double PI = 3.14159265;

// декларация на структура polar
struct polar
{
    double mag; // радиус
    double ang; // ъгъл
};

// декларация на структурата rect
struct rect{
    double x; // абциса
    double y; // радиана
};

// преобразуване на вектор, зададен чрез правогълни, в полярни координати
polar rect_to_polar(const rect& r){
    polar p;
    p.mag = sqrt(r.x * r.x + r.y * r.y);
    p.ang = atan2(r.y, r.x);
    return p;
}

// преобразуване на вектор, зададен чрез полярни, в правоъгълни координати
rect polar_to_rect(const polar& p){
    const double DEG_TO_RAD = PI/180;
    rect r;
    r.x = p.mag * cos(p.ang*DEG_TO_RAD);
    r.y = p.ang * sin(p.ang*DEG_TO_RAD);
    return r;
}

// принтиране на вектор, зададен в полярни координати
void print_polar(const polar& p){
    const double RAD_TO_DEG = 180/PI;
    std::cout << "Радиус = " << p.mag;
    std::cout << ", ъгъл = " << p.ang * RAD_TO_DEG;
    std::cout << " градуса\n";
}

// принтиране на вектор, зададен в правогълни координати
void print_rect(const rect& r){
    std::cout << "абциса = " << r.x
              << ", ордината = " << r.y << "\n";
}
int main(){
    rect r;
    polar p;

    std::cout << "Изберете режим на въвеждане на координатите: \n";
    std::cout << "r - за правоъгълни и p за полярни координати. \n";

    char ch; std::cin >> ch;
    switch (ch)
    {
    case 'r':
        std::cout << "Въведете правоъгълните координати x и y: \n";
        while (std::cin >> r.x >> r.y)
        {
            p = rect_to_polar(r);
            print_polar(p);
            std::cout << "Следващи правоъгълни координати, за край низа end ";
            
        }
        break;
    case 'p':
        std::cout << "Въведете полярните координати mag и ang: ";
        while (std::cin >> p.mag >> p.ang)
        {
            r = polar_to_rect(p);
            print_rect(r);
            std::cout << "Следващите полярни координати, за край въведете низа end ";
        }
        break;
    }
    
    return 0;
}