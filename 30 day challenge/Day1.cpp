#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    int integer;
    double dos;
    string str;

    std::cin >> integer >> dos;
    std::getline(std::cin >> ws, str);

    std::cout << i + integer << "\n"
              << fixed << setprecision(1) << d + dos <<  "\n"
              << s + str;

    
    

    return 0;
}