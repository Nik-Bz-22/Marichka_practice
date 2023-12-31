﻿#include <iostream>
#include <random>
using namespace std;

class Matrix {
public:
    struct Size {
        int n;
        int m;
    };

    double randomGen() {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> distribution(1.0, 100.0);

        double mydouble = distribution(gen);

        return mydouble;
    }

    double** createMatrix(Size si) {
        double** matrix = new double* [si.n];
        for (int i = 0; i < si.n; i++) {
            matrix[i] = new double[si.m];
        }
        return matrix;
    }

    void fillMatrix(double** matrix, Size si) {
        for (int i = 0; i < si.n; i++) {
            for (int j = 0; j < si.m; j++) {
                matrix[i][j] = randomGen();
            }
        }
    }

    void memoryClean(double** matrix, Size si) {
        for (int i = 0; i < si.n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void printMatrix(double** matrix, Size si) {
        for (int i = 0; i < si.n; i++) {
            for (int j = 0; j < si.m; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    struct Element {
        double element;
        int row;
        int column;
    };

    Element* getMasOfMatrixElements(double** matrix, Size size) {
        Element* masOfElements = new Element[size.n * size.m];
        for (int i = 0; i < size.n; i++) {
            for (int j = 0; j < size.m; j++) {
                Element el;
                el.row = i;
                el.column = j;
                el.element = matrix[i][j];
                masOfElements[i * size.m + j] = el;
            }
        }
        return masOfElements;
    }

    Element* getExtraElements(double** matrix, Size size) {
        Element* extraElements = new Element[size.m];
        for (int j = 0; j < size.m; j++) {
            double maxElement = matrix[0][j];
            int maxRow = 0;
            double columnSum = 0.0;  // Сумма элементов в колонке

            for (int i = 0; i < size.n; i++) {
                columnSum += matrix[i][j];

                if (matrix[i][j] > maxElement) {
                    maxElement = matrix[i][j];
                    maxRow = i;
                }
            }

            if (maxElement > columnSum - maxElement) {
                // Если максимальный элемент больше суммы остальных элементов
                Element el;
                el.row = maxRow;
                el.column = j;
                el.element = maxElement;
                extraElements[j] = el;
            }
            else {
                // Если не удовлетворяет условию, просто заполняем нулевыми значениями
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
    Matrix::Size size;
    size.n = 3;
    size.m = 3;

    Matrix myMatrix;
    double** matrix = myMatrix.createMatrix(size);
    myMatrix.fillMatrix(matrix, size);

    myMatrix.printMatrix(matrix, size);

    Matrix::Element* el = myMatrix.getExtraElements(matrix, size);
    for (int i = 0; i < size.m; ++i) { // Используем size.m, так как у нас size.m столбцов
        cout << "Element: " << el[i].element << "\tRow: " << el[i].row << " Column: " << el[i].column << endl;
    }

    myMatrix.memoryClean(matrix, size);

    return 0;
}