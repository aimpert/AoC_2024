#include <iostream>
#include <fstream>
#include "../include/AoC.h"
#include <unordered_map>

using namespace std;

void traversal(vector<string>& grid, pair<int, int> dir, int row, int col, pair<int, int>& robot) {
    if (grid[row + dir.first][col + dir.second] == '#') return;

    if (grid[row + dir.first][col + dir.second] == 'O') {
        traversal(grid, dir, row + dir.first, col + dir.second, robot);
    }

    if (grid[row + dir.first][col + dir.second] == '.') {
        grid[row + dir.first][col + dir.second] = grid[row][col];
        grid[row][col] = '.';
    }

    // update the new robot position since its called outside of the recursion
    if(grid[row + dir.first][col + dir.second] == '@') robot = {row + dir.first, col + dir.second};
    return;
}

int main () {

    ifstream input; 
    input.open("input.txt");
    vector<string> grid;

    unordered_map<char, pair<int, int>> direction = {
        {'^', {-1, 0}},  // Up
        {'v', {1, 0}},   // Down
        {'<', {0, -1}},  // Left
        {'>', {0, 1}}    // Right
    };

    char c;
    string temp;
    int row = 0;
    int col = 0;
    pair<int, int> robot;

    // read char by char so we can find the robot's location in one pass
    while (input.get(c)) {
        if (c == '\n') {
            if (temp == "") break;           
            col = 0;
            row++;
            grid.push_back(temp);
            temp.clear();
            continue;
        }
        if (c == '@') {
            robot = {row, col};
        }
        temp.push_back(c);
        col++;
    }

    while (input.get(c)) { // the robot's moves
        traversal(grid, direction[c], robot.first, robot.second, robot);
    }

    int res = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'O') res += (100 * i) + j;
        }
    }

    cout << res << endl;
    input.close();
    return 0;
}