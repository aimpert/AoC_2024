#include <iostream>
#include <fstream>
#include "../include/AoC.h"
#include <algorithm>
#include <unordered_map>

using namespace std;



int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    int res = 0;
    vector<int> left;
    unordered_map<int, int> right;

    while (getline(input, buf)) {
        vector<int> line = readNumbers<int>(buf);
        left.push_back(line[0]);
        right[line[1]]++;
    }

    for (int i = 0; i < left.size(); i++) {
        if (right.find(left[i]) != right.end()) res = res + (left[i] * right[left[i]]);
    }

    cout << res << endl;
    input.close();
    return 0;
}