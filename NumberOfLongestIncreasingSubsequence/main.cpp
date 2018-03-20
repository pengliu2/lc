#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. dont' forget to initialize inner vector<vector<int>>
 * 2. special case: [2,2,2,2,2]
 * if previous longest length is 1, initial value should be prev+1
 * 3. probably have to differentiate include current and exclude current
 * */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto cache = vector<vector<int>>(nums.size(), vector<int>(4, 0));
        cache[0] = vector<int>({1,1,0,0});
        for (int i = 1; i < nums.size(); i++) {
            if (cache[i-1][0] > cache[i-1][2]) {
                cache[i][2] = cache[i - 1][0];
                cache[i][3] = cache[i - 1][1];
            } else {
                cache[i][2] = cache[i - 1][2];
                cache[i][3] = cache[i - 1][3];
            }
            cache[i][0] = 1;
            cache[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                if (cache[j][0] + 1 > cache[i][0]) {
                    cache[i][0] = cache[j][0] + 1;
                    cache[i][1] = 1;
                } else if (cache[j][0] + 1 == cache[i][0]) {
                    cache[i][1] += 1;
                }
            }
        }
        if (cache[nums.size()-1][0] == cache[nums.size()-1][2])
            return cache[nums.size()-1][1] + cache[nums.size()-1][3];
        else if (cache[nums.size()-1][0] > cache[nums.size()-1][2])
            return cache[nums.size()-1][1];
        else
            return cache[nums.size()-1][3];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}