#include <iostream>
#include <fstream>
#include "../include/AoC.h"

using namespace std;

#define X 0
#define Y 1

int solve(vector<int> A, vector<int> B, vector<int> prize) {

    // these are our equations
    // int n = (prize[X]*B[Y] - B[X]*prize[Y])/(A[X]*B[Y] - B[X]*A[Y]);
    // int m = (prize[X] - (n * A[X]))/B[X];

    int n_den = A[X]*B[Y] - B[X]*A[Y];
    int n_num = prize[X]*B[Y] - B[X]*prize[Y];
    
    // check to see if n will end up being a float
    if (n_num % n_den != 0) {
        return 0;
    }
    
    int n = n_num / n_den;
    
    if (n < 0 || n > 100) return 0;

    // same for m
    int m_num = prize[X] - (n * A[X]);
    if (m_num % B[X] != 0) {
        return 0;
    }
    
    int m = m_num / B[X];

    if (m < 0 || m > 100) return 0;

    return (n * 3) + m;
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    int res = 0;
    int i = 0;
    vector<vector<int>> curr;
    while (getline(input, buf)) {
        if (i == 3) {
            res += solve(curr[0], curr[1], curr[2]);
            i = 0;
            curr.clear();
            continue;
        }
        curr.push_back(readNumbers<int>(buf));
        i++;

    }

    if (!curr.empty()) res += solve(curr[0], curr[1], curr[2]); // to collect the last machine
    
    cout << res << endl;
    input.close();
    return 0;
}