#include <iostream>
#include "../myheader.h"

class Solution {
public:
    auto cache = unordered_map<int, int>();
    int combinationSum4(vector<int>& nums, int target) {
        if (cache.count(target) != 0) return cache[target];
        int ret = 0;
        for (auto &i : nums) {
            if (target - i < 0) continue;
            if (target - i == 0) {
                ret++;
                continue;
            }
            ret += combinationSum4(nums, target - i);
        }
        cache[target] = ret;
        return ret;
    }
};

int main() {
    vector<int> input({9});
    Solution slt;
    return slt.combinationSum4(input, 3);
}