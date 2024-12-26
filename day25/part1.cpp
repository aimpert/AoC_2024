#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int tryLock(const vector<int>& key, const vector<int>& lock) {
    for (int i = 0; i < key.size(); i++) {
        if ((key[i] + 1) + (lock[i] + 1) > 7) return 0;
    }
    return 1;
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    
    bool isLock = true;
    vector<vector<int>> locks;
    locks.push_back({-1, -1, -1, -1, -1});
    vector<vector<int>> keys;

    while(getline(input, buf)) {
        if (buf == "") {
            if (getline(input, buf)) {
                isLock = buf[0] == '#';
                auto& target = isLock ? locks : keys;
                target.push_back({-1, -1, -1, -1, -1});
            }
        }
        for (int i = 0; i < buf.size(); i++) {
            auto& target = isLock ? locks : keys;
            if (buf[i] == '#') target.back()[i]++;
        }
  
    }

    int res = 0;

    for (int key = 0; key < keys.size(); key++) {
        for (int lock = 0; lock < locks.size(); lock++) {
            res += tryLock(keys[key], locks[lock]);
        }
    }

    cout << res << endl;

    input.close();
    return 0;
}