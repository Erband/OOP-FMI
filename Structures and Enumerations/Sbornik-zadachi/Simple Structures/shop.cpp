
#pragma=once
#include <iostream>
#include <string.h>
#include <iomanip>

const int DESCRIPTION_LENGTH = 32;

struct Product
{
    char description[DESCRIPTION_LENGTH];     // описание на изделие
    int partNum;                // номер на изделие
    double cost;                // цена на изделие
};

void displayProduct(Product& product)
{
    std::cout << std::setw(35) << product.description
              << std::setw(15) << product.partNum
              << std::setw(20) << product.cost << std::endl;
}



int main(){
    

    Product products[10];

    for (int i = 0; i < 10; i++)
    {
        strcpy(products[i].description, "");
        products[i].partNum = 0;
        products[i].cost = 0.0;
    }

    Product Q[5] = { {"screwdriver", 456, 5.5},
                     {"hammer", 324, 8.2},
                     {"socket", 458, 5.75},
                     {"plier", 929, 10.5},
                     {"hand-saw", 536, 7.45}};
    

    for (int i = 0; i < 5; i++){
        displayProduct(Q[i]);
    }

    return 0;
}