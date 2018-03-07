#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int integerBreak(int n) {
        int threes = 1;
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        while ( n > 4) {
            n = n-3;
            threes *= 3;
        }
        return threes * n;
    }
};

int main() {
    Solution slt;
    return slt.integerBreak(10);
}