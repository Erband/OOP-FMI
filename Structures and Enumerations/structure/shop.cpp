
#pragma=once
#include <iostream>
#include <String>

const int DESCRIPTION_LENGTH = 32;

struct Product
{
    char description[DESCRIPTION_LENGTH] = "\0";       // описание на изделие
    int partNum = 0;                // номер на изделие
    double cost = 0;                // цена на изделие
};

void displayProduct(Product& product)
{
    std::cout << product.description << " " << product.partNum << " " << product.cost << std::endl;
}

Product enterProduct(Product& product)
{
    std::cin.ignore();
    std::cin.getline(product.description, DESCRIPTION_LENGTH);
    std::cin >> product.partNum;
    std::cin >> product.cost;

    return product;
}

int main(){


    Product products[10];

    for (int i = 0; i < 5; i++){
        enterProduct(products[i]);
    }

    for (int i = 0; i < 5; i++){
        displayProduct(products[i]);
    }

    return 0;
}