#include <iostream>
#include <math.h>
struct Triangle
{
    double a, b, c;
};

void init_triangle(Triangle& t){
    bool tri;
    do
    {
        std::cin >> t.a >> t.b >> t.c;

        tri = t.a > 0 && t.b > 0 && t.c > 0 &&
              (t.a + t.b >= t.c) && (t.a + t.c > t.b) &&
              (t.b + t.c >= t.a);
    } while (!tri);
}

Triangle init_triangle(){
    bool tri;
    Triangle t;
    do
    {
        std::cout << "Side A: "; std::cin >> t.a;
        std::cout << "Side B: "; std::cin >> t.b;
        std::cout << "Side C: "; std::cin >> t.c;

        tri = t.a > 0 && t.b > 0 && t.c > 0 &&
              (t.a + t.b >= t.c) && (t.a + t.c > t.b) &&
              (t.b + t.c >= t.a);
    } while (!tri);
    
    return t;
}

void print_triangle(Triangle& t){
    std::cout << std::endl;
    std::cout << "Side A: " << t.a << std::endl;
    std::cout << "Side B: " << t.b << std::endl;
    std::cout << "Side C: " << t.c << std::endl;  
}

double Triangle_Perimeter(const Triangle& t){
    double perimeter = t.a + t.b + t.c;
    return perimeter;
}

double Triangle_Surface(const Triangle& t){
    double surface;
    double half_Perimeter = Triangle_Perimeter(t) / 2;

    surface = sqrt( half_Perimeter*(half_Perimeter-t.a)*(half_Perimeter-t.b)*(half_Perimeter-t.c) );


    return surface;
}

int main(){
    Triangle triangle = init_triangle();
    print_triangle(triangle);
    
    double Perimeter = Triangle_Perimeter(triangle);
    double Surface = Triangle_Surface(triangle);

    std::cout << "Perimeter: " << Perimeter << "\nSurface: " << Surface << std::endl;

    return 0;
}