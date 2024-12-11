#include <iostream>
#include <fstream>
#include <math.h>
#include "../include/AoC.h"


using namespace std;

int long countDigits(unsigned long number) {
    if (number < 10) return 1; // skip the division computation we know it's false
    int i = 0;
    while (number > 0) {
        number /= 10;
        i++;
    }
    return i;
}

pair<int, int> splitStone(unsigned long number, int digits) {
        pair<int, int> res;
        int divisor = pow(10, digits / 2);
        res.first = number / divisor;
        int rightHalf = number % divisor;
        res.second = rightHalf;
        return res;
}

void blink(vector<unsigned long>& stones) {
    int size = stones.size();
    for (int i = 0; i < size; i++) {
        int digs = countDigits(stones[i]);
        if (stones[i] == 0) stones[i] = 1;
        else if (digs % 2 == 0) {
            pair<int, int> split = splitStone(stones[i], digs);
            stones[i] = split.first;
            stones.push_back(split.second);
        }
        else stones[i] = stones[i] * 2024;

    }

    return;
}

int main () {

    ifstream input; 
    input.open("input.txt");
    string buf;
    vector<unsigned long> stones;
    
    while(getline(input, buf)) {
        stones = readNumbers<unsigned long>(buf);
    }

    for (int i = 0; i < 25; i++) {
        blink(stones);
    }

    cout << stones.size() << endl;

    input.close();
    return 0;
}