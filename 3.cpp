#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int get_trees(int right, int down, ifstream& file);
int file_line_size(ifstream& file);

int main()
{
    ifstream data("3.txt");

    if (!data) {
        cout << "No data file!" << endl;
        return 1;
    }

    cout << get_trees(3, 1, data) << endl;
    cout << "---------------- TASK 2" << endl;

    cout << get_trees(1, 1, data) << endl;
    cout << "----------------" << endl;

    cout << get_trees(3, 1, data) << endl;
    cout << "----------------" << endl;

    cout << get_trees(5, 1, data) << endl;
    cout << "----------------" << endl;
    
    cout << get_trees(7, 1, data) << endl;
    cout << "----------------" << endl;
    
    cout << get_trees(1, 2, data) << endl;
}

int get_trees(int right, int down, ifstream& file) {
    file.clear();
    file.seekg(0);

    cout << endl;

    int lines = file_line_size(file) - 1;

    string line;
    int r_pos = 0;
    int trees = 0;

    for (int i = 0; i <= lines; i += down) {
        for(int x = 0; x < down; x++) getline(file, line);

        if (line[r_pos] == '#') trees++;
        r_pos += right;

        if (r_pos >= line.length()) r_pos -= line.length();
    }

    return trees;
}

int file_line_size(ifstream& file) {
    string line;
    int number_of_lines = 0;


    while (!file.eof()) {
        getline(file, line);
        number_of_lines++;
    }

    file.clear();
    file.seekg(0);

    return number_of_lines;
}