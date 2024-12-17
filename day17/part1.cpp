#include <iostream>
#include <fstream>
#include <vector>
#include "../include/AoC.h"

using namespace std;

#define A 0
#define B 1
#define C 2

int directive(vector<int>& reg, const vector<int>& program, int& p, vector<int>& out) {
        int opcode  = program[p++];
        int literal = program[p++];

        int combo = literal;
        switch (literal) {
            case 4: combo = reg[A]; break;
            case 5: combo = reg[B]; break;
            case 6: combo = reg[C]; break;
        }

        switch (opcode) {
            case 0: reg[A] = reg[A] / (1 << combo); break;
            case 1: reg[B] = reg[B] ^ literal; break;
            case 2: reg[B] = combo % 8; break;
            case 3: if (reg[A] != 0) p = literal; break;
            case 4: reg[B] = reg[B] ^ reg[C]; break;
            case 5: out.push_back(combo % 8); break;
            case 6: reg[B] = reg[A] / (1 << combo); break;
            case 7: reg[C] = reg[A] / (1 << combo); break;
        }

    return p;
}

int main() {
    ifstream input("input.txt");
    vector<int> reg;
    vector<int> program;
    string buf;

    while (getline(input, buf)) {
        if (buf == "") {
            if (getline(input, buf)) {
                program = readNumbers<int>(buf);
            }
            break;
        }
        reg.push_back(readNumbers<int, int>(buf));
    }

    vector<int> res;

    int p = 0;
    while (p <= program.size()) {
        directive(reg, program, p, res);
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i];
        if (i != res.size() - 1) cout << ",";
        else cout << endl;
    }
    
    input.close();
    return 0;
}