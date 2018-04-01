#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* reminder:
 * 1. there might be same value integers in array
 * 2. solutionI doesn't work. still needs union find: to mark known num[i]+1's position in array as num[i]'s parent
 * 3. in SolutionIII: adding parent's sequence length is find:
 *    - when it's counted, it's all numbers larger than it that form a consecutive sequence
 *    - when it's not counted, it's 1
 */
class SolutionIII {
public:
    int longestConsecutive(vector<int> &nums) {
        map<int, int> cache;
        vector<int> parent(nums.size(), -1);
        vector<int> results(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++) {
            cache[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (cache.count(nums[i] + 1)) {
                parent[i] = cache[nums[i] + 1];
            }
        }
        int ret = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int cursor = i;
            while (parent[cursor] != -1) {
                int prev = cursor;
                cursor = parent[cursor];
                parent[prev] = -1;
                results[i] += results[cursor];
            }
            ret = max(ret, results[i]);
        }

        return ret;
    }
};

class SolutionI {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> cache;
        for (int i = 0; i < nums.size(); i++) {
            if (cache.count(nums[i+1])) {
                cache[nums[i]] = cache[nums[i+1]] + 1;
            } else {
                cache[nums[i]] = 1;
            }
        }
        int ret = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (cache.count(nums[i+1])) {
                cache[nums[i]] += cache[nums[i+1]];
            }
            ret = max(ret, cache[nums[i]]);
        }
        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}