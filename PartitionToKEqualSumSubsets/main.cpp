#include <iostream>
#include "../myheader.h"

/* reminder:
 * 1. don't forget to specify template argument like int in set<int>
 * 2. << operator is executed before + !!!
 * 3. == and != has higher priority than &!!!
 * 4. sort the array might accelerate it???
 * */

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;
        int sum = total / k;
        if (*max_element(nums.begin(), nums.end()) > sum) return false;

        auto cache1 = vector<vector<int>>(sum + 1, vector<int>());
        cache1[0].push_back(0);

        int full = (1 << nums.size()) - 1;
        auto cache3 = vector<int>();
        cache3.push_back(0);

        for (int i = 0; i < nums.size(); i++) {
            for (const int c : cache1[sum - nums[i]]) {
                int newcomb = c | (0x01L << i);
                for (int p = cache3.size() - 1; p >= 0; p--) {
                    if ((newcomb & cache3[p]) != 0) continue;
                    if ((newcomb | cache3[p]) == full ) return true;
                    cache3.push_back(newcomb | cache3[p]);
                }
            }
            for (int j = sum - nums[i] - 1; j >= 0; j--) {
                for (const int c : cache1[j]) {
                    cache1[nums[i]+j].push_back(c | (0x01L << i));
                }
            }
        }

        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}