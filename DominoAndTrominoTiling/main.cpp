#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int numTilings(int N) {
        auto cache = vector<vector<long long>>(N+1, vector<long long>(3L, 0L));
        int md=1e9 + 7;
        cache[0] = vector<long long>({1L, 0L, 0L});
        cache[1] = vector<long long>({1L, 0L, 0L});
        for (int i = 2; i <= N; i++) {
            long both;
            long up;
            long down;
            both = cache[i-2][0] + cache[i-1][0] + cache[i-1][1] + cache[i-1][2];
            up = cache[i-2][0] + cache[i-1][2];
            down = cache[i-2][0] + cache[i-1][1];
            cache[i][0] = both;
            cache[i][1] = up;
            cache[i][2] = down;

            //if (min(min(cache[i][0], cache[i][1]), cache[i][2]) > md) {
                cache[i][0] %= md;
                cache[i][1] %= md;
                cache[i][2] %= md;
            //}
        }
        return cache[N][0]%md;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}