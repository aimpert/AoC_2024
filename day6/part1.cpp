#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int traverse(int row, int col, vector<string>& grid, vector<pair<int, int>>& dir, int i) {
    if (row + dir[i].first < 0 || row + dir[i].first >= grid.size() || col + dir[i].second < 0 || col + dir[i].second >= grid[0].size()) return 0;
    
    if (grid[row][col] == 'X') return traverse(row + dir[i].first, col + dir[i].second, grid, dir, i);

    if (grid[row + dir[i].first][col + dir[i].second] == '#') {
        i = (i + 1) % 4;
    }
    
    grid[row][col] ='X';

    return 1 + traverse(row + dir[i].first, col + dir[i].second, grid, dir, i);
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    int res = 0;
    vector<string> grid;
    pair<int, int> startPos;
    while (getline(input, buf)) {
        grid.push_back(buf);
        int col = buf.find("^");
        if (col != std::string::npos) { 
            startPos = {grid.size()-1, col};
        }
    }

    vector<pair<int, int>> directions = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}  // Up, Right, Down, Left
    };

    res = 1 + traverse(startPos.first, startPos.second, grid, directions, 0);     
    
    cout << res << endl;

    input.close();
    return 0;
}