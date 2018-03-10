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

        sort(nums.begin(), nums.end(), [](const int a, const int b){return a>b;});
        auto cache = set<int>();
        cache.emplace(0);
        for (int &i : nums) {
            auto newcache = set<int>();
            for (auto &j : cache) {
                int r = j + i;
                if (r * 2 == total) return true;
                if (r * 2 > total) continue;
                newcache.emplace(r);
            }
            cache.insert(newcache.begin(), newcache.end());
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}