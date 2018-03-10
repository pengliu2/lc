#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int t_size = t.size();
        int s_size = s.size();
        if (s_size < t_size) return 0;

        auto cache = vector<vector<int>>(t_size, vector<int>(s_size+1, 0));
        cache.push_back(vector<int>(s_size+1, 1));
        for (int i = t_size - 1; i >= 0; i--) {
            for (int j = s_size - 1; j >= 0; j--) {
                cache[i][j] = cache[i][j+1];
                if (s[j] == t[i]) {
                    cache[i][j] += cache[i+1][j+1];
                }
            }
        }

        return cache[0][0];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}