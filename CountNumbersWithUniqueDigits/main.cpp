#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int ret = 10;
        int prev = 9;
        int available = 9;
        for (int i = 2; (i <= n) && (available > 0); i++) {
            prev *= available;
            available--;
            ret += prev;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}