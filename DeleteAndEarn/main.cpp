#include <iostream>
#include "../myheader.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        auto cache = vector<int>(nums.back() + 1);
        cache[nums.front() - 1] = 0;
        int first = _count(nums.front(), 0, nums);
        cache[nums.front()] = _count(nums.front(), 0, nums) * nums.front();
        int loc = first;
        for (int i = nums.front()+1; i <= nums.back(); i++) {
            int count = _count(i, loc, nums);
            loc += count;
            cache[i] = max(count * i + cache[i - 2], cache[i-1]);
        }

        return cache[nums.back()];
    }
    int _count(int n, int loc, const vector<int> &nums) {
        int i = loc;
        for (; i < nums.size(); i++) {
            if (nums[i] != n) break;
        }

        return i - loc;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}