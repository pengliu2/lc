#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        auto cache = vector<vector<int>>(N, vector<int>(N, 1));
        for (int i = 0; i < N; i++) {
            int h = min(i+1, N-i);
            for (int j = 0; j < N; j++) {
                int v = min(j+1, N-j);
                cache[i][j] = min(h, v);
            }
        }

        for (const auto &m : mines) {
            for (int i = 0; i < N; i++) {
                int origin = cache[i][m[1]];
                int v = 0;
                if (m[0]> i) {
                    v = m[0] - i;
                } else {
                    v = i- m[0];
                }
                cache[i][m[1]] = min(origin, v);
                origin = cache[m[0]][i];
                int h = 0;
                if (m[1]> i) {
                    h = m[1] - i;
                } else {
                    h = i- m[1];
                }
                cache[m[0]][i] = min(origin, h);
            }
        }
        int ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ret = max(ret, cache[i][j]);
            }
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}