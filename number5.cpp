#include <iostream>
#include <string>

using namespace std;


void strEdit() {

    string text = "ajhfjksfhjskdhfjschchchchchc!chchch dffdsfd, ajdhdjka ch dfnsdjhj ";

    string substring = "ch";


    size_t punctuationPos = text.find_first_of(".!?,;:");

    if (punctuationPos != string::npos) {

        size_t substringPos = text.find(substring);

        if (substringPos != string::npos && substringPos < punctuationPos) {

            text.erase(substringPos, punctuationPos - substringPos);
        }
    }

    cout << "editing text: " << text << endl;

}


int main() {
    strEdit();
    return 0;
}






