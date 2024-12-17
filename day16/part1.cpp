#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct state {
    int row, col, score;
    pair<int, int> dir;
    
    bool operator>(const state& other) const {
        return score > other.score;
    }
};

int bfs(vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    
    priority_queue<state, vector<state>, greater<state>> pq;
    
    vector<vector<vector<bool>>> visited(
        rows, 
        vector<vector<bool>>(cols, vector<bool>(4, false))
    );
    
    for (int i = 0; i < 4; i++) {
        pq.push({139, 1, 0, directions[i]});
    }
    
    while (!pq.empty()) {
        auto [row, col, score, currDir] = pq.top();
        pq.pop();
        
        if (grid[row][col] == '#') continue;
        
        if (grid[row][col] == 'E') return score;
        
        int dirIndex = -1;
        for (int i = 0; i < directions.size(); i++) {
            if (directions[i] == currDir) {
                dirIndex = i;
                break;
            }
        }
        if (visited[row][col][dirIndex]) continue;
        visited[row][col][dirIndex] = true;
        
        for (const auto& newDir : directions) {
            int newScore = score + (newDir != currDir ? 1001 : 1);
            
            pq.push({row + newDir.first, col + newDir.second, newScore, newDir});
        }
    }
    
    return INT_MAX;
}

int main() {
    ifstream input("input.txt");
    vector<string> grid;
    string buf;
    
    while (getline(input, buf)) {
        grid.push_back(buf);
    }
    
    int res = bfs(grid);
    
    cout << res << endl;
    
    input.close();
    return 0;
}