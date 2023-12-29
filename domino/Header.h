#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

bool doMathPos(double item);

int shablon(bool(* const doMath)(double), double* mas, int size);


struct Pair{
	int fromDiap = 0;
	int morThen = 0;
};

struct ItemWithStatus
{
	bool itemFromDiap = 0;
	bool itemMorThen = 0;
};

Pair shablon(ItemWithStatus(* const doMathDiap)(double), double* mas, int size);


ItemWithStatus doMathDiap(double item);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Domino {
private:
	int leftSide;
	int rightSide;
	bool posLeft;
public:
	Domino() : leftSide(0), rightSide(0), posLeft(1) {}
	Domino(int left, int right, bool posLeft = 1);
	Domino(const Domino& item);
	~Domino();
	int getLeftSide() const;
	int getRightSide() const;
	bool getPos() const;
	void setPos(bool);
	void setLeftSide(int);
	void setRightSide(int);
	Domino rotate();

	friend istream& operator>>(istream& is, Domino&);
	friend ostream& operator<<(ostream& os, const Domino&);
	bool operator==(const Domino&);
	bool isMatch(const Domino& other) const;




};

Domino* readFromFile(const string& filename, int size = 5);
void display(const Domino* mas, int size);

vector<Domino> buildSequence(Domino* mas, int size);
void writeToFile(const vector<Domino>, int size, string filename);
