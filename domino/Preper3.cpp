#include <iostream>
#include "Header.h"
using namespace std;




void Number1() {
    const int size = 9;
    //double mas[size] = { 8.9, 1.2, 4.3, 65.7, -54.6, 12.1, -21.1, 0.3, 33.1 };

    /*int posElemens = shablon(doMathPos, mas, size);
    cout << posElemens << '\n';*/

    double* mas = new double[size];
    for (int i = 0; i < size; ++i) {
        mas[i] = i * 12.37;
    }

    Pair elements = shablon(doMathDiap, mas, size);
    cout << "diap: " << elements.fromDiap << "  more: " << elements.morThen << '\n';
    delete[] mas ;
}




//void Number2() {
//    int size = 5;
//    /*Domino* mas = new Domino[size];
//    for (int i = 0; i < size; ++i) {
//        Domino item;
//        cin >> item;
//        mas[i] = item;
//    }*/
//
//    Domino* dominos = readFromFile("input.txt");
//
//
//    display(dominos, size);
//    for (int i = 0; i < size; ++i) {
//        dominos[i].rotate();
//    }
//    display(dominos, size);
//
//    vector<Domino> q;
//    vector<Domino> masiv;
//
//    for (int i = 0; i < size; ++i) { masiv.push_back(dominos[i]); }
//
//    
//
//    map<int, int> map = fillMap(dominos, size);
//
//    for (int i = 1; i <= 6; ++i) {
//        if (map[i] % 2 == 0) {
//            cout << "Valid" << '\n';
//        }
//        else {
//            cout << "It is imposible to crete the valid sequence" << '\n';
//        }
//    }
//
//    int left;
//    int right;
//
//    for (int i = 0; i < size; ++i) {
//        if (q.size() == 0) { q.push_back(masiv[i]); masiv.erase(masiv.begin()); }
//
//        else {
//            int left = q[0].getLeftSide();
//            int right = q[-1].getRightSide();
//
//
//        }
//    }
//
//
//
//    /*for (const auto& pair : map) {
//        cout << pair.first << ':' << pair.second << ", ";
//    }*/
//
//
//
//}






void Number2() {
    int size = 5;
    Domino* dominos = readFromFile("input.txt", size);

    display(dominos, size);

    vector<Domino> sequence = buildSequence(dominos, size);

    if (sequence.size() == size) {
        cout << "Valid sequence: ";


        for (int i = 0; i < size; i++) {


            if (sequence[i].getLeftSide() == sequence.back().getLeftSide() && sequence[i].getRightSide() == sequence.back().getRightSide()) {
                cout << sequence[i] << " ";
                break;
            }


            if (sequence[i].getRightSide() != sequence[i + 1].getLeftSide()) {
                sequence[i + 1].rotate();
                cout << sequence[i] << " ";

            }

            else
            {
                cout << sequence[i] << " ";

            }
        }



        cout << endl;
    }
    else {
        cout << "It is impossible to create a valid sequence." << endl;
    }

    writeToFile(sequence, size, "outpu.txt");

    delete[] dominos;
}



int main()
{
    Number2();
}





