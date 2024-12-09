#include <iostream>
#include <fstream>
#include "../include/AoC.h"
#include <algorithm>

using namespace std;



int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    int res = 0;
    vector<int> left;
    vector<int> right;

    while (getline(input, buf)) {
        vector<int> line = readNumbers<int>(buf);
        left.push_back(line[0]);
        right.push_back(line[1]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < left.size(); i++) {
        res = res + abs(left[i] - right[i]);
    }

    cout << res << endl;
    input.close();
    return 0;
}