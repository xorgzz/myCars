#include <iostream>
#include <fstream>
using namespace std;

struct Auto {
    string name;
    int year;
    string color;
};

const int allowedCars = 8;

void readDB(Auto myCars[allowedCars], int * x) {
    ifstream fp;
    fp.open("./mycars.txt");
    int i=0;
    while (!fp.eof()) {
        fp >> myCars[i].name;
        fp >> myCars[i].year;
        fp >> myCars[i].color;
        i++;
    }
    fp.close();
    *x = i;
}

void printMyCars(Auto myCars[allowedCars], int x) {
    cout << "_________________" << endl;
    cout << "|               |" << endl;
    cout << "|    MY CARS    |" << endl;
    cout << "|_______________|" << endl << endl;
    cout << "_________________________________________" << endl;
    cout << "|                                       |" << endl;
    for (int i=0; i<x; i++) {
        cout << "|\t";
        cout << myCars[i].name << "\t" << myCars[i].year << "\t" << myCars[i].color << "\t\t|" << endl;
    }
    cout << "|_______________________________________|" << endl;
}

void addCar(Auto cars[allowedCars], int * amount, string name, int year, string color) {
    cars[*amount].name = name;
    cars[*amount].year = year;
    cars[*amount].color = color;
    *amount = *amount + 1 ;
}

int main(){
    Auto myCars[allowedCars];
    int amountOfMyCars = 0;
    readDB(myCars, &amountOfMyCars);
    printMyCars(myCars, amountOfMyCars);

    addCar(myCars, &amountOfMyCars, "audi", 2137, "red");

    printMyCars(myCars, amountOfMyCars);

    return 0;
}
