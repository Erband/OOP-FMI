#include <iostream>
#include <math.h>
#include <iomanip>
// defining a struct for a point
struct Point
{
    double x,  // x - axis
           y;  // y - axis
};

// function to enter a point
void create_Point(Point& p){
    std::cout << "X-axis: "; std::cin >> p.x;
    std::cout << "Y-axis: "; std::cin >> p.y;
}

Point create_Point(){
    Point p;
    std::cout << "X-axis: "; std::cin >> p.x;
    std::cout << "Y-axis: "; std::cin >> p.y;
    return p;
}

 // displaying the coordinates of a point
void show_Point(const Point& p){ 
    std::cout << "Point(" << p.x << ", " << p.y << ")";
}

// функция за намиране на страна, дефинирана от две точки
double segment(const Point& p1, const Point& p2){
    return sqrt( (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// defining a struct for Triangle
struct Triangle
{
    Point A, B, C;
};

void create_Triangle(Triangle& t){
    std::cout << "Enter the three points of the triangle\n";
    create_Point(t.A);
    create_Point(t.B);
    create_Point(t.C);
}

void show_Triangle(const Triangle& t){
    std::cout << "triangle("; show_Point(t.A);
    std::cout << ", "; show_Point(t.B);
    std::cout << ", "; show_Point(t.C);
    std::cout << ") \n";
}

double Perimeter(const Triangle& t){
    double sideA = segment(t.A, t.B);
    double sideB = segment(t.B, t.C);
    double sideC = segment(t.C, t.A);

    return (sideA + sideB + sideC);
}

double Surface(const Triangle& t){
    double sideA = segment(t.A, t.B);
    double sideB = segment(t.B, t.C);
    double sideC = segment(t.C, t.A);
    double halfPerimeter = Perimeter(t);

    return sqrt(halfPerimeter*(halfPerimeter - sideA)*(halfPerimeter - sideB)*(halfPerimeter - sideC));
}


int main(){

    Triangle t;
    create_Triangle(t);
    show_Triangle(t);

    std::cout << "Perimeter: " << std::fixed << std::setprecision(2) << Perimeter(t) << "\nSurface: " << Surface(t);
    
    return 0;
}