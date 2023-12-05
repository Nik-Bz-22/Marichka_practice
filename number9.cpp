#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream inputFile("test.txt");

	if(!inputFile.is_open()) {
        cerr << "File open error" << endl;
        return 1;
    }

    string word;
    bool uniqStatus = 1;
    while (inputFile >> word) {
        for (int i = 0; i < word.length(); i++) {

            string new_word = word.substr(i+1);
            if (new_word.find(word[i]) <= word.length()) {
                //cout << "word: " << word << " not uniq" << '\n';
                uniqStatus = 0;
                break;
            } 

        }
        if (uniqStatus == 1) {
            cout << "Word with uniq char: " << word << '\n';
        }
        uniqStatus = 1;

    }

    inputFile.close();
}

