#include <iostream>
#include <random>
//#include "Class.cpp";
using namespace std;

class Matrix {
public:
    struct Size {
        int row;
        int column;
    };

    struct Element {
        double element;
        int row;
        int column;
    };

    double randomGen() {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> distribution(1.0, 1000.0);

        double mydouble = distribution(gen);

        return mydouble;
    }

    double** createMatrix(Size si) {
        double** matrix = new double* [si.row];
        for (int i = 0; i < si.row; i++) {
            matrix[i] = new double[si.column];
        }
        return matrix;
    }

    void fillMatrix(double** matrix, Size si) {
        for (int i = 0; i < si.row; i++) {
            for (int j = 0; j < si.column; j++) {
                matrix[i][j] = randomGen();
            }
        }
    }

    void memoryClean(double** matrix, Size si) {
        for (int i = 0; i < si.row; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void printMatrix(double** matrix, Size si) {
        for (int i = 0; i < si.row; i++) {
            for (int j = 0; j < si.column; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }



    Element* getExtraElements(double** matrix, Size size) {
        Element* extraElements = new Element[size.column];
        for (int j = 0; j < size.column; j++) {
            double maxElement = matrix[0][j];
            int maxRow = 0;
            double columnSum = 0.0;

            for (int i = 0; i < size.row; i++) {
                columnSum += matrix[i][j];

                if (matrix[i][j] > maxElement) {
                    maxElement = matrix[i][j];
                    maxRow = i;
                }
            }

            if (maxElement > columnSum - maxElement) {
                Element el;
                el.row = maxRow;
                el.column = j;
                el.element = maxElement;
                extraElements[j] = el;
            }
            else {
                Element el;
                el.row = 0;
                el.column = j;
                el.element = 0.0;
                extraElements[j] = el;
            }
        }
        return extraElements;
    }


};

int main() {
    cout << 22222222222222 << endl;
    Matrix::Size size;
    size.row = 3;
    size.column = 4;

    Matrix myMatrix;
    double** matrix = myMatrix.createMatrix(size);
    myMatrix.fillMatrix(matrix, size);

    myMatrix.printMatrix(matrix, size);

    Matrix::Element* el = myMatrix.getExtraElements(matrix, size);
    for (int i = 0; i < size.column; ++i) {
        cout << "Element: " << el[i].element << "\tRow: " << el[i].row << " Column: " << el[i].column << endl;
    }

    myMatrix.memoryClean(matrix, size);

    return 0;
}

