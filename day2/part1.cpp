#include <iostream>
#include <fstream>
#include "../include/AoC.h"

using namespace std;

bool compare(vector<int> level, int& p, bool increasing) {
    int num1 = level[p++];
    int num2 = level[p];

    if (abs(num1 - num2) < 1 || abs(num1 - num2) > 3) return false;

    if (increasing) return num1 < num2;
    else return num1 > num2; 

}

bool checkSafe(vector<int> level) {
    int p = 0;
    bool increasing = level[0] < level[1] ? true : false;
    while (p < level.size() - 1) {
        if (!compare(level, p, increasing)) return false;
    }
    return true;
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    int res = 0;

    while (getline(input, buf)) {
        vector<int> level = readNumbers<int>(buf);
        if (checkSafe(level)) res++;
    }

    cout << res << endl;
    input.close();
    return 0;
}