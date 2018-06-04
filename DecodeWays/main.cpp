#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * reminders
 * 1. when using first element as virtual result, all other results must be original element index + 1
 */

class Solution {
public:
    int numDecodings(string s) {
        vector<int> nums(s.size() + 1);
        if (s[0] == '0') return 0;
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i -1] == '2') {
                    nums[i+1] = nums[i-1];
                    continue;
                } else {
                    return 0;
                }
            }
            if (s[i-1] - '0' > 2) {
                nums[i+1] = nums[i];
            } else if (s[i-1] == '2') {
                if (s[i] - '0' < 7) {
                    nums[i+1] = nums[i] + nums[i-1];
                } else {
                    nums[i+1] = nums[i];
                }
            } else if (s[i-1] == '1') {
                nums[i+1] = nums[i] + nums[i-1];
            } else {
                /* s[i-1] == '0' */
                nums[i+1] = nums[i];
            }
        }
        return nums[s.size()];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}