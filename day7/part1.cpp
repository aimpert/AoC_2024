#include <iostream>
#include <fstream>
#include "../include/AoC.h"

using namespace std;

bool backtrack(const unsigned long& target, const vector<int>& digits, unsigned long curr, int i) {
    if (i == digits.size()) return false;
    if (i == digits.size() - 1 && curr == target) return true;

    return backtrack(target, digits, digits[i + 1] + curr, i + 1) || backtrack(target, digits, digits[i + 1] * curr, i + 1);
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    unsigned long res = 0;

    while (getline(input, buf, ':')) {
        unsigned long testVal = readNumbers<unsigned long, unsigned long>(buf);
        if (getline(input, buf)) {
            vector<int> digits = readNumbers<int>(buf);
            if (backtrack(testVal, digits, digits[0], 0)) res += testVal;
        }
    }

    cout << res << endl;
    input.close();
    return 0;
}