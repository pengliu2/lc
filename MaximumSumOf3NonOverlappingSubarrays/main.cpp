#include <iostream>
#include <vector>

using namespace std;

/*
 * reminder:
 * 1. i to i+k-1 is k elements
 * 2. calculate moving window sum: sum must be declared out of the loop
 *
 */

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> cache(nums.size(), 0);
        vector<vector<int>> cache1(nums.size(), vector<int>(2, 0));
        vector<vector<int>> cache2(nums.size(), vector<int>(3, 0));
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k-1) {
                sum += nums[i];
            } else if (i == k-1) {
                sum += nums[i];
                cache[i - k + 1] = sum;
            } else {
                sum = sum + nums[i] - nums[i-k];
                cache[i - k + 1] = sum;
            }

        }

        cache1[0][0] = 0;
        cache1[0][1] = cache[0];
        for (int i = 1; i < nums.size() - k + 1; i++) {
            if (cache[i] > cache1[i-1][1]) {
                cache1[i][0] = i;
                cache1[i][1] = cache[i];
            } else {
                cache1[i][0] = cache1[i-1][0];
                cache1[i][1] = cache1[i-1][1];
            }
        }

        cache2[k][0] = 0;
        cache2[k][1] = k;
        cache2[k][2] = cache[0] + cache[k];
        for (int i = k+1; i < nums.size() - k + 1; i++) {
            if (cache[i] + cache1[i-k][1] > cache2[i-1][2]) {
                cache2[i][0] = cache1[i-k][0];
                cache2[i][1] = i;
                cache2[i][2] = cache[i] + cache1[i-k][1];
            } else {
                cache2[i][0] = cache2[i-1][0];
                cache2[i][1] = cache2[i-1][1];
                cache2[i][2] = cache2[i-1][2];
            }
        }

        vector<int> ans = vector<int>{0, k, k*2};
        sum = cache[0] + cache[k] + cache[k*2];
        for (int i = k*2 + 1; i < nums.size() - k + 1; i++) {
            if (cache[i] + cache2[i-k][2] > sum) {
                sum = cache[i] + cache2[i-k][2];
                ans[2] = i;
                ans[0] = cache2[i-k][0];
                ans[1] = cache2[i-k][1];
            }
        }

        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}