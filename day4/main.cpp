#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int dfs(int r, int c, vector<string>& grid, int count, pair<int, int> dir) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != "XMAS"[count]) return 0;

    if (count == 3) return 1;

    return dfs(r + dir.first, c + dir.second, grid, count + 1, dir);
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

    int row = grid.size();
    int col = grid[0].size();
    vector<pair<int, int>> directions = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1},  // Up, Right, Down, Left
        {-1, 1}, {1, 1}, {1, -1}, {-1, -1} // Top-right, Bottom-right, Bottom-left, Top-left
    };

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (grid[r][c] == 'X') {
                for (auto dir : directions) {
                    res += dfs(r, c, grid, 0, dir);
                }
            }
        }
    }

    cout << res << endl;

    input.close();
    return 0;
}