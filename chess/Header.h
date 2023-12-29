#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <map>

using namespace std;


double* templates(double* mas, int size, double(* const doMathFirstPart)(double), double(* const doMathSecondPart)(double));
double doMathFirstPart(double item);
double doMathSecondPart(double item);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Chess {
private:
	int num;
	char lit;
	bool isBlack;

public:
	Chess(): num(0), lit('\0'), isBlack(0) {}
	Chess(int num, char lit);
	Chess(const Chess& other);
	~Chess();
	void setNum(int value);
	void setLit(char value);
	int getNum() const;
	char getLit() const;
	bool checkBlack() const;
	friend istream& operator>>(istream& is, Chess&);
	friend ostream& operator<<(ostream& os, const Chess&);
	Chess operator+=(int change);



};

void display(const Chess* mas, const int size);
Chess* ReadFromFile(string filename, int size);
void WriteToFile(const Chess* mas, const int size, const  string filename);