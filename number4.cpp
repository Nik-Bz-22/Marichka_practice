#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include<iomanip>

using namespace std;


double factorial(double n) {
    if (n < 0) {
        cout << "Factorial doesn't exist" << endl;
        return 0;
    }
    double fac = 1;
    for (int i = 1; i <= n; ++i) {
        fac *= i;
    }
    return fac;
}

void calculate(double x, double e) {
    double sum = 0;
    bool status = 1;
    cout << "Sin() value in radians: "  << x << endl;
    cout  << "Eps precision: " << e << "\n";
    cout << "______________________________________________________________________________________________" << endl;

    for (int n = 1; status; ++n) {

        double elem = pow(-1, n - 1) * (pow(x, 2 * n - 1) / factorial(2 * n - 1));
        cout << "Element number " << n << ":\t" << elem << endl;

        if (abs(elem) >= e) sum += elem;
        else status = 0;

        
    }
    cout << "______________________________________________________________________________________________" << endl;
    cout << "sin(" << x << ") = " << sum << endl;
}


int main() {
    calculate(2, 0.000001);

    return 0;
}




