#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> cache(n+1);
        for(int i = 1; i <= n; i++) {
            cache[i] = vector<int>(n+1, -1);
        }
        return dfs(cache, 1, n);
    }

    int dfs(vector<vector<int>> &cache, int start, int stop) {
        if (start >= stop) return 0;
        if (cache[start][stop] >= 0)
            return cache[start][stop];
        int maxp = INT_MAX;
        for (int i = (start + stop)/2; i <= stop; i++) {
            int p = i + max(dfs(cache, start, i-1), dfs(cache, i+1, stop));
            if (p < maxp)
                maxp = p;
        }
        cache[start][stop] = maxp;
        return maxp;
    }
};

int main() {
    Solution slt;
    return slt.getMoneyAmount(2);
}