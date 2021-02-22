#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string get_info(int pos, string line);

int main()
{
    ifstream data("4.txt");

    if (!data) {
        cout << "No data file!" << endl;
        return 1;
    }

    string line;
    int i = 0;
    int good_passports = 0;
    bool byr=false, iyr=false, eyr=false, hgt=false, hcl=false, ecl=false, pid=false;

    while (!data.eof()) {
        getline(data, line);

        if (line == "") {
            if (byr && iyr && eyr && hgt && hcl && ecl && pid) good_passports++;

            byr = false;
            iyr = false;
            eyr = false;
            hgt = false;
            hcl = false;
            ecl = false;
            pid = false;
        }
        else {
            if (line.find("byr") != string::npos) byr = true;
            if (line.find("iyr") != string::npos) iyr = true;
            if (line.find("eyr") != string::npos) eyr = true;
            if (line.find("hgt") != string::npos) hgt = true;
            if (line.find("hcl") != string::npos) hcl = true;
            if (line.find("ecl") != string::npos) ecl = true;
            if (line.find("pid") != string::npos) pid = true;
        }
    } 

    cout << good_passports << endl;


    data.clear();
    data.seekg(0);

    i = 0;
    good_passports = 0;
    byr = false, iyr = false, eyr = false, hgt = false, hcl = false, ecl = false, pid = false;

    string temp;

    while (!data.eof()) {
        getline(data, line);

        if (line == "") {
            if (byr && iyr && eyr && hgt && hcl && ecl && pid) good_passports++;

            byr = false;
            iyr = false;
            eyr = false;
            hgt = false;
            hcl = false;
            ecl = false;
            pid = false;
        }
        else {
            if (line.find("byr") != string::npos) {
                string temp = get_info(line.find("byr"), line);
 
                if (temp.length() == 4) {
                    if (stoi(temp) >= 1920 && stoi(temp) <= 2002) byr = true;
                }
            }
            if (line.find("iyr") != string::npos) {
                string temp = get_info(line.find("iyr"), line);

                if (temp.length() == 4) {
                    if (stoi(temp) >= 2010 && stoi(temp) <= 2020) iyr = true;
                }
            }
            if (line.find("eyr") != string::npos) {
                string temp = get_info(line.find("eyr"), line);

                if (temp.length() == 4) {
                    if (stoi(temp) >= 2020 && stoi(temp) <= 2030) eyr = true;
                }
            }
            if (line.find("hgt") != string::npos) {
                string temp = get_info(line.find("hgt"), line);

                if (temp[temp.length() - 1] == 'm') {
                    if (temp[temp.length() - 2] == 'c') {
                        string num;
                        i = 0;
                        while (temp[i] != 'c') {
                            num.resize(i + 1);
                            num[i] = temp[i];
                            i++;
                        }
                        if (stoi(num) >= 150 && stoi(num) <= 193) hgt = true;
                    }
                }
                else if (temp[temp.length() - 1] == 'n') {
                    if (temp[temp.length() - 2] == 'i') {
                        string num;
                        i = 0;
                        while (temp[i] != 'i') {
                            num.resize(i + 1);
                            num[i] = temp[i];
                            i++;
                        }
                        if (stoi(num) >= 59 && stoi(num) <= 76) hgt = true;
                    }
                }
            }
            if (line.find("hcl") != string::npos) {
                string temp = get_info(line.find("hcl"), line);

                if (temp[0] == '#' && temp.length() == 7) hcl = true;
            }
            if (line.find("ecl") != string::npos) {
                string temp = get_info(line.find("ecl"), line);

                if (temp == "amb" || temp == "blu" || temp == "brn" || temp == "gry" || temp == "grn" || temp == "hzl" || temp == "oth") ecl = true;
            }
            if (line.find("pid") != string::npos) {
                string temp = get_info(line.find("pid"), line);

                if (temp.length() == 9) pid = true;
            }
        }
    }

    cout << good_passports << endl;
}

string get_info(int pos, string line) {
    string temp;
    int n = 0;
    pos += 4;
    while (line[pos] != ' ' && pos != line.length()) {
        temp.resize(n + 1);
        temp[n] = line[pos];
        pos++;
        n++;
    }

    return temp;
}