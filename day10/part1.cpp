#include <iostream>
#include <fstream>
#include "../include/AoC.h"
#include <set>

using namespace std;

void traverse(int row, int col, vector<vector<int>>& grid, int curr, set<pair<int, int>>& nines) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != curr) return;

    if (curr == 9) {
        nines.insert({row, col});
        return;
    }

    int temp = grid[row][col];
    grid[row][col] = -1;

    traverse(row - 1, col, grid, curr + 1, nines);
    traverse(row, col + 1, grid, curr + 1, nines);
    traverse(row + 1, col, grid, curr + 1, nines);
    traverse(row, col - 1, grid, curr + 1, nines);

    grid[row][col] = temp;

    return;
}

int main () {

    ifstream input; 
    input.open("input.txt");
    vector<vector<int>> grid;
    int res = 0;
    char c;
    vector<pair<int, int>> trailheads;
    int row = 0;
    int col = 0;

    grid.push_back(vector<int>());
    while (input.get(c)) {
        if (c == '\n') {           
            col = 0;
            row++;
            grid.push_back(vector<int>());
            continue;
        }
        int digit = c - '0';
        grid[row].push_back(digit);
        if (digit == 0) trailheads.push_back({row, col});
        col++;
    }


    for (auto t : trailheads) {
        set<pair<int, int>> nines;
        traverse(t.first, t.second, grid, 0, nines);
        res += nines.size();
    }
    
    
    cout << res << endl;

    input.close();
    return 0;
}