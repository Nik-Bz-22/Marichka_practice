#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Header.h"

using namespace std;


void Number1() {

    const int size = 10;
    double mas[size] = { 8.9, 1.2, 4.3, 65.7, -54.6, 12.1, -21.1, 0.3, 33.1, 1.2 };

    double* newMas = templates(mas, size, doMathFirstPart, doMathSecondPart);

    for (int i = 0; i < size; i++) {
        cout << newMas[i] << "   ";
    }
}


void Number2() {
    
    const int size = 2;
    Chess* mas = ReadFromFile("input.txt", size);

    /*for (int i = 0; i < size; i++) {
        Chess item;
        cin >> item;
        item += 1;
        mas[i] = item;
    }*/


    WriteToFile(mas, size, "output.txt");
    

    display(mas, size);
}







int main() {
    Number2();
    return 0;
}
