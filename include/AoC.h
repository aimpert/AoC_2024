#include <string>
#include <vector>

using namespace std;

template <typename T, typename Container = std::vector<T>>
auto readNumbers(const string& buf) {
    static_assert(std::is_integral_v<T>, "T must be an integral type");
    vector<T> numbers;

    T dig = 0;
    bool collect = false;
    bool negative = false;
    for (char c : buf) {
        if (isdigit(c)) {
            dig = dig * 10 + c - '0';
            collect = true;
            
        }
        else if (c == '-') negative = true;
        else if (collect) {
            if (negative) {
                dig = dig * -1;
                negative = false;
            }
            numbers.push_back(dig);
            dig = 0;
            collect = false;
        }

    }

    if (collect) {
        if (negative) {
            dig = dig * -1;
            negative = false;
        }
        numbers.push_back(dig); // just in case
    }
    if constexpr (std::is_same_v<Container, T>) {
        return numbers.empty() ? static_cast<T>(0) : numbers.front();
    } else {
        return Container(numbers.begin(), numbers.end());
    }
}

vector<int> readDigits(const string& buf) {
    vector<int> res;
    for (char c : buf) {
        if (isdigit(c)) {
            res.push_back(c - '0');   
        }
    }
    return res;
}