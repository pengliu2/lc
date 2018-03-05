#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> cache = vector<vector<int>>(n+1);
        cache[0] = vector<int>{0, 0, 0};
        cache[1] = vector<int>{0, 0, 0};
        for (int i = 2; i < n+1; i++) {
            int maxp = (i-1)*i/2;
            int maxf = i;
            int opt = 0;
            for (int j = 1; j < i-1; j++) {
                int left_p = cache[j][2];
                int right_p = cache[i-j-1][1]*(j+2) + cache[i-j-1][2];
                int p;
                int fault;
                if (left_p == right_p) {
                    p = j + left_p;
                    fault = cache[j][1];
                } else {
                    p = j + right_p;
                    fault = cache[i-j-1][1];
                }
                if (p < maxp) {
                    maxp = p;
                    opt = j;
                    maxf = fault;
                }
            }
            cache[i] = vector<int>{opt, maxf, maxp};
        }
        return cache[n][2]+cache[n][1];
    }
};

int main() {
    Solution slt;
    return slt.getMoneyAmount(2);
}