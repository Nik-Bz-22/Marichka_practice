#include <iostream>
#include <string>
using namespace std;
#include <vector>
//
//
//class Triangle {
//private:
//    double side1, side2, side3;
//
//public:
//    Triangle(double s1 = 0, double s2 = 0, double s3 = 0) : side1(s1), side2(s2), side3(s3) {};
//    Triangle(const Triangle& t) : side1(t.side1), side2(t.side2), side3(t.side3) {}; //конструктор копирования
//
//    ~Triangle() { cout << "delete item" << '\n'; };
//
//
//
//    void printInf() {
//        cout << "Side 1: " << side1 << '\n';
//        cout << "Side 2: " << side2 << '\n';
//        cout << "Side 3: " << side3 << '\n';
//
//    }
//
//    double getSide1() {
//        return side1;
//    }
//    double getSide2() {
//        return side2;
//    }
//    double getSide3() {
//        return side3;
//    }
//
//
//    void setSide1(double value) {
//        this->side1 = value;
//    }
//    void setSide2(double value) {
//        this->side2 = value;
//    }
//    void setSide3(double value) {
//        this->side3 = value;
//    }
//
//    double per() {
//
//        return side1 + side2 + side3;
//    }
//
//    double sq() {
//        double p = p / 2;
//        return  sqrt(p * (p - side1) * (p - side2) * (p - side3));
//    }
//    bool isCorrect() {
//
//        if (side1 <= 0 || side2 <= 0 || side3 <= 0) return 0;
//        if (side1 <= 0 || side2 <= 0 || side3 <= 0) return 0;
//
//    }
//
//};
//
//
//
//
//int main()
//{
//    Triangle T(2, 3, 5);
//    T.printInf();
//
//
//
//    Triangle A(T);
//    A.printInf();
//
//    cout << A.getSide1() << '\n';
//}



/*void delWords() {

	string str = "wjdfhjksh fsfh sdjkskdjhfsdkfhs fhsdks fskfsh sfskdfsdk fk hkds";



	int len = str.length();

	vector<char> word;

	for (int i = 0; i < len; i++) {
		if (str[i] != ' ') word.push_back(str[i]);
		else
		
	}


	cout << str << '\n';
}

int main() {

	

	delWords();

	return 1;
}*/





#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void delWords(const string& sentence) {

    istringstream stream(sentence);


    vector<string> words;

    string word;
    while (stream >> word) {
        words.push_back(word);
    }


    cout << "Word with unpaired index: ";
    for (int i = 0; i < words.size(); i += 2) {
        cout << words[i] << " ";
    }

    cout << '\n';
}

int main() {
    /*string sen;
    getline(cin, sen);*/
    string sen = "hhj yjg lksdjfskldfjs lklj lfe ldjalkdjjda;lk djakdhwe ugkjg agasghjfgdsh gaha gag ahsgfjh fs";
    delWords(sen);

    return 0;
}
