#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string get_info(int pos, string line);

int main()
{
    ifstream data("6.txt");

    if (!data) {
        cout << "No data file!" << endl;
        return 1;
    }

    /*string line; PART ONE
    int good_answers = 0;
    bool questions[26];

    while (!data.eof()) {
        getline(data, line);

        if (line == "") {
            for (int i = 0; i < 26; i++) {
                if (questions[i] == true) {
                    good_answers++;
                    questions[i] = false;
                }
            }
        }
        else {
            for (int i = 0; i < line.length(); i++) {
                questions[(int)line[i] - 97] = true;
            }
        }
    }*/

    string line;
    int good_answers = 0;
    int questions[26] = {};
    int people = 0;


    while (!data.eof()) {
        getline(data, line);

        if (line == "") {
            for (int i = 0; i < 26; i++) {
                if (questions[i] == people) {
                    good_answers++;
                }
                questions[i] = 0;
            }
            people = 0;
        }
        else {
            for (int i = 0; i < line.length(); i++) {
                questions[(int)line[i] - 97]++;
            }
            people++;
        }
    }

    cout << good_answers << endl;
}