#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string get_info(int pos, string line);

int main()
{
    ifstream data("5.txt");

    int IDs[908];
    int pos = 0;

    int highest_id = 0;

    if (!data) {
        cout << "No data file!" << endl;
        return 1;
    }

    string line;
    while (!data.eof()) {
        int row = 0;
        int column = 0;
        int temp_id = 0;

        int r_low = 0;
        int r_high = 127;
        getline(data, line);
        for (int i = 0; i < 7; i++) {
            if (i == 6) {
                if (line[i] == 'F') row = r_low;
                else row = r_high;
            }
            else {
                if (line[i] == 'F') r_high -= (r_high - r_low) / 2;
                else {
                    bool temp = false;
                    if ((r_high - r_low) % 2 >= 0.5) temp = true;

                    r_low += (r_high - r_low) / 2;
                    if (temp) r_low++;
                }
            }
        }

        int c_low = 0;
        int c_high = 7;
        for (int i = 7; i < 10; i++) {
            if (i == 9) {
                if (line[i] == 'L') column = c_low;
                else column = c_high;
            }
            else {
                if (line[i] == 'L') c_high -= (c_high - c_low) / 2;
                else {
                    bool temp = false;
                    //if ((c_high - c_low) % 2 >= 0.5) temp = true;

                    c_low += (c_high - c_low) / 2;
                    //if (temp) c_low++;
                }
            }
            //cout << c_low << " " << c_high << endl;
        }

        temp_id = (row * 8) + column;
        if (temp_id > highest_id) highest_id = temp_id;

        IDs[pos] = temp_id;
        pos++;
    }

    cout << highest_id << endl;

    for (int i = 0; i < 908; i++)
    {
        for (int j = i + 1; j < 908; j++)
        {
            if (IDs[i] > IDs[j])
            {
                int temp = IDs[i];
                IDs[i] = IDs[j];
                IDs[j] = temp;
            }
        }
    }

    for (int i = 0; i < 907; i++) {
        if (IDs[i] == IDs[i+1]-2) cout << IDs[i]+1 << endl;
    }
}