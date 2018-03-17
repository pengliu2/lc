#include <iostream>
#include "../myheader.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        if (k == 0) {
            int total_zero = 0;
            for (const auto &n : nums) {
                if (n == 0)
                    total_zero++;
                else if (n > 0)
                    total_zero = 0;

                if (total_zero > 1) return true;

            }
            return false;
        }


        k = abs(k);
        auto cache = unordered_map<int, int>();
        int sum = 0;
        for (const auto &n : nums) {
            sum = (sum + n) % k;
            if (sum == 0 && n != k) return true;
            if (cache[sum%k] > 0) return true;
            cache[sum%k] = 1;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}