#include <iostream>

struct Rectangle
{
    int length;
    int width;
};


int main(){
    Rectangle r = {15, 20};
    Rectangle *p = &r;

    std::cout << p->length << " " << (*p).width << std::endl;


}