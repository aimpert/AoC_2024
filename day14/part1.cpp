#include <iostream>
#include <fstream>
#include "../include/AoC.h"

using namespace std;

#define MAX_X 101
#define MAX_Y 103

vector<int> findPosition(int x, int y, int v_x, int v_y) {
    
    static vector<int> quadrants(4, 0);

    // I know there's gotta be a cleaner way of doing this logic
    if (v_x > 0) {
        int x_travel = v_x * 100 + x;
        x = x_travel % MAX_X;
    }
    else if (v_x < 0) {
        int x_travel = v_x * 100 - (MAX_X - 1 - x);
        x = (x_travel % -MAX_X) + MAX_X - 1;
    }

    if (v_y > 0) {
        int y_travel = v_y * 100 + y;
        y = y_travel % MAX_Y;
    }
    else if (v_y < 0) {
        int y_travel = v_y * 100 - (MAX_Y - 1 - y);
        y = (y_travel % -MAX_Y) + MAX_Y - 1;
    }

    
    int half_x = (MAX_X - 1) / 2;
    int half_y = (MAX_Y - 1) / 2;

    if (x == half_x || y == half_y) return quadrants;
    
    if (x < half_x) {
        if (y < half_y) quadrants[0]++;
        else quadrants[2]++;  
    } else {
        if (y < half_y) quadrants[1]++;  
        else quadrants[3]++;  
    }
    
    return quadrants;
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    int res = 1;
    vector<int> quadrants(4, 0);

    while (getline(input, buf)) {
        vector<int> curr = readNumbers<int>(buf);
        quadrants = findPosition(curr[0], curr[1], curr[2], curr[3]);

    }

    for (auto q : quadrants) {
        res *= q;
    }
    
    cout << res << endl;
    input.close();
    return 0;
}