#include <iostream>
#include <fstream>
#include "../include/AoC.h"
#include <unordered_map>
#include <unordered_set>
#include <iterator>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};

int main () {

    ifstream input; 
    input.open("input.txt");
    char c;
    unordered_map<char, vector<pair<int, int>>> att;
    int max_row = 0;
    int col = 0;
    int max_col = 0;

    while (input.get(c)) {
        if (c == '\n') {           
            max_row++;
            max_col = col; // need this for later
            col = 0;
            continue;
        }
        if (isalnum(c)) att[c].push_back({max_row, col});
        col++;
    }


    unordered_set<pair<int, int>, pair_hash> antinodes;
    int count = 0;
    for (const auto& [key, positions] : att) {
        for (size_t i = 0; i < positions.size(); i++) {
            for (size_t j = 0; j < positions.size(); j++) {
                if (j == i) continue;
                const auto& [row1, col1] = positions[i]; 
                const auto& [row2, col2] = positions[j];
                antinodes.insert({row1, col1});
                pair<int, int> distance = {(row2 - row1), (col2 - col1)};
                pair<int, int> antinode = {row2 + distance.first, col2 + distance.second};
                while (antinode.first >= 0 && antinode.first < max_row && antinode.second >= 0 && antinode.second < max_col) {
                        antinodes.insert(antinode);
                        antinode = {antinode.first + distance.first, antinode.second + distance.second};

                    }
                }
            }
        }

    cout << antinodes.size() + count << endl;
    input.close();
    return 0;
}