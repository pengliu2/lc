#include <iostream>
#include "../myheader.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return nums;

        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> cache = unordered_map<int, vector<int>>();
        cache[0] = vector<int>{nums[0]};
        auto &ret = cache[0];
        for (int i = 1; i < nums.size(); i++) {
            for (auto &c : cache) {
                if ((i % nums[c.first] == 0) && (c.second[c.second.size()] % i == 0)) {
                    c.second.emplace_back(i);
                    if (c.second.size() > ret.size())
                        ret = c.second;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution slt;
    vector<int> i{2000000000};
    slt.largestDivisibleSubset(i);
    return 0;
}