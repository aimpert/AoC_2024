#include <iostream>
#include <fstream>
#include "../include/AoC.h"

using namespace std;

#define MAX_X 11
#define MAX_Y 7

vector<int> findPosition(int x, int y, int v_x, int v_y) {
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

    vector<int> res = {x, y};

    return res;
}

int main () {

    ifstream input; 
    input.open("small_input.txt");
    string buf;
    int res = 0;
    int i = 0;
    vector<int> curr;
    vector<vector<int>> positions;
    const int rows = 7;
    const int cols = 11;
    std::vector<std::vector<char>> grid(rows, std::vector<char>(cols, '.'));
    while (getline(input, buf)) {
        curr = readNumbers<int>(buf);
        positions.push_back(findPosition(curr[0], curr[1], curr[2], curr[3]));

    }

    for (auto p : positions) {
        if (grid[p[1]][p[0]] == '1') {
            grid[p[1]][p[0]] = '2';
            continue;
        }
        grid[p[1]][p[0]] = '1';
    }

    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
    
    cout << res << endl;
    input.close();
    return 0;
}