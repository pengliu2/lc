#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

/*
 * reminders
 * 1. answer should be element values, not indices
 * 2. dont forget to change b and e in each branch
 * 3. iterate b and e until we have different values for them, or there will be duplicate in result
 */

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            helper(ans, nums, i);
        }
        return ans;
    }
private:
    void helper(vector<vector<int>>& ans, vector<int>& nums, int index) {
        int b = index + 1;
        int e = nums.size() - 1;
        while (b < e) {
            int sum = nums[b] + nums[e] + nums[index];
            if (sum > 0) {
                do {
                    e--;
                } while (e > 0 && (nums[e] == nums[e+1]));
            } else if (sum < 0) {
                do {
                    b++;
                } while (b < nums.size() - 1 && (nums[b] == nums[b-1]));
            } else {
                ans.push_back(vector<int>{nums[index], nums[b], nums[e]});
                do {
                    b++;
                } while (b < nums.size() - 1 && (nums[b] == nums[b-1]));
                do {
                    e--;
                } while (e > 0 && (nums[e] == nums[e+1]));
            }
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}