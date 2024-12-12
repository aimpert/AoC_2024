#include <iostream>
#include <fstream>
#include "../include/AoC.h"


using namespace std;

int dfs(int row, int col, vector<string>& grid, char target, int& perim) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
        perim++;
        return 0;
    }
    
    if (grid[row][col] == target + 32) return 0;
    if (grid[row][col] != target) {
        perim++;
        return 0;
    }

    grid[row][col] = target + 32;

    return 1 + dfs(row - 1, col, grid, target, perim) 
            + dfs(row, col + 1, grid, target, perim)
            + dfs(row + 1, col, grid, target, perim)
            + dfs(row, col - 1, grid, target, perim);
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    vector<string> grid;
    int res = 0;

    while (getline(input, buf)) {
        grid.push_back(buf);
    }

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
            // I don't know why I thought of doing it this way, check to see if current character is lowercase
            // (and therefore visited)
            if (grid[row][col] >= 97 && grid[row][col] <= 122) continue;
            int perim = 0;
            res += dfs(row, col, grid, grid[row][col], perim) * perim;
        }
    }
    

    cout << res << endl;
    input.close();
    return 0;
}