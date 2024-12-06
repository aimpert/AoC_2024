#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    int res = 0;

    map<int, set<int>> adj;
    auto sorter = [&](int a, int b){return adj[b].count(a) > 0;};

    while (getline(input, buf)) {
        if (buf.empty()) break;
        int dig1 = 0;
        int dig2 = 0;
        for (int i = 0; i < buf.size(); i++) {
            if (buf[i] == '|') {
                dig1 = dig2;
                dig2 = 0;
                continue;
            }
            dig2 = dig2 * 10 + buf[i] - '0';
        }
        adj[dig2].insert(dig1);
    }


    while (getline(input, buf)) {
        int dig = 0;
        vector<int> updates;
        for (int i = 0; i < buf.size(); i++) {
            if (buf[i] == ',') {
                updates.push_back(dig);
                dig = 0;
                continue;
            }
            else if (i == buf.size() - 1) {
                dig = dig * 10 + buf[i] - '0';
                updates.push_back(dig);
                dig = 0;
                break;
            }
            dig = dig * 10 + buf[i] - '0';
        }

        if(is_sorted(updates.begin(), updates.end(), sorter)) res += updates[updates.size()/2];

    }
    
    cout << res << endl;

    input.close();
    return 0;
}