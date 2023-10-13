#include <iostream>
#include <iomanip>
struct Rectangle
{
    int length;
    int width;
};

void print_rectangle(Rectangle r){
    std::cout << std::setw(35) << r.length
              << std::setw(15) << r.width << std::endl;
}

void init_rectangle(Rectangle& r){
    do{
    std::cin >> r.length >> r.width;
    }
    while (r.length <= 0 || r.width <= 0);
}

Rectangle init_rectangle(){
    Rectangle r;
    do
    {
        std::cout << "length: "; std::cin >> r.length;
        std::cout << "width: "; std::cin >> r.width;
    }
    while (r.length <= 0 || r.width <= 0);
    
    return r;
}

int main(){

    Rectangle r;
    init_rectangle(r);
    print_rectangle(r);

    r = init_rectangle();
    print_rectangle(r);

    return 0;
}