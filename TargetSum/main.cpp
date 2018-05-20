#include <iostream>
#include "../myheader.h"

/*
 * reminder:
 * 1. helper needs to return a value, which is more easily get children's returns
 * 2. the cache must be able to cover all possible -sum(nums) to sum(nums)
 * 3. reversed DFS like solutionII: better to check target reachability or we have to keep a larger cache
 */

class SolutionII {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        cache = vector<vector<int>>(nums.size(), vector<int>(sum*2+2, -1));
        return helper(S, nums, 0);
    }

    int helper(int S, vector<int>& nums, int index) {
        if (S > sum || S + sum < 0) return 0;
        if (index == nums.size()) {
            if (S == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (cache[index][S + sum + 1] != -1) {
            //cout << "c:" << index << "," << S << "at " << S+sum+1 << ":" << cache[index][S + sum + 1] << endl;
            return cache[index][S + sum + 1];
        }

        int minus = helper(S - nums[index], nums, index+1);
        int plus = helper(S + nums[index], nums, index+1);
        cache[index][S + sum + 1] = minus + plus;
        return minus + plus;
    }
private:
    vector<vector<int>> cache;
    int sum;
};

class SolutionI {
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