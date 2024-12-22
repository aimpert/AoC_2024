#include <iostream>
#include <fstream>
#include <vector>
#include "../include/AoC.h"

using namespace std;

unsigned long prune(unsigned long secret) {
    return secret % 16777216;
}

unsigned long mix(unsigned long secret, unsigned long result) {
    return secret ^ result;
}

unsigned long generate(unsigned long secret) {

    for (int i = 0; i < 2000; i++) {
        secret = prune(mix(secret, secret << 6));
        secret = prune(mix(secret, secret >> 5));
        secret = prune(mix(secret, secret << 11));
    }

    return secret;

}

int main() {
    ifstream input("input.txt");
    string buf;
    unsigned long res = 0;
    
    while (getline(input, buf)) {
        unsigned long curr = readNumbers<unsigned long, unsigned long>(buf);
        res += generate(curr);
    }

    cout << res << endl;
    return 0;
}