#include <iostream>
#include <fstream>
#include <vector>
#include "../include/AoC.h"
#include <queue>

using namespace std;

struct Point
{
    int x;
    int y;
};
 
struct queueNode
{
    Point pt; 
    int dist;  
};

int bfs(vector<string>& grid, Point src, Point dest) {
    int maxRow = grid.size();
    int maxCol = grid[0].size();
    vector<vector<bool>> visited(maxRow, vector<bool>(maxCol, false));
    
    visited[src.x][src.y] = true;

    queue<queueNode> q;

    queueNode s = {src, 0};
    q.push(s);
    
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    while (!q.empty()) {
        queueNode curr = q.front();
        Point pt = curr.pt;

        if (pt.x == dest.x && pt.y == dest.y) return curr.dist;
        
        q.pop();

        for (int i = 0; i < 4; i++) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if ((row >= 0) && (row < maxRow) && (col >= 0) && (col < maxCol) && !visited[row][col] && grid[row][col] != '#') {
                visited[row][col] = true;
                queueNode adjCell = {{row, col}, curr.dist + 1};
                q.push(adjCell);
            }

        }
    }
    
    return -1;
}

int main() {
    ifstream input("input.txt");
    string buf;
    vector<string> grid(71, string(71, '.'));

    int i = 0;
    while (getline(input, buf)) {
        if (i == 1024) break;
        vector<int> coords = readNumbers<int>(buf);
        grid[coords[1]][coords[0]] = '#';
        i++;
    }

    Point source = {0, 0};
    Point dest = {(int)grid.size() - 1, (int)grid[0].size() - 1};

    vector<int> coords;
    while (getline(input, buf)) {
        coords = readNumbers<int>(buf);
        grid[coords[1]][coords[0]] = '#';
        if (bfs(grid, source, dest) == -1) break;
    } 

    cout << coords[0] << "," << coords[1] << endl;

    input.close();
    return 0;
}