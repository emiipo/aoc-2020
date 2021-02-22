#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int get_number(int& c, string l, char sp);

int main()
{
    int good_passwords_1 = 0;
    int good_passwords_2 = 0;
    ifstream data("2.txt");
    
    if (!data) {
        cout << "No data file!" << endl;
        return 1;
    }

    string line;
    string password;
    char letter;
    int min = 0;
    int max = 0;

    while (!data.eof()) {
        getline(data, line);

        int count = 0;
        min = get_number(count, line, '-');
        count++;
        max = get_number(count, line, ' ');

        count++;
        letter = line[count];
        count += 3;

        for (int i = count; i < line.length(); i++) {
            password.resize((i - count) + 1);
            password[(i - count)] = line[i];
        }
        
        int amount = 0;
        for (int i = 0; i < password.length(); i++) {
            if (password[i] == letter) amount++;
        }
        if (amount >= min && amount <= max) good_passwords_1++;

        if ((password[min-1] == letter && password[max-1] != letter) || (password[min-1] != letter && password[max-1] == letter)) good_passwords_2++;
    }

    cout << good_passwords_1 << endl;
    cout << good_passwords_2 << endl;
}

int get_number(int& c, string l, char sp) {
    string number;
    int n = 0;
    while (l[c] != sp) {
        number.resize(n + 1);
        number[n] = l[c];
        c++;
        n++;
    }

    return stoi(number);
}