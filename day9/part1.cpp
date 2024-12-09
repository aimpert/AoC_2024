#include <iostream>
#include <fstream>
#include "../include/AoC.h"

using namespace std;


int main () {

    ifstream input; 
    input.open("input.txt");
    char c;
    vector<int> arr;
    int id = 0;
    bool isFreeSpace = false;
    
    while (input.get(c)) {
        int temp = c - '0';
        if (isFreeSpace) {
            for (int i = 0; i < temp; i++) {
                arr.push_back(-1);
            }
        }
        else {
            for (int i = 0; i < temp; i++) {
                arr.push_back(id);
            }
            id++;
        }
        isFreeSpace = !isFreeSpace; 
    }

    size_t j = arr.size() - 1;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == -1) {
                while (j > i && arr[j] == -1) {
                j--;
            }
            if (j > i) {
                arr[i] = arr[j];
                arr[j] = -1;
            }
        }
    }

    unsigned long long res = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == -1) break;
        res += i * arr[i];
    }

    cout << res << endl;

    input.close();
    return 0;
}