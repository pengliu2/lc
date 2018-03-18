#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;

        long long mod = 1000000007;
        auto cache = vector<vector<vector<long long>>>(N+1, vector<vector<long long>>(m+2, vector<long long>(n+2, 0L)));
        i++;
        j++;
        cache[0][i][j] = 1;
        for (int k = 1; k < N; k++) {
            for (int l = 1; l <= m; l++) {
                for (int h = 1; h <= n; h++) {
                    cache[k][l][h] = cache[k-1][l+1][h] + cache[k-1][l-1][h] + cache[k-1][l][h+1] + cache[k-1][l][h-1];
                    cache[k][l][h] = cache[k][l][h] % mod;
                }
            }
        }
        long long ret = 0;
        for(int h = 0; h < N; h++) {
            for (int k = 1; k <= m; k++) {
                ret += (cache[h][k][1] + cache[h][k][n]);
            }

            for (int k = 1; k <= n; k++) {
                ret += (cache[h][1][k] + cache[h][m][k]);
            }
            ret = ret % mod;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}