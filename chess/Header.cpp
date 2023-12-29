#include "Header.h"

double* templates(double* mas, int size, double(* const doMathFirstPart)(double), double(* const doMathSecondPart)(double))
{

	double* newMas = new double[size];

	for (int i = 0; i < size/2; i++) {

		newMas[i] = doMathFirstPart(mas[i]);
	}

	for (int i = size/2; i < size; i++) {

		newMas[i] = doMathSecondPart(mas[i]);
	}






	return newMas;
}

double doMathFirstPart(double item) { 
	
	return sin(item);}

double doMathSecondPart(double item) {

	return sqrt(1 + item*item);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Chess::Chess(int num, char lit) {
	this->num = num;
	this->lit = lit;
	this->isBlack = this->checkBlack();
}

Chess::Chess(const Chess& other) {
	num = other.num;
	lit = other.lit;
	isBlack = other.isBlack;
}

Chess::~Chess()
{
	true;
}

void Chess::setNum(int value)
{
	this->num = value;
}

void Chess::setLit(char value)
{
	this->lit = value;
}

int Chess::getNum() const
{
	return this->num;
}

char Chess::getLit() const
{
	return this->lit;
}

bool Chess::checkBlack() const
{
	map<char, int> tabl;
	tabl['a'] = 1;
	tabl['b'] = 2;
	tabl['c'] = 3;
	tabl['d'] = 4;
	tabl['e'] = 5;
	tabl['f'] = 6;
	tabl['g'] = 7;
	tabl['h'] = 8;

	if ((this->getNum() % 2 == 0 && tabl[this->getLit()] % 2 == 0) || (this->getNum() % 2 != 0 && tabl[this->getLit()] % 2 != 0)) return true;
	else return false;
}

Chess Chess::operator+=(int change)
{
	this->num += change;
	return *this;
}


istream& operator>>(istream& is, Chess& item)
{
	cout << "Enter the char: ";
	is >> item.lit;

	cout << "Enter the num: ";
	is >> item.num;

	item.isBlack = item.checkBlack();

	return is;
}

ostream& operator<<(ostream& os, const Chess& item)
{
	
	if (item.isBlack){ os << '[' << item.num << ';' << item.lit << " (*Black*)" << ']'; }
	else{ os << '[' << item.num << ';' << item.lit << " (*White*)" << ']'; }
	return os;
}

void display(const Chess* mas, const int size)
{
	for (int i = 0; i < size; i++) {
		cout << mas[i] << "  ";
	}
}

Chess* ReadFromFile(string filename, int size)
{
	Chess* mas = new Chess[size];
	ifstream file(filename);

	if (file.is_open()) {
		Chess item;


		for (int i = 0; i < size; ++i) {
			file >> item;
			mas[i] = item;
		}

		file.close();
	}
	else {
		cerr << "Unable to open file: " << filename << endl;
	}
	return mas;
}

void WriteToFile(const Chess* mas, const int size,const  string filename)
{

	ofstream file(filename);

	if (file.is_open()) {
		for (int i = 0; i < size; i++) {
			file << mas[i];
		}
	}
	else {
		cerr << "Unable to open file: " << filename << endl;
	}
}


