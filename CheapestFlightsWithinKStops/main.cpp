#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        auto rules = vector<vector<vector<int>>>(n, vector<vector<int>>());
        for (const auto &f : flights) {
            rules[f[0]].push_back(vector<int>({f[1], f[2]}));
        }

        auto cache = vector<vector<int>>(n, vector<int>(K+2, INT_MAX));
        cache[src][0] = 0;

        for (int i = 1; i <= K+1; i++) {
            for (int j = 0; j < n; j++) {
                cache[j][i] = cache[j][i-1];
            }
            for (int j = 0; j < n; j++) {
                if (cache[j][i-1] == INT_MAX) continue;
                for (const auto &r : rules[j]) {
                    int next = r[0];
                    int cost = r[1];
                    cache[next][i] = min(cache[next][i], cache[j][i-1]+cost);
                }
            }
        }
        if (cache[dst][K+1] == INT_MAX)
            return -1;
        else
            return cache[dst][K+1];
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}