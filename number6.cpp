#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

class SortedList {
private:
	double doub_gener(double start, double end) {
		// ініціалізує початкове значення генератора
		random_device rd;
		// ініціалізація самого об'єкта генератора
		mt19937 gen(rd());
		// рівномірне розподілення рандомних чисел в заданому діапазоні
		uniform_real_distribution<double> dis(start, end);
		// сама генерація числа
		double randomDouble = dis(gen);
		return randomDouble;
	}

public:
	int size;
	int n;

	void initialize(int inputSize) {
		size = inputSize;
		n = size / 2;
	}

	double* create_mas(int size) {
		double* a = new double[size];
		for (int i = 0; i < size; ++i) {
			a[i] = doub_gener(10.0, 100.0);
		}
		return a;
	}

	double* sort_list(double* list) {
		for (int i = 0; i < n; ++i) {
			double max = (list[i + n] > list[i]) ? list[i + n] : list[i];
			double min = (list[i + n] < list[i]) ? list[i + n] : list[i];
			list[i] = max;
			list[i + n] = min;
		}
		return list;
	}
};

int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	int size = 2 * n;

	SortedList obj;
	obj.initialize(size);
	double* a = obj.create_mas(size);
	double* sortList = obj.sort_list(a);

	cout << "---------------------------------" << endl;
	cout << "|Before\t\t|\tAfter\t|" << "\n";
	cout << "---------------------------------" << endl;

	for (int i = 0; i < size; ++i) 
		cout << fixed << setprecision(3) << "|" << a[i] << "\t\t|\t" << sortList[i] << "\t|" << '\n';

	cout << "---------------------------------" << endl;

	delete[] a;

	return 0;
}
