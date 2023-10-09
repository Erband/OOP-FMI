#include <iostream>
#include <fstream>

const int MAX_LENGTH = 64;

struct Book
{
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int ISBN;
    char genre[10];
    double price;
};

const int BOOK_CAPACITY = 1000;
struct Bookstore{
    int amountOfBooks;
    Book books[BOOK_CAPACITY];
};

void initializeBookStore(Bookstore& store, const char* fileName)


int main(){
    // отваряне на файла за запис (output file stream)
    ofstream myFile;

    myFile.open("Bookstore.txt")





    return 0;
}