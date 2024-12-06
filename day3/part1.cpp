#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main () {

    regex pattern(R"(ul\(\d{1,3},\d{1,3}\))");
    ifstream input; 
    input.open("input.txt");
    string line;
    smatch match;
    int res = 0;

    while (getline(input, line, 'm')) {
        if (regex_search(line.cbegin(), line.cend(), match, pattern)) {
            int dig1 = 0;
            int dig2 = 0;
            int delim = line.find(",");
            for (int i = 3; i < line.size() - 1; i++) {
                if (line[i] == ')') break;
                if (i < delim) dig1 = dig1 * 10 + line[i] - '0';
                else if (i > delim) dig2 = dig2 * 10 + line[i] - '0';
            }
            res += dig1 * dig2;
        }
    }
    
    cout << res << endl;
    input.close();
    return 0;
}