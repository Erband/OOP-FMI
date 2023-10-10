#include <iostream>
const int NAME_SIZE = 128;
const int DESCRIPTION_SIZE = 512;

enum Brand
{
    vw,
    Audi,
    BMW,
    mercedes
};

enum Engine{
    V8,
    V10,
    V12
};

enum Fuel{
    Gasoline,
    Diesel,
    LPG
};

struct Car
{
    int km;
    double avgFuelBurn;
    char name[NAME_SIZE], description[DESCRIPTION_SIZE];
    Brand brand;
    Engine engine;
    Fuel fuel;
    
    void enterCar() {
        std::cout << "Enter car:";
        std::cout << "Enter name:";
        std::cin.getline(name, NAME_SIZE);
        std::cout << "Enter description:";
        std::cin.getline(description, DESCRIPTION_SIZE);
        std::cout << "Enter km: ";
        std::cin >> km; std::cout << std::endl;
        std::cout << "Enter average fuel burn: ";
        std::cin >> avgFuelBurn; std::cout << std::endl;
    }

    // constructor for car
    Car(int _km, double _avgFuelBurn, const char* _name = "Audi",
         const char* _description = "Best car") {
            km = _km;
            avgFuelBurn = _avgFuelBurn;
         }

    void getFuel ()
    {
        switch (fuel)
        {
        case Gasoline:
            std::cout << "We're on Gasoline" << std::endl;
            break;
        case Diesel:
            std::cout << "We're on Diesel" << std::endl;
            break;
        case LPG:
            std::cout << "We're on LPG" << std::endl;
            break;
        }
    }
        

};


int main() {

    Car* myCar = new Car(0, 0, "Placeholder", "Placeholder");
    myCar->enterCar();
    
    

    return 0;
}