#include <iostream>
#include "../myheader.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto size = nums.size();
        int total = 0;
        for (int i : nums) {
            total += i;
        }
        if (total % 2 != 0) return false;

        vector<int> dp = vector<int>(total + 1, 0);
        dp[0] = 1;
        for (const int num : nums) {
            for (int i = total; i >= 0; i--) {
                if (dp[i]) dp[i+num] = 1;
            }
            if (dp[total/2]) return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}