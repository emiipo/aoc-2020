#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int file_line_size(ifstream& file);
int find_number2(int lines, int* array);
int find_number3(int lines, int* array);

int main()
{
    ifstream data("1.txt");
    int lines = file_line_size(data)-1;
    data.clear();
    data.seekg(0);
    int* a = NULL;

    a = new int[lines];

    if (!data) {
        cout << "No data file!" << endl;
        return 1;
    }

    for (int i = 0; i <= lines; i++) {
        data >> a[i];
    }

    cout << find_number2(lines, a) << endl;
    cout << find_number3(lines, a) << endl;
}

int file_line_size(ifstream& file) {
    string line;
    int number_of_lines = 0;
    

    while (!file.eof()) {
        getline(file, line);
        number_of_lines++;
    }

    return number_of_lines;
}

int find_number2(int lines, int* array) {
    int num = 0;

    for (int i = 0; i <= lines; i++) {
        for (int n = i+1; n <= lines; n++) {
            if (array[i] + array[n] == 2020) {
                num = array[i] * array[n];
                return num;
            }
        }
    }

    return 0;
}

int find_number3(int lines, int* array) {
    int num = 0;

    for (int i = 0; i <= lines; i++) {
        for (int n = i + 1; n <= lines; n++) {
            for (int a = n; a <= lines; a++) {
                if (array[i] + array[n] + array[a] == 2020) {
                    num = array[i] * array[n] * array[a];
                    return num;
                }
            }
        }
    }

    return 0;
}