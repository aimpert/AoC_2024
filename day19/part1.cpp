#include <iostream>
#include <fstream>
#include <vector>
#include "../include/AoC.h"
#include <unordered_set>
#include <sstream>

using namespace std;

bool backtrack(unordered_set<string> towels, string curr, string combo, string word) {
    if (towels.find(combo) == towels.end()) return false;
    
    curr = curr + combo;
    if (curr.size() == word.size()) return true;
    combo.erase();
    for (int i = curr.size(); i < word.size(); i++) {
        combo.push_back(word[i]);
        if (backtrack(towels, curr, combo, word)) return true;
    }

    return false;
}

int main() {
    ifstream input("input.txt");
    string buf;
    unordered_set<string> towels;

    while (getline(input, buf)) {
        if (buf == "") break;
        stringstream ss(buf);
        string pattern;
        while (getline(ss, pattern, ',')) {
            pattern.erase(0, pattern.find_first_not_of(" \t"));
            pattern.erase(pattern.find_last_not_of(" \t") + 1);
            towels.insert(pattern);
        }
    }

    int res = 0;
    while (getline(input, buf)) {
        string start;
        for (int i = 0; i < buf.size(); i++) {
            start.push_back(buf[i]);
            if (backtrack(towels, "", start, buf)) {
                res++;
                break;
            }
        }
    }

    cout << res << endl;
    input.close();
    return 0;
}