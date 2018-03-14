#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> cache = vector<unordered_map<int, int>>(nums.size() + 1);
        int i = 1;
        cache[0] = unordered_map<int, int>();
        cache[0][0] = 1;
        for (const int n : nums) {
            auto &v = cache[i];
            auto v0 = cache[i-1];
            for (const auto u : v0) {
                int plus = u.first + n;
                int minus = u.first - n;
                v[plus] += u.second;
                v[minus] += u.second;
            }
            i++;
        }
        return cache[nums.size()][S];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}