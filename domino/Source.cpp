#include "Header.h"
bool doMathPos(double item)
{
    if (item >= 0) {
        return true;

    }
    return false;

}

int shablon(bool(* const doMath)(double), double* mas, int size)
{
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (doMath(mas[i])) {
            ++counter;
        }
    }
    return counter;
}




Pair shablon(ItemWithStatus(* const doMathDiap)(double), double* mas, int size)
{
    Pair itemsCount;

    for (int i = 0; i < size; ++i) {
        ItemWithStatus element = doMathDiap(mas[i]);
        if (element.itemFromDiap)  {
            ++itemsCount.fromDiap;
        }
        if (element.itemMorThen) {
            ++itemsCount.morThen;
        }
    }



    return itemsCount;
}

ItemWithStatus doMathDiap(double item)
{
    ItemWithStatus status;
    if (item >= -1.5 && item <= 1.5) {
        status.itemFromDiap = true;
    }
    if (item > 2.25 ) {
        status.itemMorThen = true;
    }

    return status;
}

///////////////////////////////////////////////////////////////////////////////////////////

Domino::Domino(int left, int right, bool posLeft){
    this->leftSide = left;
    this->rightSide = right;
    this->posLeft = posLeft;
}

Domino::Domino(const Domino& item) {
    this->leftSide = item.leftSide;
    this->rightSide = item.rightSide;
    this->posLeft = item.posLeft;
}

Domino::~Domino()
{
    //cout << "This is destructor" << '\n';
    true;
    
}

int Domino::getLeftSide() const {
    return this->leftSide;
}

int Domino::getRightSide() const {
    return this->rightSide;
}

bool Domino::getPos() const {
    return this->posLeft;
}


void Domino::setLeftSide(int value) {
    this->leftSide = value;
}

void Domino::setRightSide(int value) {
    this->rightSide = value;
}

void Domino::setPos(bool value) {
    this->posLeft = value;
}

Domino Domino::rotate() {
    //this->posLeft = !this->posLeft;
    int left = this->leftSide;
    int right = this->rightSide;

    this->setLeftSide(right);
    this->setRightSide(left);
    return *this;
}




istream& operator>>(istream& is, Domino& item)
{
    //cout << "Enter left side: ";
    is >> item.leftSide;

    //cout << "Enter right side: ";
    is >> item.rightSide;

    //cout << "Direction left: ";
    is >> item.posLeft;

    return is;
}

ostream& operator<<(ostream& os, const Domino& item) {
    if (item.leftSide != item.rightSide) {
        os << '[' << item.leftSide << '|' << item.rightSide << ']';
    }
    else {
        os << '[' << item.leftSide << '/' << item.rightSide << ']';

    }
    return os;
}



bool Domino::operator==(const Domino& other)
{
    if (this->leftSide == other.leftSide) {
        return true;
    }

    else if (this->rightSide == other.rightSide) {
        return true;
    }
    return false;
}

Domino* readFromFile(const string& filename, int size)
{
    Domino* mas = new Domino[size];
    ifstream file(filename);

    if (file.is_open()) {
        Domino item;


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

void display(const Domino* mas, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << mas[i];
    }
    cout << '\n';
}



bool Domino::isMatch(const Domino& other) const {
    return (this->getRightSide() == other.getLeftSide()) || (this->getLeftSide() == other.getRightSide());
}

vector<Domino> buildSequence(Domino* mas, int size) {
    vector<Domino> sequence;

    sequence.push_back(mas[0]);
    for (int i = 1; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (sequence.back().isMatch(mas[j])) {
                sequence.push_back(mas[j]);
                swap(mas[i], mas[j]);
                break;
            }
            else if (sequence.back().isMatch(mas[j].rotate())) {
                sequence.push_back(mas[j].rotate());
                swap(mas[i], mas[j]);
                break;
            }
        }
    }

    return sequence;
}

void writeToFile(const vector<Domino> mas, int size, string filename)
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
