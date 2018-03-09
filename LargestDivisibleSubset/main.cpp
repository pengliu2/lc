#include <iostream>
#include "../myheader.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return nums;
        sort(nums.begin(), nums.end());

        auto cache = vector<vector<int>>();
        cache.emplace_back(vector<int>({nums[0]}));

        int maxret = 1;
        int maxindex = 0;

        for (int i = 1; i < nums.size(); i++) {
            int maxl = 1;
            int index = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if ((cache[j].size() + 1) > maxl) {
                        maxl = cache[j].size() + 1;
                        index = j;
                    }
                }
            }
            if (index != i) {
                cache.emplace_back(cache[index]);
                cache[i].push_back(nums[i]);
            } else {
                cache.emplace_back(vector<int>({nums[i]}));
            }

            if (cache[i].size() > maxret) {
                maxret = cache[i].size();
                maxindex = i;
            }
        }

        return cache[maxindex];
    }
};

int main() {
    Solution slt;
    vector<int> i{1, 2, 4, 8, 16};
    slt.largestDivisibleSubset(i);
    return 0;
}